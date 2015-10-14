//
// Created by Pierre-Antoine on 01/07/2015.
//

#include "Player.h"

using namespace nsRessourceManager;

///////////////////////////////////////////
#define PLAYER nsGameObject::Player      //
///////////////////////////////////////////


PLAYER::Player(UInt16 health /* = 100 */) noexcept
{
    this->health = health;
}

void PLAYER::render() const noexcept
{
    animator.render();

}


///////////////////////////////////////////
#undef PLAYER                            //
#define WARR nsGameObject::Warrior    //
///////////////////////////////////////////


WARR::Warrior(UInt16 x, UInt16 y) noexcept
        : Player(nsGameConstants::WARRIOR_HEALTH)
{
    setX(x);
    setY(y);
    animator = PlayerAnimator(nsRessourceManager::WARRIOR);
    animator.setPosition(x, y);
}

///////////////////////////////////////////
#undef WARR                              //
//#define bblblblb nsGameObject::blblblb //
///////////////////////////////////////////