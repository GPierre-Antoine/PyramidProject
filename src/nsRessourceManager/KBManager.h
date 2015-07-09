//
// Created by Theo on 09/07/2015.
//

#ifndef PYRAMIDPROJECT_KBMANAGER_H
#define PYRAMIDPROJECT_KBMANAGER_H

#include "../nsGameEngine/Defines/typedef.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <vector>


namespace nsRessourceManager
{
    class KBManager
    {
    public:
        enum Action
        {
            Up = 0,
            Down = 1,
            Left = 2,
            Right = 3,

            Count = 4
        }; //Action

        static std::vector<sf::Keyboard::Key> keyBinds;

        static sf::Keyboard::Key getKey(Action action) noexcept;

        static void setKeyBind(Action action, sf::Keyboard::Key key) noexcept;

    };//KBManager

}//nsRessourceManager


#endif //PYRAMIDPROJECT_KBMANAGER_H
