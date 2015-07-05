//
// Created by Pierre-Antoine on 05/07/2015.
//

#include "Collider.h"

/****************************************** Mirrored Definition *********************************************/
template <typename T>
bool nsGameEngine::nsCollider::Rectangle<T>::contains (const nsGameEngine::nsCollider::Collider<T> & col) const noexcept
{
    return col.isContainedByRectangle (*this);
}

/****************************************** Do Object fit in QuadTree N *************************************/
template <typename T>
bool nsGameEngine::nsCollider::Circle<T>::isContainedByRectangle (const nsGameEngine::nsCollider::Rectangle<T> & rect) const noexcept
{
    return (rect.getX () <= this->*x) && (this->*x + (this->*radius << 1) <= add(rect.getX (),rect.getWidth ())) &&
           (rect.getY () <= this->*y) && (this->*y + (this->*radius << 1) <= add(rect.getY (),rect.getHeight ()));
}

template <typename T>
bool nsGameEngine::nsCollider::Rectangle<T>::isContainedByRectangle (const nsGameEngine::nsCollider::Rectangle<T> & rect) const noexcept
{
    return (rect.*x <= this->*x) && (this->*x + this->getWidth () <= rect.*x + rect.getWidth ())
           && (rect.*y <= this->*y) && (this->*y + this->getHeight () <= rect.*y + rect.getHeight ());
}


/****************************************** Constructors ***************************************************/
template <typename T>
nsGameEngine::nsCollider::Rectangle<T>::Rectangle (const T X,const T Y,const T WIDTH,const T HEIGHT) noexcept:
        x (X), y (Y), width (WIDTH), height (HEIGHT)
{

}

template <typename T>
nsGameEngine::nsCollider::Circle<T>::Circle (T X, T Y, T RADIUS) noexcept:
        x (X), y (Y), radius (RADIUS)
{

}
/***************************************** getters ********************************************************/

template <typename T>
const T nsGameEngine::nsCollider::Rectangle<T>::getWidth () const noexcept
{
    return width;
}

template <typename T>
const T nsGameEngine::nsCollider::Rectangle<T>::getHeight () const noexcept
{
    return height;
}

template <typename T>
const T nsGameEngine::nsCollider::Rectangle<T>::getX () const noexcept
{
    return x;
}

template <typename T>
const T nsGameEngine::nsCollider::Rectangle<T>::getY () const noexcept
{
    return y;
}

template <typename T>
const T nsGameEngine::nsCollider::Circle<T>::getX () const noexcept
{
    return x;
}

template <typename T>
const T nsGameEngine::nsCollider::Circle<T>::getY () const noexcept
{
    return y;
}

template <typename T>
const T nsGameEngine::nsCollider::Circle<T>::getRad () const noexcept
{
    return radius;
}