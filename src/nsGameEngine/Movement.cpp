//
// Created by Theo on 09/07/2015.
//

#include "Movement.h"
#include "Defines/typedef.hpp"
#include "../nsRessourceManager/const.h"

using namespace nsGameConstants;

#define MOVE nsGameEngine::Movement

MOVE::Movement() noexcept
        : speedUp(0), speedDown(0), speedLeft(0), speedRight(0),
          goingUp(false), goingDown(false), goingLeft(false), goingRight(false)
{ }

float MOVE::getHorizontalMovement() const noexcept
{
    return (speedRight - speedLeft) * MAX_SPEED_PIXEL_PER_FRAME;
}

float MOVE::getVerticalMovement() const noexcept
{
    return (speedDown - speedUp) * MAX_SPEED_PIXEL_PER_FRAME;
}

void MOVE::update() noexcept
{
    //Si va dans une direction, augmente petit a petit la vitesse
    //Si ne va pas dans cette direction, descend petit a petit
    if (goingUp && speedUp < 1.f)
        speedUp += 1.f / ACCELERATION_FRAMES_NUMBER;
    else if (speedUp > 0.f)
    {
        speedUp -= 1.f / STOPPING_FRAMES_NUMBER;
        speedUp = (speedUp < 0.f ? 0.f : speedUp);
    }

    if (goingDown && speedDown < 1.f)
        speedDown += 1.f / ACCELERATION_FRAMES_NUMBER;
    else if (speedDown > 0.f)
    {
        speedDown -= 1.f / STOPPING_FRAMES_NUMBER;
        speedDown = (speedDown < 0.f ? 0.f : speedDown);
    }

    if (goingLeft && speedLeft < 1.f)
        speedLeft += 1.f / ACCELERATION_FRAMES_NUMBER;
    else if (speedLeft > 0.f)
    {
        speedLeft -= 1.f / STOPPING_FRAMES_NUMBER;
        speedLeft = (speedLeft < 0.f ? 0.f : speedLeft);
    }

    if (goingRight && speedRight < 1.f)
        speedRight += 1.f / ACCELERATION_FRAMES_NUMBER;
    else if (speedRight > 0.f)
    {
        speedRight -= 1.f / STOPPING_FRAMES_NUMBER;
        speedRight = (speedRight < 0.f ? 0.f : speedRight);
    }

} //Update

void MOVE::isGoingUp(bool goingUp) noexcept
{
    MOVE::goingUp = goingUp;
}

void MOVE::isGoingDown(bool goingDown) noexcept
{
    MOVE::goingDown = goingDown;
}

void MOVE::isGoingLeft(bool goingLeft) noexcept
{
    MOVE::goingLeft = goingLeft;
}

void MOVE::isGoingRight(bool goingRight) noexcept
{
    MOVE::goingRight = goingRight;
}

#undef MOVE