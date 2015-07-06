//
// Created by Pierre-Antoine on 06/07/2015.
//

#include <assert.h>
#include "UnitTest.h"
#include "nsGameEngine/nsCollision/Collider.h"

void nsTest::UnitTest::ColliderTest ()
{
    nsGameEngine::nsCollider::Rectangle r1 (0,0,10,10);
    nsGameEngine::nsCollider::Rectangle r2 (0,0,10,10);
    nsGameEngine::nsCollider::Rectangle r3 (11,3,4,6);

    //assert(r1.contains (r2));

    assert(r1.contains (r2));
    assert(!r1.contains(r3));
}
