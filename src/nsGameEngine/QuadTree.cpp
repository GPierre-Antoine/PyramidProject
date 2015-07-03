//
// Created by Pierre-Antoine on 30/06/2015.
//

#include "QuadTree.h"

#define GE nsGameEngine::QuadTree


GE::QuadTree (UInt16 pWidth,UInt16 pHeight) noexcept : level (0u), area (0,0,pWidth,pHeight), parent (nullptr) { }

GE::QuadTree (UInt16 pLevel,UInt16 pX, UInt16 pY,UInt16 pWidth, UInt16 pHeight, QuadTree & parent) noexcept :
        level (pLevel),origin{sf::Vector2<UInt16>(pX,pY)},width{pWidth},height{pHeight}, area (pX,pY,pWidth,pHeight), parent (this)
{ }

GE::~QuadTree()
{
    if (splited)
        delete NW, NE, SW, SE;
}

bool GE::fits (nsGameEngine::QuadTree *Child, sICollidable & go) const noexcept
{
    return area.fitsInto (go->getCollider ());
}


/**
 * La fonction add prend en parametre un shared pointer vers un gameobject
 * et l'ajoute dans le quadtree, en vérifiant qu'il rentre bien dans son espace
 * appelle ensuite la fonction private add, qui effectue la même chose sans vérifier
 * (contrôle entrée utilisateur)
 */
void GE::add(sICollidable & go) noexcept
{
    if (!fits(this,go))
    {
        if (parent != nullptr)
            parent->add (go);
        //else
            //throw tu_fais_de_la_merde
    }
    else
        prAdd (go);
}

void GE::prAdd(sICollidable & go) noexcept
{
    if (splited)
    {
        if (fits (NE,go))
        {
            NE->prAdd (go);
        }
        else if (fits(NW,go))
        {
            NW->prAdd (go);
        }
        else if (fits(SE,go))
        {
            SE->prAdd (go);
        }
        else if (fits(SW,go))
        {
            SW->prAdd (go);
        }
        else
        {//when *this is splited and GO fits in *this, but not in sons.
            goList.push_back (go);
            numberOfUnfittingCollider +=1;
        }
    }
    else
    {

    }

}

size_t GE::size () const noexcept
{//a refaire
    if (splited)
        return goList.size () + NE->size () + NW->size () + SE->size () + SW->size ();
    return goList.size();
}

void GE::split () noexcept
{
    if (this->level == maxLevel)
        return;
    this->splited = true;
    try
    {
        NE = new QuadTree(level +1,,,,,*this);
    }

}

#undef  GE
