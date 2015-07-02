//
// Created by Pierre-Antoine on 01/07/2015.
//

#ifndef PYRAMIDPROJECT_COLLIDER_H
#define PYRAMIDPROJECT_COLLIDER_H

#include <utility>
#include <SFML/System/Vector2.hpp>
#include "../Defines/typedef.hpp"

namespace nsGameEngine
{
    namespace nsCollider
    {
        template <typename T>

        class Collider
        {
        private:
            virtual bool                collidesV     (const Rectangle & other) const noexcept = 0;
            virtual bool                OtherfitsInto (const Rectangle & other) const noexcept = 0;

            virtual bool                collidesV     (const Circle    & other) const noexcept = 0;
            virtual bool                otherFitsInto (const Circle    & other) const noexcept = 0;
        protected:
        public:
            bool                        collides (const Collider & other) const noexcept;
            bool                        fitsInto (const Collider & other) const noexcept;

            virtual void move (const sf::Vector2<T> & mvt) noexcept = 0;
            virtual void move (const T & pX, const T & pY) noexcept = 0;


            virtual ~Collider (){}
        };

        template <typename T>
        class Rectangle : public Collider
        {
        private:
            friend class Circle;
            T                           width;
            T                           height;
            sf::Vector2<T>              origin;

            bool                        otherFitsInto (const Rectangle & other) const noexcept;
            bool                        collidesV     (const Rectangle & other) const noexcept;

            bool                        otherFitsInto (const Circle    & other) const noexcept;
            bool                        collidesV     (const Circle    & other) const noexcept;

        public:
            //Constructor
            Rectangle (const T & x, const T & y,     const T & width, const T & height) noexcept;
            Rectangle (const sf::Vector2<T>& origin, const T & width, const T & height) noexcept;

            virtual ~Rectangle () {}
        };




        template <typename T>
        class Circle : public Collider
        {
        protected:
        private:
            friend class Rectangle;
            T                           radius;
            sf::Vector2<T>              origin;

            bool otherFitsInto (const Rectangle & other) const noexcept;
            bool collidesV (const Rectangle & other) const noexcept;

            bool otherFitsInto (const Circle    & other) const noexcept;
            bool collidesV (const Circle    & other) const noexcept;

        public:
            Circle (const T & x, const T & y,      const T & radius) noexcept;
            Circle (const sf::Vector2<T> & origin, const T & radius) noexcept;

            virtual ~Circle () {}
        };

        typedef Collider    <UInt16>    ColliderUi;
        typedef Circle      <UInt16>    CircleUi;
        typedef Rectangle   <UInt16>    RectangleUi;


    }//nsCollider
}//nsGameEngine

#endif //PYRAMIDPROJECT_COLLIDER_H
