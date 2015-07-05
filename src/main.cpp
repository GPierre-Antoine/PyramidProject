//
// Created by Pierre-Antoine on 29/06/2015.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "nsRessourceManager/const.h"
#include "nsRessourceManager/Animator.h"
#include "nsGameEngine/nsCollision/Collider.h"
#include <cassert>


void testCollider ();

/** /
void fctBizarrePoubelle ()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    //On n'aura plus à traiter le setWindow, qui est def pour tous les animator
    nsRessourceManager::Animator::setWindow(window);

    nsGameEngine::nsCollider::RectangleUI rect(0,0,1,1);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    std::cout << nsGameConstants::CHARACTER_SPRITES_COUNT << "coucou";
}
 /**/

void testPlayerAnimation1 ()
{


}

/**/
void testCollider ()
{
    nsGameEngine::nsCollider::RectangleUI r1 (0,0,10,10);
    nsGameEngine::nsCollider::RectangleUI r2 (5,5,1,1);

    assert(r1.contains (r2));
}

/**/
int main()
{
    testCollider ();
    //fctBizarrePoubelle();
    testPlayerAnimation1();

    return 0;
}