//
// Created by Pierre-Antoine on 30/06/2015.
//

#include <iostream> //cerr

#include "SFML/System/Vector2.hpp"

#include "QuadTree.h"

#define GE nsGameEngine::QuadTree


#ifndef NDEBUG

sf::RenderWindow  * GE::window { nullptr };
//fonction d'affichage du quadtree, pour le test.
void nsGameEngine::QuadTree::render (sf::RenderWindow * renderWindow) const noexcept
{
    if (this->window == nullptr)
    {
        if (renderWindow != nullptr)
            window = renderWindow;
        else
            return;
    }

    sf::RectangleShape rect (sf::Vector2f(area.Width(),area.Height ()));

    rect.setOutlineColor (sf::Color::Red);
    rect.setOutlineThickness (2u);

    rect.setPosition (area.X(),area.Y());

    window->draw(rect);
}

#endif

GE::QuadTree (UInt16 pWidth,UInt16 pHeight) noexcept :
        level (0u), area (0,0,pWidth,pHeight), parent (nullptr) { }

GE::QuadTree (UInt16 pLevel,UInt16 pX, UInt16 pY,UInt16 pWidth, UInt16 pHeight, QuadTree & parent) noexcept :
        level (pLevel), area (pX,pY,pWidth,pHeight), parent (this)
{ }

GE::~QuadTree()
{
    if (splited)
        delete NW, NE, SW, SE;
}

bool GE::contains (const sICollidable & go) const noexcept
{
    return this->area.contains(go->getCollider ());
}


/**
 * La fonction add prend en parametre un shared pointer vers un gameobject
 * et l'ajoute dans le quadtree, en vérifiant qu'il rentre bien dans son espace
 * appelle ensuite la fonction private add, qui effectue la même chose sans vérifier
 * (contrôle entrée utilisateur)
 */
void GE::add(sICollidable & go) noexcept
{
    if (!this->contains(go))
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
// The use of prAdd NEEDS SECURITY : THIS->CONTAINS(go) MUST HAVE BEEN TESTED BEFORE
{
    if (splited)
    {
        if (NE->contains (go))
        {
            NE->prAdd (go);
        }
        else if (NW->contains (go))
        {
            NW->prAdd (go);
        }
        else if (SE->contains (go))
        {
            SE->prAdd (go);
        }
        else if (SW->contains (go))
        {
            SW->prAdd (go);
        }
        else
        {//when *this is splited and GO fits in *this, but not in sons.
            goList.push_back (go);
            numberOfUnfittingCollider +=1;
        }
    }
    else //unsplitted
    {
        if (goList.size () - numberOfUnfittingCollider >= maxCapacity) //need to split
        {
            split ();
            prAdd (go);
            update ();
            return;
        }
        else //no need to split
        {
            goList.push_back (go);
        }
    }

}


void GE::update () noexcept
{
    for (std::vector<sICollidable>::reverse_iterator i {goList.rbegin ()} ; i != goList.rend () ; i = std::next (i))
    {
        //on vérifie si l'objet ne déborde pas du réctangle du quadtree
        //s'il déborde, on le place dans le quadtree parent
        if (!this->contains(*i))
        {
            sICollidable t = *i;
            goList.erase (i.base ());
            parent->add (t);
        }
        else // l'objet est bien contenu dans *this
        {
            if (!splited) // si *this n'est splited
            {

            }
            else // si *this est splited
            {
                QuadTree *target = nullptr;
                if (NW->contains (*i))//si le gameobject rentre dans un des enfants
                    target = NW;
                else if (NE->contains (*i))
                    target = NE;
                else if (SW->contains (*i))
                    target = SW;
                else if (SE->contains (*i))
                    target = SE;

                if (target != nullptr) //on le met dans l'enfant en question et on le supprime de *this
                {
                    target->prAdd (*i);
                    goList.erase(i.base());
                }
            }

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
        UInt16 x      {area.X ()};
        UInt16 y      {area.Y ()};
        UInt16 width  {area.Width ()};
        UInt16 height {area.Height ()};

        UInt16 __2 = 2; //to avoid comparison warning
        UInt16 __1 = 1; //to avoid comparison warning
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
