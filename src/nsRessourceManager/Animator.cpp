//
// Created by Pierre-Antoine on 29/06/2015.
//

#include <SFML/Graphics.hpp>
#include <iostream>
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
}

////////////////////////////////////        PLAYERANIMATOR         ////////////////////////////////////////////

PANIM::PlayerAnimator(const std::string & characterName)
        : currentLoop(PLAYER_DOWN), loopsCounter(0)
{
    ANIM::setMoving(false);
    //S'occupe de charger la texture de notre joueur (ex guerrier)
    RessourceManager::loadCharacterTextures(characterName, PLAYER_SRITE_SIZE, CHARACTER_SPRITES_COUNT);

    //On sauvegarde cette texture (pointeur)
    textures = &RessourceManager::getTexture(characterName);
}

PANIM::PlayerAnimator(const PlayerAnimator & animator)
        : currentLoop(animator.currentLoop), loopsCounter(animator.loopsCounter)
{
    ANIM::setMoving(isMoving());
}

void PANIM::render() noexcept
{
    sf::Sprite sprite;

    if (this->isMoving())
    {
        if (loopsCounter < PLAYER_STEPPING_FRAMES)
        {   //Premier pas
            sprite.setTexture(textures->at(currentLoop * 3 + 0));
        }
        else if (loopsCounter < PLAYER_STEPPING_FRAMES + PLAYER_STOP_STEP_FRAMES)
        {   //Ramene le pied
            sprite.setTexture(textures->at(currentLoop * 3 + 1));
        }
        else if (loopsCounter < PLAYER_STEPPING_FRAMES * 2 + PLAYER_STOP_STEP_FRAMES)
        {   //Avance l'autre pied
            sprite.setTexture(textures->at(currentLoop * 3 + 2));
        }
        else
        {   //Ramene encore
            sprite.setTexture(textures->at(currentLoop * 3 + 1));
        }
        ++loopsCounter;
        //Revient au debut de mon animation, si on a fait les 4 differents
        if (loopsCounter > PLAYER_STEPPING_FRAMES * 2 + PLAYER_STOP_STEP_FRAMES * 2)
            loopsCounter = 0;
    }
    else
    {
        //L'image du milieu est toujours celle sans mouvement d'ou le +1
        sprite.setTexture(textures->at(currentLoop * TILESET_SPRITES_PER_ROW + 1));
    }
    sprite.setPosition(position);

    window->draw(sprite);
}

void PANIM::changeLoop(UInt16 loopConstant) noexcept
{
    currentLoop = loopConstant;
}

void PANIM::update() noexcept
{

}


#undef ANIM
#undef PANIM