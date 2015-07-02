//
// Created by Pierre-Antoine on 01/07/2015.
//

#include "Collider.h"
#define COLL nsGameEngine::nsCollider

//visitor acceptation for collides
bool  COLL::Collider::collides (const Collider & other) const noexcept
{
    return other.collidesV (*this);
}
//visitor acceptation for fitsInto
bool  COLL::Collider::fitsInto      (const Collider & other) const noexcept
{
    return other.otherFitsInto (*this);
}

//rectangle vs rectangle
bool COLL::Rectangle::otherFitsInto (const Rectangle & other) const noexcept
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
bool COLL::Rectangle::otherFitsInto (const Circle & other) const noexcept
{
    //other = appelant
    //this = appelé

    return  (this->origin.x + other.radius <= other.origin.x) &&
            (this->origin.y + other.radius <= other.origin.y) &&
            (this->origin.x + this->width - other.radius >= other.origin.x) &&
            (this->origin.y + this->width - other.radius >= other.origin.y);
    //Appelant (Rond) est dans le Appelé (Rectangle).
}

bool COLL::Circle::otherFitsInto (const Rectangle & other) const noexcept
{
    //other = appelant
    //this = appelé

    return false;
    //Appelant (Rond) est dans le Appelé (Rectangle).
}

#undef COLL