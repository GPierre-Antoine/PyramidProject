//
// Created by Theo on 09/07/2015.
//

#include "KBManager.h"

using namespace std;

#define KB nsRessourceManager::KBManager

vector<sf::Keyboard::Key> KB::keyBinds(KB::Count);


sf::Keyboard::Key KB::getKey(Action action) noexcept
{
    return keyBinds[action];
}

void KB::setKeyBind(Action action, sf::Keyboard::Key key) noexcept
{
    keyBinds[action] = key;
}