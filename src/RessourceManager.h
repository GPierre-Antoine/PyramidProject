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
        static sf::RenderWindow *window = 0;

    public:
        RessourceManager ();
        void SetRenderWindow (sf::RenderWindow & window) noexcept;
    };

}
#endif //PYRAMIDPROJECT_RESSOURCEMANAGER_H
