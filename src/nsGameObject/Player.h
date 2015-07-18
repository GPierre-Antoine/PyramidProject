//
// Created by Pierre-Antoine on 01/07/2015.
//

#ifndef PYRAMIDPROJECT_PLAYER_H
#define PYRAMIDPROJECT_PLAYER_H

#include "Character.h"
#include "../nsRessourceManager/Animator.h"
#include "../Utility/typedef.hpp"

namespace nsGameObject
{
    class Player : public Character
    {
    private:
        UInt16 health;

    protected:
        Player(UInt16 health = 100) noexcept;

    public:
        virtual void render() const noexcept;

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

        virtual std::shared_ptr<GameObject> clone () const noexcept
        {
            return std::shared_ptr<GameObject>(new Warrior (*this));
        }

        virtual void render () const noexcept
        {

        }
    }; //class Warrior
}


#endif //PYRAMIDPROJECT_PLAYER_H
