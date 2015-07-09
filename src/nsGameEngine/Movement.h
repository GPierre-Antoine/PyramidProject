//
// Created by Theo on 09/07/2015.
//

#include "Defines/typedef.hpp"
#include "../nsRessourceManager/const.h"

#ifndef PYRAMIDPROJECT_MOVEMENT_H
#define PYRAMIDPROJECT_MOVEMENT_H

namespace nsGameEngine
{
    class Movement
    {
    private:
        //Pourcentages de speed 0 < speed < 1
        float speedUp;
        float speedDown;
        float speedLeft;
        float speedRight;

        bool goingUp;
        bool goingDown;
        bool goingLeft;
        bool goingRight;

    public:
        Movement() noexcept;

        float getHorizontalMovement() const noexcept;

        float getVerticalMovement() const noexcept;

        void update() noexcept;

        void isGoingUp(bool goingUp) noexcept;
        void isGoingDown(bool goingDown) noexcept;
        void isGoingLeft(bool goingLeft) noexcept;
        void isGoingRight(bool goingRight) noexcept;

    };
}


#endif //PYRAMIDPROJECT_MOVEMENT_H
