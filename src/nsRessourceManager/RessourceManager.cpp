//
// Created by Pierre-Antoine on 29/06/2015.
//

#include <SFML/Graphics/Texture.hpp>
#include "RessourceManager.h"

#define RS nsRessourceManager::RessourceManager

RS::RessourceManager()
{
}

void RS::loadCharacterTextures(std::string imageFileName, const sf::Vector2i & tailleDecoupe)
{
}

const sf::Texture* RS::getTextureTablePointer(int characterLine)
{
    //return le pinteur correspondant
    return tablePointers->at(characterLine);
}

#undef  RS