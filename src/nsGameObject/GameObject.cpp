//
// Created by Pierre-Antoine on 29/06/2015.
//

#include "GameObject.h"
typedef unsigned short int UInt16;

#define GO nsGameObject::GameObject
UInt16 GO::X() const
{
    return x;
}

UInt16 GO::Y() const
{
    return y;
}


#undef
