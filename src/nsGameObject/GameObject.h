//
// Created by Pierre-Antoine on 29/06/2015.
//

#ifndef PYRAMIDPROJECT_GAMEOBJECT_H
#define PYRAMIDPROJECT_GAMEOBJECT_H

#include "../nsRessourceManager/Animator.h"

namespace nsGameObject
{
    typedef unsigned short int UInt16;

    class GameObject
    {
    private:
        nsRessourceManager::Animator anim;
        UInt16 x;
        UInt16 y;

    public:

        UInt16 X() const noexcept;
        UInt16 Y() const noexcept;

        virtual void update () noexcept = 0;
        virtual void render () noexcept = 0;
        virtual ~GameObject () {}
    };

}

#endif //PYRAMIDPROJECT_GAMEOBJECT_H
