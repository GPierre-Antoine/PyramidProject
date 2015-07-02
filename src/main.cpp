//
// Created by Pierre-Antoine on 29/06/2015.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "nsRessourceManager/const.h"
#include "nsGameEngine/Collision/Collider.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    nsGameEngine::nsCollider::Rectangle rect(0,0,1,1);
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

    return 0;
}