//
// Created by Pierre-Antoine on 29/06/2015.
//

#ifndef PYRAMIDPROJECT_ANIMATOR_H
#define PYRAMIDPROJECT_ANIMATOR_H

#include "RessourceManager.h"

namespace nsRessourceManager
{
    class Animator
    {
    private:
        static sf::RenderWindow window;

    public:
        void setWindow (sf::RenderWindow & window) noexcept;

        void update () noexcept;
        void render () const noexcept;
        Animator ();
    };

}
#endif //PYRAMIDPROJECT_ANIMATOR_H
