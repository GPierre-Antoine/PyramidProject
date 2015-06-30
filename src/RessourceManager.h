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
        //Un pointeur vers la fenetre de jeu pour dessiner
        static sf::RenderWindow* window;

        //contient des tableaux de textures de personnages, 0 car tableau vide au debut,
        //on ajoutera les 12 textures par l'utilisation d'un push_back
        static std::vector<std::vector<sf::Texture>> textures[nsGameConstants::CHARACTER_NUMBER][0];

    public:
        //A partir d'une image, charge les 12 sprites dans leur tableau respectif. Verifie
        //a l'occasion si non deja chargé
        void loadCharacterTextures(std::string imageFileName, const sf::Vector2i & tailleDecoupe);

        //renvoit l'iterateur du tableau de textures, pour le personnagecorrespondant
        const std::vector<sf::Texture>& getTabPointer(int characterLine);

        RessourceManager();

    }; // class RessourceManager

} // namespace nsRessourceManager

#endif //PYRAMIDPROJECT_RESSOURCEMANAGER_H
