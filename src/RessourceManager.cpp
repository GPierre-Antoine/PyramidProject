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

const std::vector<sf::Texture> & RS::getTextureVec(int characterLine)
{
    //Pointe le debut de la matrice (premier tableau)
    const std::vector<std::vector<sf::Texture>>* matrixPtr = *text;
    //renvoit le tableau à l'indice characterLine
    return matrixPtr->at(characterLine);
}

/*sf::Texture* RS::getTexture(int characterLine, int textureInd)
{
    sf::Texture* texture = &textures[characterLine][textureInd];
    sf::Texture* ptr;
    ptr = textures[0];

    return textures[0];
}*/

#undef  RS
