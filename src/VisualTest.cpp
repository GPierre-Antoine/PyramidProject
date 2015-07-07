//
// Created by Theo on 07/07/2015.
//

#include "VisualTest.h"
#include "nsRessourceManager/Animator.h"
#include "nsGameObject/Player.h"
#include "nsRessourceManager/const.h"
#include <SFML/Graphics.hpp>
#include <vector>

#define TEST nsTest::VisualTest

using namespace std;

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


class KBManager
{
public:
    static vector<sf::Keyboard::Key> keyBinds;

    //nbr de controls
    static const UInt16 ACTION_KEY_COUNT = 4;

    enum Action
    {
        Up = 0,
        Down = 1,
        Left = 2,
        Right = 3,

    };

    static sf::Keyboard::Key getKey(Action action)
    {
        return keyBinds[action];
    }

    static void setKeyBind(Action action, sf::Keyboard::Key key)
    {
        keyBinds[action] = key;
    }
};

vector<sf::Keyboard::Key> KBManager::keyBinds(KBManager::ACTION_KEY_COUNT);

class Movement
{
private:
    Int16 speedUp;
    Int16 speedDown;
    Int16 speedLeft;
    Int16 speedRight;

public:
    Movement()
            : speedUp(0), speedDown(0), speedLeft(0), speedRight(0)
    { }

    Int16 getHorizontalMovement()
    {
        return (speedRight - speedLeft) / nsGameConstants::SPEED_DIVISOR;
    }

    Int16 getVerticalMovement()
    {
        return (speedDown - speedUp) / nsGameConstants::SPEED_DIVISOR;
    }

    void update()
    {
        //Si on appuie sur Up, et que on est pas a max speed, on augmente, sinon on descend jusqu'a vitesse nulle
        if (sf::Keyboard::isKeyPressed(KBManager::getKey(KBManager::Up)) && speedUp < nsGameConstants::MAX_MOVEMENT_SPEED)
            ++speedUp;
        else if (speedUp > 0)
            --speedUp;

        if (sf::Keyboard::isKeyPressed(KBManager::getKey(KBManager::Down)) &&
            speedDown < nsGameConstants::MAX_MOVEMENT_SPEED)
            ++speedDown;
        else if (speedDown > 0)
            --speedDown;

        if (sf::Keyboard::isKeyPressed(KBManager::getKey(KBManager::Left)) &&
            speedLeft < nsGameConstants::MAX_MOVEMENT_SPEED)
            ++speedLeft;
        else if (speedLeft > 0)
            --speedLeft;

        if (sf::Keyboard::isKeyPressed(KBManager::getKey(KBManager::Right)) &&
            speedRight < nsGameConstants::MAX_MOVEMENT_SPEED)
            ++speedRight;
        else if (speedRight > 0)
            --speedRight;

    }
};


void TEST::FluiditeMovement ()
{
    KBManager::setKeyBind(KBManager::Up, sf::Keyboard::Key::Z);
    KBManager::setKeyBind(KBManager::Down, sf::Keyboard::Key::S);
    KBManager::setKeyBind(KBManager::Left, sf::Keyboard::Key::Q);
    KBManager::setKeyBind(KBManager::Right, sf::Keyboard::Key::D);

    sf::RenderWindow window(sf::VideoMode(1600, 900), "Test KeyBinds!");
    sf::CircleShape shape = sf::CircleShape(20, 3);
    shape.setFillColor(sf::Color::Red);

    Movement movement;

    const sf::Time timePerFrame = sf::seconds(1.f / 60.f); //60fps
    sf::Clock clock;

    while (window.isOpen())
    {
        clock.restart();

        sf::Event event;
        if (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        movement.update();
        Int16 newShapePosX = (Int16) shape.getPosition().x + movement.getHorizontalMovement();
        Int16 newShapePosY = (Int16) shape.getPosition().y + movement.getVerticalMovement();
        shape.setPosition(newShapePosX, newShapePosY);

        window.clear();
        window.draw(shape);
        window.display();

        while (clock.getElapsedTime() < timePerFrame)
            sf::sleep(sf::milliseconds(1));
    }
}

#undef TEST