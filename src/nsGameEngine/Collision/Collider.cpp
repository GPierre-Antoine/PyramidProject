//
// Created by Pierre-Antoine on 01/07/2015.
//

#include "Collider.h"
#define COLL nsGameEngine::nsCollider

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
    //Appelant (Rond) est dans l'Appelé (Rectangle).
}

bool COLL::Circle::otherFitsInto (const Rectangle & other) const noexcept
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

bool COLL::Circle::otherFitsInto (const Circle & other) const noexcept
{
    auto middleX = (this->origin.x < other.origin.x) ?
                   other.origin.x - this->origin.x : this->origin.x - other.origin.x;
    // Just to give it an explicit type;
    auto middleY = (this->origin.y < other.origin.y) ?
                   other.origin.y - this->origin.y : this->origin.y - other.origin.y;
    auto sqRadius = this->radius * this->radius; // keep radius² to avoid useless calcs

    return false;
}
#undef COLL