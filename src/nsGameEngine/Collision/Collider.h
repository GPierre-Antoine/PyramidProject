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
            class Collider;
            template <typename T>
            class Rectangle;
            template <typename T>
            class Circle;

            template <typename T>
            class Collider
            {
            private:
                virtual bool                collidesV       (const Rectangle<T> & other) const noexcept = 0;
                virtual bool                OtherfitsInto   (const Rectangle<T> & other) const noexcept = 0;

                virtual bool                collidesV       (const Circle<T>    & other) const noexcept = 0;
                virtual bool                otherFitsInto   (const Circle<T>    & other) const noexcept = 0;
            public:
                bool                        collides        (const Collider<T> & other) const noexcept;
                bool                        fitsInto        (const Collider<T> & other) const noexcept;
                virtual void move (const sf::Vector2<T> & mvt) noexcept = 0;
                virtual void move (const T & pX, const T & pY) noexcept = 0;


                virtual ~Collider (){}
            };

            template <typename T>
            class Rectangle : public Collider<T>
            {
            private:
                friend class Circle<T>;
                T                           width;
                T                           height;
                sf::Vector2<T>              origin;

                virtual bool                otherFitsInto   (const Rectangle<T> & other) const noexcept;
                virtual bool                collidesV       (const Rectangle<T> & other) const noexcept;

                virtual bool                otherFitsInto   (const Circle<T>    & other) const noexcept;
                virtual bool                collidesV       (const Circle<T>    & other) const noexcept;

            public:
                //Constructor
                Rectangle (const T & x, const T & y,        const T & width, const T & height) noexcept;
                Rectangle (const sf::Vector2<T>& origin,    const T & width, const T & height) noexcept;

                virtual ~Rectangle () {}
            };




            template <typename T>
            class Circle : public Collider<T>
            {
            private:
                friend class Rectangle<T>;
                T                                           radius;
                sf::Vector2<T>                              origin;

                virtual bool otherFitsInto                  (const Rectangle<T> & other) const noexcept;
                virtual bool collidesV                      (const Rectangle<T> & other) const noexcept;

                virtual bool otherFitsInto                  (const Circle<T>    & other) const noexcept;
                virtual bool collidesV                      (const Circle<T>    & other) const noexcept;

            public:
                //Constructor
                Circle (const T & x, const T & y,      const T & radius) noexcept;
                Circle (const sf::Vector2<T> & origin, const T & radius) noexcept;

                virtual ~Circle () {}
            };

            typedef Collider    <UInt16>    ColliderUI;
            typedef Circle      <UInt16>    CircleUI;
            typedef Rectangle   <UInt16>    RectangleUI;
        }//nsCollider
    }//nsGameEngine

    #endif //PYRAMIDPROJECT_COLLIDER_H
