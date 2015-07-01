//
// Created by Pierre-Antoine on 01/07/2015.
//

#ifndef PYRAMIDPROJECT_COLLIDER_H
#define PYRAMIDPROJECT_COLLIDER_H

#include <utility>
#include "../Defines/typedef.hpp"

namespace nsGameEngine
{
    namespace nsCollider
    {

        namespace
        {
            bool isBetween (UInt16 Middler, UInt16 First, UInt16 Second);

            enum EType
            {
                RECTANGLE,
                CIRCLE
            };
        }

        template <typename T>

        class Collider
        {
        protected:
            EType type;
            std::pair<T,T> origin;
        public:
            virtual bool                collides (const Collider & other) const noexcept = 0;
            virtual bool                fitsInto (const Collider & other) const noexcept = 0;
            virtual bool                contains (T x, T y) const noexcept = 0;

            virtual ~Collider (){}
        };

        template <typename T>
        class Rectangle : public Collider
        {
        protected:
        private:
            T                           width;
            T                           height;



        public:
            virtual bool                collides (const Collider & other) const noexcept;
            virtual bool                fitsInto (const Collider & other) const noexcept;
            virtual bool                contains (const std::pair<T,T> & point) const noexcept;

        };

        template <typename T>
        class Circle : public Collider
        {
        protected:
        private:
            T                           radius;

        public:
            virtual bool                collides (const Collider & other) const noexcept;
            virtual bool                fitsInto (const Collider & other) const noexcept;
            virtual bool                contains (T x, T y) const noexcept;

        };

        typedef Collider    <UInt16>    Collider;
        typedef Circle      <UInt16>    Circle;
        typedef Rectangle   <UInt16>    Rectangle;


    }
}

#endif //PYRAMIDPROJECT_COLLIDER_H
