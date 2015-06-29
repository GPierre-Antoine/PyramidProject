//
// Created by Pierre-Antoine on 29/06/2015.
//

#ifndef PYRAMIDPROJECT_RESSOURCEMANAGER_H
#define PYRAMIDPROJECT_RESSOURCEMANAGER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <c++/bits/stl_map.h>

namespace nsRessourceManager
{
    //Pour la taille du tableau de textures, actuellement on a Martine, Momie donc 2
    const int CHARACTER_NUMBER = 2;

    class RessourceManager
    {
    private:
        //Un pointeur vers la fenetre de jeu pour dessiner
        static sf::RenderWindow* window;

        //Old one
        //static std::vector<const sf::Texture> textures;

        //contient des tableaux de textures de personnages, 0 car tableau vide au debut,
        //on ajoutera les 12 textures par l'utilisation d'un push_back
        static std::vector<std::vector<const sf::Texture>> textures[CHARACTER_NUMBER][12];

    public:
        void loadCharacterTextures(std::string imageFileName, const sf::Vector2i & tailleDecoupe);
        std::vector<const sf::Texture>* getTabPointer (int line);

        RessourceManager();
    };

    enum CharacterTextures
    {
        MARTINE = RessourceManager.getTabPointer (0),
        MOMIE = RessourceManager.getTabPointer(1)
    };

}

#endif //PYRAMIDPROJECT_RESSOURCEMANAGER_H
