//
// Created by Pierre-Antoine on 01/07/2015.
//

#include "Entity.h"

#define GO nsGameObject::Entity

/*void GO::move(Int16 Up, Int16 Right)
{


}*/

UInt16 GO::Y() const noexcept
{
    return x;
}

UInt16 GO::X() const noexcept
{
    return y;
}

void GO::setX(UInt16 x)
{
    this->x = x;
}

void GO::setY(UInt16 y)
{
    this->y = y;
}


#undef GO