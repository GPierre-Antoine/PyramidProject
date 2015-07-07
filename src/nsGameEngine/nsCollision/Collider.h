//
// Created by Pierre-Antoine on 01/07/2015.
//

#ifndef PYRAMIDPROJECT_COLLIDER_H
#define PYRAMIDPROJECT_COLLIDER_H

typedef unsigned short int UInt16;

namespace nsGameEngine
{
    namespace nsCollider
    {


        class Rectangle;
        class Circle;

        class Collider
        {
        private:
        public:
            virtual bool isContainedByRectangle (const Rectangle & rect) const noexcept = 0;
            virtual bool collidesWith (const Collider & other) const noexcept = 0;
            virtual ~Collider () { }
        };

        class Rectangle : public Collider
        {
            friend class Circle;
        private:
            UInt16 x;
            UInt16 y;
            UInt16 width;
            UInt16 height;
        public:
            virtual bool collidesWith (const Collider & other) const noexcept;
            virtual bool collidesWith (const Circle & other) const noexcept;
            virtual bool collidesWith (const Rectangle & other) const noexcept;
            bool contains (const Collider & col) const noexcept;
            virtual bool isContainedByRectangle (const Rectangle & rect) const noexcept;

            Rectangle (const UInt16 X, const UInt16 Y, const UInt16 WIDTH, const UInt16 HEIGHT) noexcept;

            virtual ~Rectangle () { }
        };

        class Circle : public Collider
        {
            friend class Rectangle;
        private:
            UInt16 x;
            UInt16 y;
            UInt16 radius;
        public:
            virtual bool collidesWith (const Collider & other) const noexcept;
            virtual bool collidesWith (const Circle & other) const noexcept;
            virtual bool collidesWith (const Rectangle & other) const noexcept;            virtual bool isContainedByRectangle (const Rectangle & rect) const noexcept;
            Circle (UInt16 X, UInt16 Y, UInt16 RADIUS) noexcept;
            virtual ~Circle () { }
        };
    }//nsCollider
}//nsGameEngine


#endif //PYRAMIDPROJECT_COLLIDER_H
