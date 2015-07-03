//
// Created by Pierre-Antoine on 30/06/2015.
//

#ifndef PYRAMIDPROJECT_QUADTREE_H
#define PYRAMIDPROJECT_QUADTREE_H

#include <memory>
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

        /*
        UInt16 x;
        UInt16 y;
        UInt16 width;
        UInt16 height;
        */

        nsCollider::RectangleUI area;
        bool splited {false};

        QuadTree *NW;
        QuadTree *NE;
        QuadTree *SW;
        QuadTree *SE;

        std::vector<sICollidable> goList;
        std::vector<sICollidable> bigGoList;


        QuadTree (unsigned short level,UInt16 pX, UInt16 pY,UInt16 pWidth, UInt16 pHeight) noexcept;

        bool fits (QuadTree *Child, sICollidable & go) const noexcept;

        void prAdd(sICollidable & go) noexcept;

    public:
        QuadTree (UInt16 pWidth, UInt16 pHeight) noexcept;
        void add (sICollidable & go) noexcept;
        unsigned long long int size ();

        ~QuadTree ();
    };
}

#endif //PYRAMIDPROJECT_QUADTREE_H
