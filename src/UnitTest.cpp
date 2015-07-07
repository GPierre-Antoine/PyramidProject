//
// Created by Pierre-Antoine on 06/07/2015.
//

#include <assert.h>
#include "UnitTest.h"
#include "nsGameEngine/nsCollision/Collider.h"
#include "nsGameEngine/QuadTree.h"
#include <SFML/Window.hpp>
#include "nsGameObject/Player.h"

using nsGameEngine::nsCollider::Rectangle;
using nsGameEngine::nsCollider::Circle;
using nsGameEngine::QuadTree;

#define TEST nsTest::UnitTest


void TEST::ColliderTest()
{
    Rectangle r1 (0,0,10,10);

    Rectangle r2 (3,4,3,2);

    Rectangle r3 (3,4,3,2);

    Circle c1 (10,10,1); //Cercle construit de centre 11,11, rayon 1

    Circle c2 (9,9,1);   //Cercle construit de centre 10,10, rayon 1

    Circle c3 (0,0,5);   //Cercle construit de centre 5,5,   rayon 5

    Circle c4 (1,1,3);   //Cercle construit de centre 4,4,   rayon 3



    assert(r1.contains (r2));
    assert(!r1.contains (c1));
    assert(!r1.contains (c2));
    assert(r1.contains (c3));
    assert(r1.contains (c4));

    assert (r1.collidesWith (r1));
    assert (!r1.collidesWith (c1));
    assert (r1.collidesWith (c2));
    assert (r1.collidesWith (c3));
    assert (r1.collidesWith (c4));

}

void TEST::QuadTreeTest()
{
    QuadTree q1(1920, 1080);

}

#undef TEST