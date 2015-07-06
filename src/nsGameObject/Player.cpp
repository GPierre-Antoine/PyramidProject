//
// Created by Pierre-Antoine on 01/07/2015.
//

#include "Player.h"
#include <iostream>
#include "../nsRessourceManager/const.h"
#include "../nsRessourceManager/Animator.h"

using namespace nsRessourceManager;

///////////////////////////////////////////
#define PLAYER nsGameObject::Player      //
///////////////////////////////////////////


PLAYER::Player(UInt16 health /* = 100 */) noexcept
{
    this->health = health;
}

void PLAYER::render() noexcept
{
    animator.render();

}


///////////////////////////////////////////
#undef PLAYER                            //
#define WARRIOR nsGameObject::Warrior    //
///////////////////////////////////////////


WARRIOR::Warrior(UInt16 x, UInt16 y) noexcept
        : Player(nsGameConstants::WARRIOR_HEALTH)
{
    setX(x);
    setY(y);
    animator = PlayerAnimator(MARTINE);
    animator.setPosition(x, y);
}

///////////////////////////////////////////
#undef WARRIOR                           //
//#define bblblblb nsGameObject::blblblb    //
///////////////////////////////////////////