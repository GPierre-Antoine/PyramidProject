//
// Created by Theo on 29/06/2015.
//

#ifndef PYRAMIDPROJECT_CHARACTER_H
#define PYRAMIDPROJECT_CHARACTER_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../nsRessourceManager/RessourceManager.h"
#include "Entity.h"

namespace nsGameObject
{
    class Character : public Entity
    {
    private:

        sf::Vector2f position;

    public:
        virtual void render() const noexcept = 0;

    };
}

#endif //PYRAMIDPROJECT_CHARACTER_H
