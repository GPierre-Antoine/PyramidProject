//
// Created by Pierre-Antoine on 01/07/2015.
//

#ifndef PYRAMIDPROJECT_COLLIDER_H
#define PYRAMIDPROJECT_COLLIDER_H

#include "../Movement.h"

typedef unsigned short int UInt16;

namespace nsGameEngine
{
    namespace nsCollider
    {

        //Forward Declaration
        class Rectangle;
        class Circle;

        class Collider
        {
        private:
        public:
            virtual bool isContainedByRectangle (const Rectangle & rect) const noexcept = 0;
            virtual bool collidesWith (const Collider & other) const noexcept = 0;
            //virtual void resize (int width, int height) noexcept = 0;
            // resize can't be generic
            virtual void move (int x, int y) noexcept = 0;
            virtual void move (Movement mv) noexcept;

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

            virtual void move (int x, int y) noexcept;
            void resize (int width, int height) noexcept;


            virtual ~Rectangle () { }

            UInt16 getX () const noexcept;
            UInt16 getY () const noexcept;

            UInt16 getWidth  () const noexcept;
            UInt16 getHeight () const noexcept;
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
            virtual bool collidesWith (const Rectangle & other) const noexcept;
            virtual bool isContainedByRectangle (const Rectangle & rect) const noexcept;

            virtual void move (int x, int y) noexcept;
            void resize (int radius) noexcept;

            Circle (UInt16 X, UInt16 Y, UInt16 RADIUS) noexcept;
            virtual ~Circle () { }


        };
    }//nsCollider
}//nsGameEngine


#endif //PYRAMIDPROJECT_COLLIDER_H
