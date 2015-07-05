//
// Created by Pierre-Antoine on 29/06/2015
//

#ifndef PYRAMIDPROJECT_RESSOURCEMANAGER_H
#define PYRAMIDPROJECT_RESSOURCEMANAGER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <map>
#include "const.h"

namespace nsRessourceManager
{

    class RessourceManager
    {
    private:

        static std::map<const std::string, const std::vector<sf::Texture>> textures;

    public:
        ////////////////////////////////////////////////////////////////////////////////////
        //                                                                                //
        //   Charge la texture de personnage correspondante dans la std::map,             //
        //   verifie par ailleurs si la texture n'est pas deja chargee.                   //
        //                                                                                //
        ////////////////////////////////////////////////////////////////////////////////////
        static void loadCharacterTextures(std::string imageFileName,
                                   const sf::Vector2i & tailleDecoupe, unsigned spriteCount);

        ////////////////////////////////////////////////////////////////////////////////////
        //                                                                                //
        //   Renvoit le tableau de textures contenu dans la map, a l'aide de la cle       //
        //   characterName.                                                               //
        //                                                                                //
        ////////////////////////////////////////////////////////////////////////////////////
        static const std::vector<sf::Texture> & getTexture(const std::string & characterName);

        RessourceManager();

    };

}

#endif //PYRAMIDPROJECT_RESSOURCEMANAGER_H









//vieux
//static const std::vector<std::vector<sf::Texture>>
//        textures[nsGameConstants::CHARACTER_SPRITES_COUNT][CharTexturesIndex::SIZE];
//static const std::vector<sf::Texture*> tablePointers [CharTexturesIndex::SIZE];