//
// Created by Pierre-Antoine on 30/06/2015.
//

#ifndef PYRAMIDPROJECT_QUADTREE_H
#define PYRAMIDPROJECT_QUADTREE_H

#include <memory> //shared pointer
#include "../nsGameObject/GameObject.h"
#include "../nsGameObject/Interface.h"

#include "Defines/typedef.hpp"

namespace nsGameEngine
{
    typedef std::shared_ptr<nsGameObject::ICollidable> sICollidable;


    class QuadTree
    {
    private:
        UInt16 level;
        static const unsigned short maxLevel {12}; //le quadtree aura 12 noeuds au plus.
        static const unsigned short maxCapacity  {5};
        byte_t  numberOfUnfittingCollider {0};


        UInt16 x;
        UInt16 y;
        UInt16 width;
        UInt16 height;


        nsCollider::RectangleUI area;
        bool splited {false};
        /*static enum
        {
            NW,
            NE,
            SW,
            SE
        };

        QuadTree *childs; /**/
        QuadTree *NW;
        QuadTree *NE;
        QuadTree *SW;
        QuadTree *SE;
        QuadTree *parent;


        //I have to rethink about the predefined size.
        std::vector<sICollidable> goList;


        QuadTree (unsigned short level, UInt16 pX, UInt16 pY,UInt16 pWidth, UInt16 pHeight, QuadTree & parent) noexcept;

        bool fits (QuadTree *Child, sICollidable & go) const noexcept;

        void prAdd(sICollidable & go) noexcept;

        void split () noexcept;

        void update () noexcept;

    public:
        QuadTree (UInt16 pWidth, UInt16 pHeight) noexcept;
        void add (sICollidable & go) noexcept;
        unsigned long long int size () const noexcept;

        ~QuadTree ();
    };
}

#endif //PYRAMIDPROJECT_QUADTREE_H
