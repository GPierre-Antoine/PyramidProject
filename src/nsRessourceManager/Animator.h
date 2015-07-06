//
// Created by Pierre-Antoine on 29/06/2015.
//

#ifndef PYRAMIDPROJECT_ANIMATOR_H
#define PYRAMIDPROJECT_ANIMATOR_H

#include <SFML/Graphics/Sprite.hpp>
#include "RessourceManager.h"

namespace nsRessourceManager
{
    class Animator
    {
    protected:
        static sf::RenderWindow* window;

        sf::Vector2f position;

    public:
        static void setWindow(sf::RenderWindow & window) noexcept;

        virtual void setPosition (UInt16 x, UInt16 y);

        virtual void update() noexcept;

        virtual void render() noexcept = 0;

        virtual ~Animator()
        { }
    };



    class PlayerAnimator : public Animator
    {
    private:
        const std::vector<sf::Texture>* textures;

        //Si faux, affiche l'image du milieu de notre currentLoop(celle sans mouvement)
        bool isMoving;

        UInt16 currentFacing;

        //Compteur de tours de boucle
        UInt16 loopsCounter;

    public:
        PlayerAnimator(const std::string & characterName = BASIC);
        PlayerAnimator(const PlayerAnimator & animator);

        virtual void update() noexcept;

        virtual void render() noexcept;

        virtual ~PlayerAnimator()
        { }
    };

}
#endif //PYRAMIDPROJECT_ANIMATOR_H
