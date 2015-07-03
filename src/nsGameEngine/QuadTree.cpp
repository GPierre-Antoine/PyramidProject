//
// Created by Pierre-Antoine on 30/06/2015.
//

#include <iostream> //cerr
#include "QuadTree.h"

#define GE nsGameEngine::QuadTree


GE::QuadTree (UInt16 pWidth,UInt16 pHeight) noexcept : level (0u), area (0,0,pWidth,pHeight), parent (nullptr) { }

GE::QuadTree (UInt16 pLevel,UInt16 pX, UInt16 pY,UInt16 pWidth, UInt16 pHeight, QuadTree & parent) noexcept :
        level (pLevel),x(pX),y(pY),width{pWidth},height{pHeight}, area (pX,pY,pWidth,pHeight), parent (this)
{ }

GE::~QuadTree()
{
    if (splited)
        delete NW, NE, SW, SE;
}

bool GE::fits (nsGameEngine::QuadTree *Child, sICollidable & go) const noexcept
{
    return Child->area.fitsInto (go->getCollider ());
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
        if (goList.size () - numberOfUnfittingCollider >= maxCapacity)
        {
            split ();
            prAdd (go);
            update ();
            return;
        }
        else
        {
            goList.push_back (go);
        }
    }

}


void GE::update () noexcept
{
    for (std::vector<sICollidable>::reverse_iterator i {goList.rbegin ()} ; i != goList.rend () ; i = std::next (i))
    {
        if (!fits (this, *i))
        {
            goList.erase (i.base ());
        }
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
        UInt16 __2 = 0x0002; //to avoid comparison warning
        UInt16 __1 = 0x0001; //to avoid comparison warning
        UInt16 ParityW = width  & __1; //to fix odd cases
        UInt16 ParityH = height & __1; //to fix odd cases
        NW = new QuadTree(level + __1,x+width/__2, y,width/ __2,  height/ __2,          *this);
        NE = new QuadTree(level + __1,x+ParityW,y,            width/ __2,height/ __2,   *this);
        SW = new QuadTree(level + __1,x,ParityH + y+height/ __2,width/ __2,height/ __2, *this);
        SE = new QuadTree(level + __1,x+ParityW + width/ __2,ParityH + y+height/ __2,width/ __2,height/ __2,   *this);

    }// creation of subQuadTree with fake empty row (change if float.)
    catch (std::bad_alloc & e)
    {
        std::cerr << "bad_alloc caught: " << e.what() << std::endl;
    }

}

#undef  GE
