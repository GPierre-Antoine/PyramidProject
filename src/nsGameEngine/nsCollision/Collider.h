//
// Created by Pierre-Antoine on 01/07/2015.
//

#ifndef PYRAMIDPROJECT_COLLIDER_H
#define PYRAMIDPROJECT_COLLIDER_H

#include <SFML/System/Vector2.hpp>
#include "../Defines/typedef.hpp"


namespace nsGameEngine
{
    namespace nsCollider
    {


        class Rectangle;

        class Collider
        {
        public:
            virtual bool isContainedByRectangle (const Rectangle & rect) const noexcept = 0;
            virtual ~Collider () { }
        };

        class Rectangle : public Collider
        {
        private:
            UInt16 x;
            UInt16 y;
            UInt16 width;
            UInt16 height;
        public:
            bool contains (const Collider & col) const noexcept;
            virtual bool isContainedByRectangle (const Rectangle & rect) const noexcept;
            Rectangle (const UInt16 X, const UInt16 Y, const UInt16 WIDTH, const UInt16 HEIGHT) noexcept;

            const UInt16 getWidth  () const noexcept;
            const UInt16 getHeight () const noexcept;
            const UInt16 getX      () const noexcept;
            const UInt16 getY      () const noexcept;
            virtual ~Rectangle () { }
        };

        class Circle : public Collider
        {
        private:
            UInt16 x;
            UInt16 y;
            UInt16 radius;
        public:
            virtual bool isContainedByRectangle (const Rectangle & rect) const noexcept;
            Circle (UInt16 X, UInt16 Y, UInt16 RADIUS) noexcept;
            const UInt16 getX    () const noexcept;
            const UInt16 getY    () const noexcept;
            const UInt16 getRad  () const noexcept;
            virtual ~Circle () { }
        };
    }//nsCollider
}//nsGameEngine


#endif //PYRAMIDPROJECT_COLLIDER_H
