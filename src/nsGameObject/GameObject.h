//
// Created by Pierre-Antoine on 29/06/2015.
//

#ifndef PYRAMIDPROJECT_GAMEOBJECT_H
#define PYRAMIDPROJECT_GAMEOBJECT_H

#include "../nsRessourceManager/Animator.h"

namespace nsGameObject
{

    class GameObject
    {
    private:
        nsRessourceManager::Animator anim;

    public:
        virtual void update () noexcept = 0;
        virtual void render () noexcept = 0;
        virtual ~GameObject () {}
    };

}

#endif //PYRAMIDPROJECT_GAMEOBJECT_H
