//
// Created by Theo on 29/06/2015.
//

#ifndef PYRAMIDPROJECT_CHARACTER_H
#define PYRAMIDPROJECT_CHARACTER_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameObject.h"
#include "RessourceManager.h"

namespace nsGameObject
{
    class Character : public GameObject
    {
    private:

        sf::Vector2f position;

    public:
        virtual void render() noexcept;

    };
}

#endif //PYRAMIDPROJECT_CHARACTER_H
