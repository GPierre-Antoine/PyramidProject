//
// Created by Pierre-Antoine on 29/06/2015.
//

#ifndef PYRAMIDPROJECT_RESSOURCEMANAGER_H
#define PYRAMIDPROJECT_RESSOURCEMANAGER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "const.h"

namespace nsRessourceManager
{

    class RessourceManager
    {
    private:

        static sf::RenderWindow* window;

        //static const sf::Texture textures[nsGameConstants::CHARACTER_NUMBER][12]; Autre solution

        static const std::vector<std::vector<sf::Texture>>
                text[nsGameConstants::CHARACTER_NUMBER][nsGameConstants::CHARACTER_SPRITES_COUNT];

    public:
        //A partir d'une image, charge les 12 sprites dans leur tableau respectif. Verifie en même temps si non deja chargé
        void loadCharacterTextures(std::string imageFileName, const sf::Vector2i & tailleDecoupe);

        //Renvoit le tableau de textures correspondant
        const std::vector<sf::Texture> & getTextureVec(int characterLine);

        //Renvoit la texture correspondante
        //sf::Texture* getTexture(int characterLine, int textureInd);

        RessourceManager();

    };

}

#endif //PYRAMIDPROJECT_RESSOURCEMANAGER_H