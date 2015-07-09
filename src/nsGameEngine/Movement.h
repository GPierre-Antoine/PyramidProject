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
        float speedUp = 0.f;
        float speedDown = 0.f;
        float speedLeft = 0.f;
        float speedRight = 0.f;

        bool goingUp = false;
        bool goingDown = false;
        bool goingLeft = false;
        bool goingRight = false;

        Int16 maxSpeedFrames = nsGameConstants::ACCELERATION_FRAMES_NUMBER;
        Int16 stoppingFrames = nsGameConstants::STOPPING_FRAMES_NUMBER;
        float maxSpeedPerFrame = nsGameConstants::MAX_SPEED_PIXEL_PER_FRAME;

    public:
        Movement() noexcept;

        float getHorizontalMovement() const noexcept;

        float getVerticalMovement() const noexcept;

        void update() noexcept;

        void isGoingUp(bool goingUp) noexcept;

        void isGoingDown(bool goingDown) noexcept;

        void isGoingLeft(bool goingLeft) noexcept;

        void isGoingRight(bool goingRight) noexcept;

        void setMaxSpeedFrames(Int16 maxSpeedFrames) noexcept;

        void setStoppingFrames(Int16 stoppingFrames) noexcept;

        void setMaxSpeedPerFrame(float maxSpeedPerFrame) noexcept;

    };
}

#endif //PYRAMIDPROJECT_MOVEMENT_H
