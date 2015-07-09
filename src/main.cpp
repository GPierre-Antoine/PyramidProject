//
// Created by Pierre-Antoine on 29/06/2015.
//

#include "VisualTest.h"
#include "UnitTest.h"

#define UNIT nsTest::UnitTest
#define VISUAL nsTest::VisualTest

int main()
{
    UNIT::ColliderTest();

    //Un seul visual a la fois a choisir
    VISUAL::PlayerAnimatedMovement1();

    return 0;
}
