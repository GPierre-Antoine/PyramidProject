//
// Created by Pierre-Antoine on 29/06/2015.
//

#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "../Utility/ListeCircu.hpp"
#include "RessourceManager.h"

namespace nsRessourceManager
{
    class Animator
    {
    protected:
        static sf::RenderWindow* window;
        sf::Vector2f position;
        bool moving;

    public:
        static void setWindow(sf::RenderWindow & window) noexcept;

        void setPosition(UInt16 x, UInt16 y);

        virtual bool isMoving() const noexcept;

        void setMoving(bool moving) noexcept;

        virtual void update() noexcept = 0;

        virtual void render() noexcept = 0;

        virtual ~Animator()
        { }
    };


    class PlayerAnimator : public Animator
    {
    private:
        const MTextures_t *textures;
        byte_t direction;
        //Compteur de tours de boucle
        UInt16 loopsCounter;

        nsUtility::ListeCircu<byte_t> * loopList;

    public:
        PlayerAnimator(KPair_t & character = BASIC);

        PlayerAnimator(const PlayerAnimator & animator);

        void changeLoop(byte_t newDirection) noexcept;

        virtual void update() noexcept;

        virtual void render() noexcept;

        virtual ~PlayerAnimator()
        { }
    };

}