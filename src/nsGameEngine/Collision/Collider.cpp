//
// Created by Pierre-Antoine on 01/07/2015.
//

#include "Collider.h"
#define COLL nsGameEngine::nsCollider
//Constructor
template <typename T>
COLL::Rectangle::Rectangle(const T & X, const T & Y, const T & width, const T & height) noexcept
: origin (sf::Vector2<T>(X,Y)), width (width), height (height)
{

}

template <typename T>
COLL::Rectangle::Rectangle(const sf::Vector2<T> & orig, const T & width, const T & height) noexcept
        : origin (orig), width (width), height (height)
{

}


//visitor acceptation for collides
bool  COLL::Collider::collides (const Collider & other) const noexcept
{
    return other.collidesV (auto (*this));
}

//visitor acceptation for fitsInto
bool  COLL::Collider::fitsInto      (const Collider & other) const noexcept
{
    return other.otherFitsInto (auto (*this));
}

//rectangle vs rectangle
bool COLL::Rectangle::otherFitsInto (const Rectangle & other) const noexcept
{
    //other = appelant
    //this = appel�

    return  (this->origin.x <= other.origin.x) &&
            (this->origin.y <= other.origin.y) &&
            (this->origin.x + this->width >= other.origin.x + other.width ) &&
            (this->origin.y + this->height>= other.origin.y + other.height);
    //Appelant est DANS l'appel�, au sens strict.
}

//rectangle vs circle
bool COLL::Rectangle::otherFitsInto (const Circle & other) const noexcept
{
    //other = appelant
    //this = appel�

    return  (this->origin.x + other.radius <= other.origin.x) &&
            (this->origin.y + other.radius <= other.origin.y) &&
            (this->origin.x + this->width - other.radius >= other.origin.x) &&
            (this->origin.y + this->width - other.radius >= other.origin.y);
    //Appelant (Rond) est dans l'Appel� (Rectangle).
}

bool COLL::Circle::otherFitsInto (const Rectangle & other) const noexcept
{
    //other = appelant
    //this = appel�
    auto sqRadius = radius * radius; // keep radius� to avoid useless calcs
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
    (middleY + other.height) <= sqRadius); //formule math�matique. C'est chiant.
    //�a veut dire : pour chaque coin du rectangle,
    // ((x(rect) - x(cercle))� + (y(rect) - y(cercle))� <= rayon�).
    //amusant hein ?

    //Appelant (Rectangle) est dans l'Appel� (Cercle).
}

bool COLL::Circle::otherFitsInto (const Circle & other) const noexcept
{
    auto middleX = (this->origin.x < other.origin.x) ?
                   other.origin.x - this->origin.x : this->origin.x - other.origin.x;
    // Just to give it an explicit type;
    auto middleY = (this->origin.y < other.origin.y) ?
                   other.origin.y - this->origin.y : this->origin.y - other.origin.y;
    auto sqRadius = this->radius * this->radius; // keep radius� to avoid useless calcs


    return false;
}
bool COLL::Rectangle::collidesV(const nsGameEngine::nsCollider::Rectangle & other) const
{
    return false;
}

bool COLL::Rectangle::collidesV (const nsGameEngine::nsCollider::Circle & other) const
{
    return false;
}

bool COLL::Circle::collidesV (const nsGameEngine::nsCollider::Rectangle & other) const
{
    return false;
}

bool COLL::Circle::collidesV (const nsGameEngine::nsCollider::Circle & other) const
{
    return false;
}

template <typename T>
COLL::Circle<T>::Circle (const T & x, const T & y, const T & radius) :
        origin (sf::Vector2(x+radius,y+radius)), radius (radius)
{

}
template <typename T>
COLL::Circle<T>::Circle (const sf::Vector2<T> & origin, const T & radius) :
        origin (origin), radius (radius)
{
    this->origin.x+=radius;
    this->origin.y+=radius;
}

#undef COLL