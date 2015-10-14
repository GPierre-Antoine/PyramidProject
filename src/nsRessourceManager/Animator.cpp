//
// Created by Pierre-Antoine on 29/06/2015.
//

#include <SFML/Graphics.hpp>
#include "Animator.h"

using namespace nsGameConstants;

#define ANIM nsRessourceManager::Animator
#define PANIM nsRessourceManager::PlayerAnimator

///////////////////////////////////////        ANIMATOR         ///////////////////////////////////////////////

//Definition
sf::RenderWindow* ANIM::window;

void ANIM::setWindow(sf::RenderWindow & window) noexcept
{
    ANIM::window = &window;
}

void ANIM::setPosition(UInt16 x, UInt16 y)
{
    position.x = (float) x;
    position.y = (float) y;
}

bool ANIM::isMoving() const noexcept
{
    return moving;
}

void ANIM::setMoving(bool moving) noexcept
{
    this->moving = moving;
    //todo : if isnt moving change loop to idle
}

////////////////////////////////////        PLAYERANIMATOR         ////////////////////////////////////////////

PANIM::PlayerAnimator(KPair_t & character /*= BASIC*/)
        : direction(PLAYER_DOWN), loopsCounter(0)
{
    ANIM::setMoving(false);
    //S'occupe de charger la texture de notre joueur (ex guerrier)
    RessourceManager::loadCharacterTextures(character, nsGameConstants::CHARACTER_SPRITE_SIZE);

    //On sauvegarde cette texture (pointeur)
    textures = &RessourceManager::getTexture(character.first);

    //On charge la loop
    loopList = new nsUtility::ListeCircu<byte_t>(CHARACTER_RIGHT_LEG_FORWARD);
    nsUtility::ListeCircu<byte_t>* elemCourant = loopList;
    elemCourant = insertValue(elemCourant, CHARACTER_RIGHT_LEG_MID);
    elemCourant = insertValue(elemCourant, CHARACTER_LEFT_LEG_MID);
    elemCourant = insertValue(elemCourant, CHARACTER_LEFT_LEG_FORWARD);
    elemCourant = insertValue(elemCourant, CHARACTER_LEFT_LEG_MID);
    insertValue(elemCourant, CHARACTER_RIGHT_LEG_MID);
}

PANIM::PlayerAnimator(const PlayerAnimator & animator)
        : direction(animator.direction), loopsCounter(animator.loopsCounter)
{
    ANIM::setMoving(animator.isMoving());
}

void PANIM::render() noexcept
{
    sf::Sprite legSprite;


    if (this->isMoving())
    {
        if (loopsCounter > PLAYER_MID_STEPPING_FRAMES + PLAYER_FORWARD_STEPPING_FRAMES)
        {
            loopList = loopList->getSuivant();
            loopsCounter = 0;
        }
        else if (loopsCounter == PLAYER_MID_STEPPING_FRAMES)
            loopList = loopList->getSuivant();

        legSprite.setTexture(textures->at(direction).at(loopList->getInfo()));

        ++loopsCounter;
    }
    else
    {
        //todo : faire idle loop
        legSprite.setTexture(textures->at(direction).at(CHARACTER_IDLE));
    }

    legSprite.setPosition(position);


    window->draw(legSprite);

    /*test
    for (unsigned i = 0; i < 13; ++i)
    {
        legSprite.setTexture(textures->at(0).at(i));
        window->clear(sf::Color::White);
        window->draw(legSprite);
        window->display();
        sf::sleep(sf::milliseconds(200));
    }

    /*fin test*/
}

void PANIM::changeLoop(byte_t newDirection) noexcept
{
    direction = newDirection;
}

void PANIM::update() noexcept
{

}


#undef ANIM
#undef PANIM