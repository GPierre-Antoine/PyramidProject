//
// Created by Pierre-Antoine on 01/07/2015.
//

#ifndef PYRAMIDPROJECT_ENTITY_H
#define PYRAMIDPROJECT_ENTITY_H

#include "GameObject.h"

namespace nsGameObject
{
    class Entity : public GameObject
    {
        virtual void update () noexcept = 0;
        virtual void ~Entity () {}
    };
}


#endif //PYRAMIDPROJECT_ENTITY_H
