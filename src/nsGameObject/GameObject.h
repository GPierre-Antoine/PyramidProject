//
// Created by Pierre-Antoine on 29/06/2015.
//

#ifndef PYRAMIDPROJECT_GAMEOBJECT_H
#define PYRAMIDPROJECT_GAMEOBJECT_H

#include <memory>

#include "../nsRessourceManager/Animator.h"
#include "../Utility/typedef.hpp"

namespace nsGameObject
{
    class GameObject
    {
    public:
        virtual std::shared_ptr<GameObject> clone () const noexcept = 0;
        virtual void render () const noexcept = 0;
        virtual ~GameObject () {}

    };

}

#endif //PYRAMIDPROJECT_GAMEOBJECT_H
