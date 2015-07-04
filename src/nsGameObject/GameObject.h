//
// Created by Pierre-Antoine on 29/06/2015.
//

#ifndef PYRAMIDPROJECT_GAMEOBJECT_H
#define PYRAMIDPROJECT_GAMEOBJECT_H

#include "../nsRessourceManager/Animator.h"
#include "../nsGameEngine/Defines/typedef.hpp"

namespace nsGameObject
{
    class GameObject
    {
    protected:
        nsRessourceManager::PlayerAnimator animator;

    public:
        virtual void render () noexcept = 0;
        virtual ~GameObject () {}

    };

}

#endif //PYRAMIDPROJECT_GAMEOBJECT_H
