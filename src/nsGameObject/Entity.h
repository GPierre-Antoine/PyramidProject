//
// Created by Pierre-Antoine on 01/07/2015.
//

#ifndef PYRAMIDPROJECT_ENTITY_H
#define PYRAMIDPROJECT_ENTITY_H

#include "GameObject.h"
#include "Interface.h"

namespace nsGameObject
{
    class Entity : public GameObject, public IMovable, public ICollidable
    {
    public:
        virtual void update () noexcept = 0;
        virtual ~Entity () {}
    };
}


#endif //PYRAMIDPROJECT_ENTITY_H
