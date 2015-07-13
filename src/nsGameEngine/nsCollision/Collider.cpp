//
// Created by Pierre-Antoine on 05/07/2015.
//

#include "Collider.h"
#define COLL nsGameEngine::nsCollider

namespace
{
    UInt16 Uabs (int expr) { if (expr < 0) return UInt16(-expr);
        return UInt16(expr); };
}

void COLL::Collider::move (nsGameEngine::Movement mv) noexcept
{
    move (int (mv.getHorizontalMovement ()),int (mv.getVerticalMovement ()));
}

/* Mirrored Definitions */
bool COLL::Rectangle::contains (const COLL::Collider & col) const noexcept
{
    return col.isContainedByRectangle (*this);
}

/* Do Object fit in QuadTree N */
bool COLL::Circle::isContainedByRectangle (const COLL::Rectangle & rect) const noexcept
{
    return (rect.x <= x) && (x + (radius << 1) <= rect.x + rect.width ) &&
           (rect.y <= y) && (y + (radius << 1) <= rect.y + rect.height);
}

bool COLL::Rectangle::isContainedByRectangle (const COLL::Rectangle & rect) const noexcept
{
    return (rect.x <= this->x) && (this->x + this->width <= rect.x + rect.width)
           && (rect.y <= this->y) && (this->y + this->height <= rect.y + rect.height);
}


/* Constructors */
COLL::Rectangle::Rectangle (const UInt16 X,const UInt16 Y,const UInt16 WIDTH,const UInt16 HEIGHT) noexcept :
        x (X), y (Y), width (WIDTH), height (HEIGHT)
{

}

COLL::Circle::Circle (const UInt16 X, const UInt16 Y, const UInt16 RADIUS) noexcept:
        x (X), y (Y), radius (RADIUS)
{

}

/**/
bool COLL::Rectangle::collidesWith (const COLL::Circle & other) const noexcept
{
    //toutes les distances sont multipliées par 2 pour éviter de diviser certaines
    UInt16 circleDistancex = Uabs(((other.x + other.radius) << 1) - ((x << 1) + width ));
    UInt16 circleDistancey = Uabs(((other.y + other.radius) << 1) - ((y << 1) + height));

    if ((circleDistancex > (width + (other.radius << 1))) || (circleDistancey > (height + (other.radius << 1))))
        return false;

    if ((circleDistancex <= (width)) || (circleDistancey <= (height)))
        return true;

    UInt16 t1 = Uabs(circleDistancex - width);
    t1 = t1 * t1;
    UInt16 t2 = Uabs(circleDistancey - height);
    t2 = t2 * t2;
    t1 += t2;

    return (t1 <= (other.radius * other.radius) << 1);
}

void COLL::Rectangle::move(int x, int y) noexcept
{
    this->x+= x;
    this->y+= y;
}

void COLL::Rectangle::resize (int width, int height) noexcept
{
    this->width += width;
    this->height += height;
}

void COLL::Circle::move(int x, int y) noexcept
{
    this->x+= x;
    this->y+= y;
}

void COLL::Circle::resize (int radis) noexcept
{
    this->radius+= radius;
}

//centre x du cercle : x + radius
//centre y du cercle : y + radius

bool COLL::Rectangle::collidesWith (const COLL::Rectangle & other) const noexcept
{
    return  !((other.x >= this->x + this->width) ||
            (other.x + other.width <= x) ||
            (other.y >= y + height) ||
            (other.y + other.height <= y));/**/
}


//signature needed functions
bool COLL::Rectangle::collidesWith (const nsGameEngine::nsCollider::Collider & other) const noexcept
{
    return false;
}

bool COLL::Circle::collidesWith (const nsGameEngine::nsCollider::Collider & other) const noexcept
{
    return false;
}

//circle vs Circle
bool COLL::Circle::collidesWith (const nsGameEngine::nsCollider::Circle & other) const noexcept
{
    UInt16 dx = (x < other.x ? other.x - x : x - other.x); //abs(x - other.x)
    UInt16 dy = (y < other.y ? other.y - y : y - other.y); //abs(y - other.y)
    UInt16 radii = radius + other.radius;
    return (dx * dx + dy * dy <= radii * radii);//pythagore
}

//avoid duplicates
bool COLL::Circle::collidesWith (const nsGameEngine::nsCollider::Rectangle & other) const noexcept
{
    return other.collidesWith (*this);
}

#undef COLL


