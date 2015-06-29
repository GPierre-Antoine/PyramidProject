//
// Created by Theo on 29/06/2015.
//

#include "Character.h"

#define GO nsGameObject::Character

virtual void GO::render()
{
    charSprite.setPosition(position);
    ressourceManager->drawSomething(charSprite);
}


#undef GO