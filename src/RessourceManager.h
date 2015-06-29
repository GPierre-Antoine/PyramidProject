//
// Created by Pierre-Antoine on 29/06/2015.
//

#ifndef PYRAMIDPROJECT_RESSOURCEMANAGER_H
#define PYRAMIDPROJECT_RESSOURCEMANAGER_H

#include <SFML/Graphics/RenderWindow.hpp>

namespace nsRessourceManager
{
    class RessourceManager
    {
    private:
        static sf::RenderWindow window;
        static std::vector<sf::Texture> textures;

    public:
        RessourceManager ();
        void setWindow(sf::RenderWindow) ;
    };

}
#endif //PYRAMIDPROJECT_RESSOURCEMANAGER_H
