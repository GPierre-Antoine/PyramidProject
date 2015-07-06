//
// Created by Pierre-Antoine on 06/07/2015.
//

#include <assert.h>
#include "UnitTest.h"
#include "nsGameEngine/nsCollision/Collider.h"
#include "nsGameEngine/QuadTree.h"

using nsGameEngine::nsCollider::Rectangle;
using nsGameEngine::QuadTree;


void nsTest::UnitTest::ColliderTest ()
{
    Rectangle r1 (0,0,10,10);
    Rectangle r2 (1,1,1,1);
    Rectangle r3 (11,3,4,6);
    Rectangle r4 (0,0,11,11);

    assert ( r1.contains (r1));
    assert ( r1.contains (r2));
    assert (!r1.contains (r3));
    assert ( r4.contains (r1));
    assert (!r1.contains (r4));

}

void nsTest::UnitTest::QuadTreeTest ()
{
    QuadTree q1(1920,1080);

}
