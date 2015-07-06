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
using nsGameEngine::QuadTree;

#define TEST nsTest::UnitTest


void TEST::ColliderTest ()
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

void TEST::QuadTreeTest ()
{
    QuadTree q1(1920,1080);

}

void TEST::PlayerAnimation1()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test Personnage!");
    window.setFramerateLimit(60);
    //On n'aura plus à traiter le setWindow, qui est def pour tous les animator
    nsRessourceManager::Animator::setWindow(window);

    nsGameObject::Warrior guerrier = nsGameObject::Warrior(0, 0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        guerrier.render();

        /*for (int i = 0; i < 12; ++i)
        {
            Sprite sprite;
            sprite.setTexture(RessourceManager::getTexture(MARTINE).at(i));
            window.clear();
            window.draw(sprite);
            window.display();
            sleep(milliseconds(1000));

        }*/
        window.display();
    }
}

#undef TEST