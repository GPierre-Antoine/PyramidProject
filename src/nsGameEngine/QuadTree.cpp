//
// Created by Pierre-Antoine on 30/06/2015.
//
#include <iostream> //cerr

#include "SFML/System/Vector2.hpp"

#include "QuadTree.h"

#define GE nsGameEngine::QuadTree



#ifndef NDEBUG
#ifdef  DEBUG_QUADTREE_VISUAL
sf::RenderWindow  * GE::window { nullptr };
//fonction d'affichage du quadtree, pour le test.
void GE::render (sf::RenderWindow * renderWindow) const noexcept
{
    if (this->window == nullptr)
    {
        if (renderWindow != nullptr)
            window = renderWindow;
        else
            return;
    }

    sf::RectangleShape rect (sf::Vector2f(area.getWidth() - (level << 1) -1,area.getHeight () - (level << 1)-1));
    sf::Color c;
    switch (level)
    {
        case 0:
            c = (sf::Color::Red);

            break;
        case 1:
            c = (sf::Color::Blue);
            break;
        case 2:
            c = (sf::Color::Green);
            break;
        case 3:
            c = (sf::Color::Cyan);
            break;
        case 4:
            c = (sf::Color::Black);
            break;
        case 5:
            c = (sf::Color::Magenta);
            break;
        default:
            c = (sf::Color::Magenta);
    }

    rect.setFillColor (c);

    rect.setOutlineThickness (0u);

    rect.setPosition (area.getX()+level +1 ,area.getY()+level+1);

    window->draw(rect);
    if (splited)
    {
        for (auto & child : quad)
        {
            child->render();
        }
    }
}

void GE::forceSplit(int n /* = 1*/) noexcept
{
    if ((n--) && (level < maxLevel))
    {
        allocate ();
        for (auto & child : quad)
            child->forceSplit (n);
    }
}
#endif
#endif

GE::QuadTree (UInt16 pWidth,UInt16 pHeight) noexcept :
        level (0u), area (0,0,pWidth,pHeight), parent (nullptr) { }

GE::QuadTree (UInt16 pLevel,UInt16 pX, UInt16 pY,UInt16 pWidth, UInt16 pHeight, QuadTree & parent) noexcept :
        level (pLevel), area (pX,pY,pWidth,pHeight), parent (this)
{ }

GE::~QuadTree() { }

bool GE::contains (const sICollidable & go) const noexcept
{
    return this->area.contains(go->getCollider ());
}


/**
 * La fonction add prend en parametre un shared pointer vers un gameobject
 * et l'ajoute dans le quadtree, en vérifiant qu'il rentre bien dans son espace, sinon, redirige vers parent.
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
                                    //The use of prAdd NEEDS SECURITY : THIS->CONTAINS(go) MUST HAVE BEEN TESTED BEFORE
{
    if (splited)
    {
        size_t index {0};
        for (;(!quad[index]->contains (go)) && ++index < EQT::size ;);
                                    //donne à "index" la valeur du quadtree contenant go

        if (index == EQT::size)     //sentinelle, si l'objet n'est contenu que par *this
        {                           //when *this is splited and GO fits in *this, but not in sons.
            goList.push_back (go);
            return;
        }

        quad[index]->prAdd (go);    //sinon, on le met dynamiquement dans la cible adaptée
        return;                     //on arrête le déroulement de la fonction,
                                    //pour être sûr du bon déroulement de prAdd (pas deffets cumulés).
    }
    else
        goList.push_back (go);
                                    //unsplitted : on ne cherche pas à savoir si on a besoin de split ou pas,
                                    //update() se charge de repositionner les objets.
}


void GE::update () noexcept
{
    /*
     * La fonction update va être appelée à chaque update de l'état du jeu.
     * A chaque étape, il est important de vérifier :
     * - si ne contient aucun objet, détruire enfants.
     * - chaque objet de goList est il bien contenu dans *this, sinon on le met dans parent
     * - si l'objet est splited :
     * -- pour chaque enfant, l'objet entre t'il dans enfant ?
     * --- si oui : on l'ajoute à l'enfant, on l'enleve de *this et on casse la boucle
     * --- si non : on le laisse là où il est.
     * - sinon :
     * -- faut il split ?
     * --- si oui : on alloue les enfants, on update, et on termine la fonction.
     *
     *
     */


    if (splited)
    {


        if (this->size() - goList.size() == 0)
            deAllocate();
    }
    else // if (unsplited)
    {

    }

    for (std::vector<sICollidable>::reverse_iterator i {goList.rbegin ()} ; i != goList.rend () ; i = std::next (i))
    {
        // on vérifie si l'objet est entre dans *this
        if (!this->contains(*i))//s'il déborde
        {
            parent->add (*i);           //on le place dans le quadtree parent
            goList.erase (i.base ());   //on l'efface de *this
            continue;                   //on passe à l'objet suivant
        }

        // l'objet est bien contenu dans *this

        if (splited)                    // si *this est splited
        {
            for (auto & qt : quad)       //pour chaque enfant qt de *this
            {
                if (!qt->contains (*i)) //si l'enfant qt ne contient pas l'objet testé, on saute cette itération
                    continue;
                //sinon :
                qt->prAdd (*i); // on ajoute l'objet testé à qt en cours
                this->goList.erase(i.base()); // on efface l'objet du vecteur ce *this
                break;//on casse la boucle

            }
        }
        else if (goList.size() >= maxCapacity)// si *this n'est splited
        {
            if (level < maxLevel) //besoin de tester ici si peut spliter pour eviter boucle infinie
            {
                split (); //calls update
                return;
            }
        }
    }
}


//returns the size of a QuadTree, including those of eventual sons.
size_t GE::size () const noexcept
{
    if (splited)
        return goList.size () + quad[EQT::NE]->size () + quad[EQT::NW]->size () + quad[EQT::SE]->size () + quad[EQT::SW]->size ();
    return goList.size();
}


void GE::split () noexcept //needs test of level < levelMax BEFORE !
{
    allocate ();
    update   ();
}

void GE::allocate () noexcept
{
    this->splited = true;
    UInt16 x      {area.getX ()};
    UInt16 y      {area.getY ()};
    UInt16 width  {area.getWidth ()};
    UInt16 height {area.getHeight ()};

    //to replace with uniq_ptr of vector of quadtree.
    //std::array of quadtree !

    UInt16 __2 = 2; //to avoid comparison warning
    UInt16 __1 = 1; //to avoid comparison warning
    UInt16 ParityW = width  & __1; //to fix odd cases
    UInt16 ParityH = height & __1; //to fix odd cases
    //must make a private constructor taking : level, Rectangle, ref to parent.

    //QTptr is a QuadTree unique_ptr

    /*                                   level,     x origin,               y origin,               width,     height,     ref to parent*/
    quad[EQT::NW] = QTptr (new QuadTree(level + __1,x                     , y                      ,width/ __2,height/ __2,*this));
    quad[EQT::NE] = QTptr (new QuadTree(level + __1,x+ParityW +width/__2  , y                      ,width/ __2,height/ __2,*this));
    quad[EQT::SW] = QTptr (new QuadTree(level + __1,x                     , ParityH + y+height/ __2,width/ __2,height/ __2,*this));
    quad[EQT::SE] = QTptr (new QuadTree(level + __1,x+ParityW +width/__2  , ParityH + y+height/ __2,width/ __2,height/ __2,*this));
}

void GE::deAllocate () noexcept
{
    for (auto & uptr : quad)
        uptr.reset(nullptr);
    this->splited = false;

}


#undef  GE

size_t nsGameEngine::QuadTree::getByteCount () const noexcept
{
    if (splited)
    {
        size_t i {0};
        for (auto & child : quad)
            i+= child->getByteCount ();
        return (sizeof(*this) + i);
    }
    else
        return sizeof(*this);
}
