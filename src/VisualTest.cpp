//
// Created by Theo on 07/07/2015.
//

#include "VisualTest.h"
#include "nsRessourceManager/Animator.h"
#include "nsGameObject/Player.h"
#include "nsGameEngine/Movement.h"
#include "nsRessourceManager/KBManager.h"

#define TEST nsTest::VisualTest

using namespace std;
using namespace nsRessourceManager;

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
        if (window.pollEvent(event))
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

void TEST::FluiditeMovement ()
{
    KBManager::setKeyBind(KBManager::Up, sf::Keyboard::Key::Z);
    KBManager::setKeyBind(KBManager::Down, sf::Keyboard::Key::S);
    KBManager::setKeyBind(KBManager::Left, sf::Keyboard::Key::Q);
    KBManager::setKeyBind(KBManager::Right, sf::Keyboard::Key::D);

    sf::RenderWindow window(sf::VideoMode(1600, 900), "Test KeyBinds!");
    sf::CircleShape shape = sf::CircleShape(20, 3);
    shape.setFillColor(sf::Color::Red);

    nsGameEngine::Movement movement;

    const sf::Time timePerFrame = sf::seconds(1.f / 60.f); //60fps
    sf::Clock clock;

    while (window.isOpen())
    {
        clock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            ////////////////////////////////////////    GET INPUTS      ////////////////////////////////////
            movement.isGoingUp(sf::Keyboard::isKeyPressed(KBManager::getKey(KBManager::Up)));             //
            movement.isGoingDown(sf::Keyboard::isKeyPressed(KBManager::getKey(KBManager::Down)));         //
            movement.isGoingLeft(sf::Keyboard::isKeyPressed(KBManager::getKey(KBManager::Left)));         //
            movement.isGoingRight(sf::Keyboard::isKeyPressed(KBManager::getKey(KBManager::Right)));       //
            ////////////////////////////////////////////////////////////////////////////////////////////////
        }

        movement.update();

        //Pour seulement les nombres pairs
        //int16_t newShapePosX = (int16_t) (shape.getPosition().x + movement.getHorizontalMovement());
        //int16_t newShapePosY = (int16_t) (shape.getPosition().y + movement.getVerticalMovement());
        //newShapePosX /= 2;
        //newShapePosY /= 2;
        //newShapePosX *= 2;
        //newShapePosY *= 2;

        //Pour tous les nombres (pairs et impairs)
        float newShapePosX =  shape.getPosition().x + movement.getHorizontalMovement();
        float newShapePosY =  shape.getPosition().y + movement.getVerticalMovement();

        shape.setPosition(newShapePosX, newShapePosY);

        window.clear();
        window.draw(shape);
        window.display();

        while (clock.getElapsedTime() < timePerFrame)
            sf::sleep(sf::milliseconds(1));
    }
}

#undef TEST
