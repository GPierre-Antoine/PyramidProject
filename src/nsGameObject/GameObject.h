//
// Created by Pierre-Antoine on 29/06/2015.
//

#ifndef PYRAMIDPROJECT_GAMEOBJECT_H
#define PYRAMIDPROJECT_GAMEOBJECT_H

#include "../nsRessourceManager/Animator.h"
#include "../Utility/typedef.hpp"

namespace nsGameObject
{
    class GameObject
    {
    public:
        virtual void render () noexcept = 0;
        virtual ~GameObject () {}

    };

}

#endif //PYRAMIDPROJECT_GAMEOBJECT_H
