//
// Created by Theo on 09/07/2015.
//

#include "Movement.h"

using namespace nsGameConstants;

#define MOVE nsGameEngine::Movement

MOVE::Movement() noexcept
{ }

float MOVE::getHorizontalMovement() const noexcept
{
    return (speedRight - speedLeft) * maxSpeedPerFrame;
}

float MOVE::getVerticalMovement() const noexcept
{
    return (speedDown - speedUp) * maxSpeedPerFrame;
}

void MOVE::update() noexcept
{
    //Si va dans une direction, augmente petit a petit la vitesse
    //Si ne va pas dans cette direction, descend petit a petit
    if (goingUp && speedUp < 1.f)
        speedUp += 1.f / maxSpeedFrames;
    else if (speedUp > 0.f)
    {
        speedUp -= 1.f / stoppingFrames;
        speedUp = (speedUp < 0.f ? 0.f : speedUp);
    }

    if (goingDown && speedDown < 1.f)
        speedDown += 1.f / maxSpeedFrames;
    else if (speedDown > 0.f)
    {
        speedDown -= 1.f / stoppingFrames;
        speedDown = (speedDown < 0.f ? 0.f : speedDown);
    }

    if (goingLeft && speedLeft < 1.f)
        speedLeft += 1.f / maxSpeedFrames;
    else if (speedLeft > 0.f)
    {
        speedLeft -= 1.f / stoppingFrames;
        speedLeft = (speedLeft < 0.f ? 0.f : speedLeft);
    }

    if (goingRight && speedRight < 1.f)
        speedRight += 1.f / maxSpeedFrames;
    else if (speedRight > 0.f)
    {
        speedRight -= 1.f / stoppingFrames;
        speedRight = (speedRight < 0.f ? 0.f : speedRight);
    }

} //Update

void MOVE::isGoingUp(bool goingUp) noexcept
{
    this->goingUp = goingUp;
}

void MOVE::isGoingDown(bool goingDown) noexcept
{
    this->goingDown = goingDown;
}

void MOVE::isGoingLeft(bool goingLeft) noexcept
{
    this->goingLeft = goingLeft;
}

void MOVE::isGoingRight(bool goingRight) noexcept
{
    this->goingRight = goingRight;
}

void MOVE::setMaxSpeedFrames(Int16 maxSpeedFrames) noexcept
{
    this->maxSpeedFrames = maxSpeedFrames;
}

void MOVE::setStoppingFrames(Int16 stoppingFrames) noexcept
{
    this->stoppingFrames = stoppingFrames;
}

void MOVE::setMaxSpeedPerFrame(float maxSpeedPerFrame) noexcept
{
    this->maxSpeedPerFrame = maxSpeedPerFrame;
}

#undef MOVE