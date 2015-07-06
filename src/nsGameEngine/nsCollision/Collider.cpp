//
// Created by Pierre-Antoine on 05/07/2015.
//

#include "Collider.h"

/* Mirrored Definition */
bool nsGameEngine::nsCollider::Rectangle::contains (const nsGameEngine::nsCollider::Collider & col) const noexcept
{
    return col.isContainedByRectangle (*this);
}

/* Do Object fit in QuadTree N */
bool nsGameEngine::nsCollider::Circle::isContainedByRectangle (const nsGameEngine::nsCollider::Rectangle & rect) const noexcept
{
    return (rect.getX () <= this->x) && (this->x + (this->radius << 1) <= rect.getX () + rect.getWidth ()) &&
           (rect.getY () <= this->y) && (this->y + (this->radius << 1) <= rect.getY () + rect.getHeight ());
}

bool nsGameEngine::nsCollider::Rectangle::isContainedByRectangle (const nsGameEngine::nsCollider::Rectangle & rect) const noexcept
{
    return (rect.x <= this->x) && (this->x + this->getWidth () <= rect.x + rect.getWidth ())
           && (rect.y <= this->y) && (this->y + this->getHeight () <= rect.y + rect.getHeight ());
}


/* Constructors */
nsGameEngine::nsCollider::Rectangle::Rectangle (const UInt16 X,const UInt16 Y,const UInt16 WIDTH,const UInt16 HEIGHT) noexcept :
        x (X), y (Y), width (WIDTH), height (HEIGHT)
{

}

nsGameEngine::nsCollider::Circle::Circle (const UInt16 X, const UInt16 Y, const UInt16 RADIUS) noexcept:
        x (X), y (Y), radius (RADIUS)
{

}
/* getters */

const UInt16 nsGameEngine::nsCollider::Rectangle::getWidth () const noexcept
{
    return width;
}

const UInt16 nsGameEngine::nsCollider::Rectangle::getHeight () const noexcept
{
    return height;
}

const UInt16 nsGameEngine::nsCollider::Rectangle::getX () const noexcept
{
    return x;
}

const UInt16 nsGameEngine::nsCollider::Rectangle::getY () const noexcept
{
    return y;
}

const UInt16 nsGameEngine::nsCollider::Circle::getX () const noexcept
{
    return x;
}

const UInt16 nsGameEngine::nsCollider::Circle::getY () const noexcept
{
    return y;
}

const UInt16 nsGameEngine::nsCollider::Circle::getRad () const noexcept
{
    return radius;
}
/**/