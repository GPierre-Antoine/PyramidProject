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
        template <typename T>
        class Rectangle;

        template <typename B>
        B add (const B & a, const B & b)
        {
            return a + b;
        }

        template <typename T>
        class Collider
        {
        public:
            //bool accept (const Visitor & vis) const noexcept;
            virtual bool isContainedByRectangle (const Rectangle<T> & rect) const noexcept = 0;
            virtual ~Collider () { }
        };

        template <typename T>
        class Rectangle : public Collider<T>
        {
        private:
            T x;
            T y;
            T width;
            T height;
        public:
            bool contains (const Collider<T> & col) const noexcept;
            virtual bool isContainedByRectangle (const Rectangle<T> & rect) const noexcept;
            Rectangle (const T X, const T Y, const T WIDTH, const T HEIGHT) noexcept;

            const T getWidth  () const noexcept;
            const T getHeight () const noexcept;
            const T getX      () const noexcept;
            const T getY      () const noexcept;
            virtual ~Rectangle () { }
        };

        template <typename T>
        class Circle : public Collider<T>
        {
        private:
            T x;
            T y;
            T radius;
        public:
            virtual bool isContainedByRectangle (const Rectangle<T> & rect) const noexcept;
            Circle (T X, T Y, T RADIUS) noexcept;
            const T getX    () const noexcept;
            const T getY    () const noexcept;
            const T getRad  () const noexcept;
            virtual ~Circle () { }
        };


        typedef Collider    <UInt16>    ColliderUI;
        typedef Circle      <UInt16>    CircleUI;
        typedef Rectangle   <UInt16>    RectangleUI;
    }//nsCollider
}//nsGameEngine


#endif //PYRAMIDPROJECT_COLLIDER_H
