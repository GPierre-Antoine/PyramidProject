//
// Created by Pierre-Antoine on 30/06/2015.
//

#ifndef PYRAMIDPROJECT_QUADTREE_H
#define PYRAMIDPROJECT_QUADTREE_H

#include <memory> //shared pointer
#include "../nsGameObject/GameObject.h"
#include "../nsGameObject/Interface.h"

#include "SFML/Graphics/renderWindow.hpp"

#include "Defines/typedef.hpp"

namespace nsGameEngine
{
    typedef std::shared_ptr<nsGameObject::ICollidable> sICollidable;


    class QuadTree
    {
    private:
        UInt16 level;
        static const unsigned short maxLevel {12};
        //le quadtree aura 12 noeuds au plus.
        static const unsigned short maxCapacity  {5};
        byte_t  numberOfUnfittingCollider {0};



        nsCollider::Rectangle area;
        bool splited {false};
        /** /
        QuadTree *childs; /**/
        QuadTree *NW;
        QuadTree *NE;
        QuadTree *SW;
        QuadTree *SE;
        QuadTree *parent;


        //I have to rethink about the predefined size.
        std::vector<sICollidable> goList;


        QuadTree (unsigned short level, UInt16 pX, UInt16 pY,
                  UInt16 pWidth, UInt16 pHeight, QuadTree & parent)
                  noexcept;

        bool contains (const sICollidable & go) const noexcept;

        void prAdd(sICollidable & go) noexcept;

        void split () noexcept;

    public:
        #ifndef NDEBUG
        static sf::RenderWindow *window;
        void render (sf::RenderWindow * renderWindow = nullptr) const noexcept;
        #endif
        QuadTree (UInt16 pWidth, UInt16 pHeight) noexcept;
        void add (sICollidable & go) noexcept;
        unsigned long long int size () const noexcept;

        ~QuadTree ();

        void update () noexcept;
    };
}

#endif //PYRAMIDPROJECT_QUADTREE_H
