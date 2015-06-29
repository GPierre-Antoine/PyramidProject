//
// Created by Pierre-Antoine on 29/06/2015.
//

#include "RessourceManager.h"

#define RS nsRessourceManager::RessourceManager
//using namespace sf;


RS::RessourceManager()
{

}

void RS::loadCharacterTextures(std::string imageFileName, const sf::Vector2i & tailleDecoupe)
{
}

std::vector<const sf::Texture>* RS::getTabPointer(int line)
{
    std::vector<const sf::Texture> tab;
    tab = textures;
    //return &textures[line];
    return nullptr;
}

#undef  RS
