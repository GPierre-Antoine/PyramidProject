//
// Created by Pierre-Antoine on 01/07/2015.
//

#ifndef PYRAMIDPROJECT_ENTITY_H
#define PYRAMIDPROJECT_ENTITY_H

#include "GameObject.h"
#include "Interface.h"

namespace nsGameObject
{
    class Entity : public GameObject, public IMovable//, public ICollidable
    {
    private:
        UInt16 x;
        UInt16 y;

    protected:
        mutable nsRessourceManager::PlayerAnimator animator;

        void setX(UInt16 x);

        void setY(UInt16 y);

    public:
        UInt16 X() const noexcept;
        //Pas besoin d'être virtual, est defini ici, et jamais redefini
        UInt16 Y() const noexcept;

        virtual void update() noexcept = 0;

        virtual ~Entity() {}

    };
}


#endif //PYRAMIDPROJECT_ENTITY_H
