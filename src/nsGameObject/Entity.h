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
    private:
        UInt16 x;
        UInt16 y;

    protected:
        void setX(UInt16 x);

        void setY(UInt16 y);

    public:
        virtual void update() noexcept = 0;

        virtual UInt16 X() const noexcept;

        virtual UInt16 Y() const noexcept;

        virtual ~Entity() {}

    };
}


#endif //PYRAMIDPROJECT_ENTITY_H
