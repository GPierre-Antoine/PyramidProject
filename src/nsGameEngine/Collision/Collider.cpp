//
// Created by Pierre-Antoine on 01/07/2015.
//

#include "Collider.h"
#define COLL nsGameEngine::nsCollider
//Constructor
template <typename T>
COLL::Rectangle<T>::Rectangle (const T & X, const T & Y, const T & width, const T & height) noexcept : origin (sf::Vector2<T>(X,Y)), width (width), height (height)
{

}

template <typename T>
COLL::Rectangle<T>::Rectangle(const sf::Vector2<T> & orig, const T & width, const T & height) noexcept
        : origin (orig), width (width), height (height)
{

}


//visitor acceptation for collides
template <typename T>
bool  COLL::Collider<T>::collides (const Collider<T> & other) const noexcept
{
    return other.collidesV (*this);
}

//visitor acceptation for fitsInto
template <typename T>
bool  COLL::Collider<T>::fitsInto      (const Collider<T> & other) const noexcept
{
    return other.otherFitsInto (*this);
}

//rectangle vs rectangle
template <typename T>
bool COLL::Rectangle<T>::otherFitsInto (const Rectangle & other) const noexcept
{
    //other = appelant
    //this = appelé

    return  (this->origin.x <= other.origin.x) &&
            (this->origin.y <= other.origin.y) &&
            (this->origin.x + this->width >= other.origin.x + other.width ) &&
            (this->origin.y + this->height>= other.origin.y + other.height);
    //Appelant est DANS l'appelé, au sens strict.
}

//rectangle vs circle
template <typename T>
bool COLL::Rectangle<T>::otherFitsInto (const Circle<T> & other) const noexcept
{
    //other = appelant
    //this = appelé

    return  (this->origin.x + other.radius <= other.origin.x) &&
            (this->origin.y + other.radius <= other.origin.y) &&
            (this->origin.x + this->width - other.radius >= other.origin.x) &&
            (this->origin.y + this->width - other.radius >= other.origin.y);
    //Appelant (Rond) est dans l'Appelé (Rectangle).
}
template <typename T>
bool COLL::Circle<T>::otherFitsInto (const Rectangle<T> & other) const noexcept
{
    //other = appelant
    //this = appelé
    auto sqRadius = radius * radius; // keep radius² to avoid useless calcs
    auto middleX = (this->origin.x < other.origin.x) ?
                   other.origin.x - this->origin.x : this->origin.x - other.origin.x;
                   // Just to give it an explicit type;
    auto middleY = (this->origin.y < other.origin.y) ?
                   other.origin.y - this->origin.y : this->origin.y - other.origin.y;
    // Just to give it an explicit type;


    return  (middleX * middleX + middleY * middleY <= sqRadius) && // pythagore
    (middleX * middleX + (middleX + other.width)*(middleX + other.width) <= sqRadius) &&
    (middleY * middleY + (middleY + other.height)*(middleY + other.height) <= sqRadius) &&
    ((middleX + other.width)*(middleX + other.width) + (middleY + other.height)*
    (middleY + other.height) <= sqRadius); //formule mathématique. C'est chiant.
    //ça veut dire : pour chaque coin du rectangle,
    // ((x(rect) - x(cercle))² + (y(rect) - y(cercle))² <= rayon²).
    //amusant hein ?

    //Appelant (Rectangle) est dans l'Appelé (Cercle).
}
template <typename T>
bool COLL::Rectangle<T>::collidesV(const nsGameEngine::nsCollider::Rectangle<T> & other) const noexcept
{
    return false;
}

template <typename T>
bool COLL::Rectangle<T>::collidesV (const nsGameEngine::nsCollider::Circle<T> & other) const noexcept
{
    return false;
}

template <typename T>
bool COLL::Circle<T>::collidesV (const nsGameEngine::nsCollider::Rectangle<T> & other) const noexcept
{
    return false;
}

template <typename T>
bool COLL::Circle<T>::collidesV (const nsGameEngine::nsCollider::Circle<T> & other) const noexcept
{
    return false;
}

template <typename T>
COLL::Circle<T>::Circle (const T & x, const T & y, const T & radius) noexcept :
        origin (sf::Vector2<T>(x+radius,y+radius)), radius (radius)
{

}
template <typename T>
COLL::Circle<T>::Circle (const sf::Vector2<T> & origin, const T & radius) noexcept :
        origin (origin), radius (radius)
{
    this->origin.x+=radius;
    this->origin.y+=radius;
}

template <typename T>
bool COLL::Circle<T>::otherFitsInto(const nsGameEngine::nsCollider::Circle<T> & other) const noexcept
{
    return false;
}

#undef COLL
