//
// Created by Pierre-Antoine on 29/06/2015.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animator.h"

using namespace nsGameConstants;

#define RS nsRessourceManager::Animator

//Definition
sf::RenderWindow* RS::window;

void RS::update() noexcept
{

}

void RS::render() noexcept
{

}

void RS::setWindow(sf::RenderWindow & window) noexcept
{
    RS::window = &window;
}

void RS::setPosition(UInt16 x, UInt16 y)
{
    position.x = (float) x;
    position.y = (float) y;
}


#undef RS
#define RSP nsRessourceManager::PlayerAnimator


RSP::PlayerAnimator(const std::string & characterName)
        : isMoving(true), currentFacing(PLAYER_DOWN), loopsCounter(0)
{
    //S'occupe de charger la texture de notre joueur (ex guerrier)
    RessourceManager::loadCharacterTextures(characterName, PLAYER_SRITE_SIZE, CHARACTER_SPRITES_COUNT);

    //On sauvegarde cette texture (pointeur)
    textures = &RessourceManager::getTexture(characterName);
}

//Constructeur par recopie
RSP::PlayerAnimator(const PlayerAnimator & animator)
        : isMoving(animator.isMoving), currentFacing(animator.currentFacing), loopsCounter(animator.loopsCounter)
{

}


void RSP::render() noexcept
{
    sf::Sprite sprite;

    if (isMoving)
    {
        if (loopsCounter < PLAYER_STEPPING_FRAMES)
        {   //Premier pas
            sprite.setTexture(textures->at(currentFacing * 3 + 0));
        }
        else if (loopsCounter < PLAYER_STEPPING_FRAMES + PLAYER_STOP_STEP_FRAMES)
        {   //Ramene le pied
            sprite.setTexture(textures->at(currentFacing * 3 + 1));
        }
        else if (loopsCounter < PLAYER_STEPPING_FRAMES * 2 + PLAYER_STOP_STEP_FRAMES)
        {   //Avance l'autre pied
            sprite.setTexture(textures->at(currentFacing * 3 + 2));
        }
        else
        {   //Ramene encore
            sprite.setTexture(textures->at(currentFacing * 3 + 1));
        }
        ++loopsCounter;
        //Revient au debut de mon animation, si on a fait les 4 differents
        if (loopsCounter > PLAYER_STEPPING_FRAMES * 2 + PLAYER_STOP_STEP_FRAMES * 2)
            loopsCounter = 0;
    }
    else
    {
        //L'image du milieu est toujours celle sans mouvement d'ou le +1
        sprite.setTexture(textures->at(currentFacing * TILESET_SPRITES_PER_ROW + 1));
    }
    sprite.setPosition(position);

    window->draw(sprite);
}

void RSP::update() noexcept
{

    Animator::update();

}

#undef RSP