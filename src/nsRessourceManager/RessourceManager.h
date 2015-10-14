//
// Created by Pierre-Antoine on 29/06/2015
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <map>
#include "const.h"

namespace nsRessourceManager
{
    typedef std::vector<sf::Texture> VTextures_t;
    typedef std::vector<VTextures_t> MTextures_t;

    class RessourceManager
    {
    private:

        //static std::map<const std::string, const std::vector<sf::Texture>> textures;
        static std::map<const byte_t, const MTextures_t> textures;

    public:
        ////////////////////////////////////////////////////////////////////////////////////
        //                                                                                //
        //   Charge la texture de personnage correspondante dans la std::map,             //
        //   verifie par ailleurs si la texture n'est pas deja chargee.                   //
        //                                                                                //
        ////////////////////////////////////////////////////////////////////////////////////
        //static void loadCharacterTextures(std::string imageFileName,
        //                           const sf::Vector2i & tailleDecoupe, unsigned spriteCount);

        ////////////////////////////////////////////////////////////////////////////////////
        //                                                                                //
        //   Charge tous les sprites du personnage dans la matrice et place cette         //
        //   matrice dans la map textures. ne fait rien si deja chargee                   //
        //                                                                                //
        ////////////////////////////////////////////////////////////////////////////////////
        static void loadCharacterTextures(const KPair_t & character, const sf::Vector2i & tailleDecoupe);

        ////////////////////////////////////////////////////////////////////////////////////
        //                                                                                //
        //   Renvoit le tableau de textures contenu dans la map, a l'aide de la cle       //
        //   characterName.                                                               //
        //                                                                                //
        ////////////////////////////////////////////////////////////////////////////////////
        //static const std::vector<sf::Texture> & getTexture(const std::string & characterName);
        static const MTextures_t & getTexture(byte_t characterID);

        RessourceManager();

    }; // class RessourceManager

} // nsRessourceManager