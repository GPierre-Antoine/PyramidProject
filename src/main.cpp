//
// Created by Pierre-Antoine on 29/06/2015.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "nsGameObject/Player.h"
#include "nsRessourceManager/const.h"
#include "nsRessourceManager/Animator.h"
#include "nsGameEngine/nsCollision/Collider.h"
#include "UnitTest.h"
#include <cassert>

void testPlayerAnimation1()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test Personnage!");
    window.setFramerateLimit(60);
    //On n'aura plus à traiter le setWindow, qui est def pour tous les animator
    nsRessourceManager::Animator::setWindow(window);

    nsGameObject::Warrior guerrier = nsGameObject::Warrior(100, 100);

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


/**/
int main()
{
    //fctBizarrePoubelle();
    testPlayerAnimation1();
    //UnitTest::ColliderTest();

    return 0;
}