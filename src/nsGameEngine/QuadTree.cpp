//
// Created by Pierre-Antoine on 30/06/2015.
//

#include "QuadTree.h"
#define GE nsGameEngine::QuadTree

typedef std::shared_ptr<nsGameObject::GameObject> sGameObject;
typedef unsigned short int UInt16;



GE::QuadTree (UInt16 pWidth,UInt16 pHeight) noexcept : level (0u), x (0u), y (0u), width (pWidth), height (pHeight)
{

}

GE::QuadTree (UInt16 pLevel,UInt16 pX, UInt16 pY,UInt16 pWidth, UInt16 pHeight) noexcept : level (pLevel), x (pX), y (pY), width (pWidth), height (pHeight)
{

}

GE::~QuadTree()
{
    delete NW, NE, SW, SE;
}

bool GE::fits (nsGameEngine::QuadTree *Child, sGameObject & go) const
{
    return (go->X() < 0) || (width < go->X()) || (go->Y() < 0) || (height < go->Y());
}


/**
 * La fonction add prend en parametre un shared pointer vers un gameobject
 * et l'ajoute dans le quadtree, en vérifiant qu'il rentre bien dans son espace
 * appelle ensuite la fonction private add, qui effectue la même chose sans vérifier
 * (contrôle entrée utilisateur)
 */
void GE::add(sGameObject& go) noexcept
{
    if (fits(this,go))
        prAdd (go);
}

void GE::prAdd(sGameObject& go) noexcept
{

}

unsigned long long int GE::size ()
{
    if (splited)
        return goList.size () + NE->size () + NW->size () + SE->size () + SW->size ();
    return goList.size();
}


#undef  GE