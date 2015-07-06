//
// Created by Pierre-Antoine on 01/07/2015.
//

#ifndef PYRAMIDPROJECT_PLAYER_H
#define PYRAMIDPROJECT_PLAYER_H

#include "Character.h"
#include "../nsRessourceManager/Animator.h"
#include "../nsGameEngine/Defines/typedef.hpp"

namespace nsGameObject
{
    class Player : public Character
    {
    private:
        UInt16 health;

    protected:
        Player(UInt16 health = 100) noexcept;

    public:
        virtual void render() noexcept;

    }; //class Player





    class Warrior : public Player
    {
    public:
        Warrior(UInt16 x, UInt16 y) noexcept;

        void testChangementMouvement (UInt16 x, UInt16 y, bool moving)
        {
            animator.setPosition(x, y);
            animator.setMoving(moving);
        }

        void testChangementLoop (UInt16 loop)
        {
            animator.changeLoop(loop);
        }

    }; //class Warrior
}


#endif //PYRAMIDPROJECT_PLAYER_H
