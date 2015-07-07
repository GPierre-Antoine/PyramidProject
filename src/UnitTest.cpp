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

void TEST::PlayerAnimation1()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test Personnage!");
    window.setFramerateLimit(60);

    sf::Clock clock;

    //On n'aura plus à traiter le setWindow, qui est def pour tous les animator
    nsRessourceManager::Animator::setWindow(window);

    nsGameObject::Warrior guerrier = nsGameObject::Warrior(200, 0);

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
        window.display();

        sf::Int32 millisecondes = clock.getElapsedTime().asMilliseconds();
        if (millisecondes <= 4000)
            guerrier.testChangementMouvement(200, millisecondes / 10, true);
        else
        {
            clock.restart();
            guerrier.testChangementLoop(nsGameConstants::PLAYER_LEFT);
        }

        /*for (int i = 0; i < 12; ++i)
        {
            Sprite sprite;
            sprite.setTexture(RessourceManager::getTexture(MARTINE).at(i));
            window.clear();
            window.draw(sprite);
            window.display();
            sleep(milliseconds(1000));

        }*/
    }
}

#undef TEST