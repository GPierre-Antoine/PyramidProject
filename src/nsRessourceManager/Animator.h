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
        bool moving;

    public:
        static void setWindow(sf::RenderWindow & window) noexcept;

        void setPosition(UInt16 x, UInt16 y);

        virtual bool isMoving() const noexcept;

        void setMoving(bool moving) noexcept;

        virtual void update() noexcept = 0;

        virtual void render() const noexcept = 0;

        virtual ~Animator()
        { }
    };


    class PlayerAnimator : public Animator
    {
    private:
        const std::vector<sf::Texture>* textures;
        mutable UInt16 currentLoop;
        //Compteur de tours de boucle
        mutable UInt16 loopsCounter;

    public:
        PlayerAnimator(const std::string & characterName = BASIC);

        PlayerAnimator(const PlayerAnimator & animator);

        void changeLoop(UInt16 loopConstant) noexcept;

        virtual void update() noexcept;

        virtual void render() const noexcept;

        virtual ~PlayerAnimator()
        { }
    };

}
#endif //PYRAMIDPROJECT_ANIMATOR_H
