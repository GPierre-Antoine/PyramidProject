//
// Created by Pierre-Antoine on 30/06/2015.
//

#ifndef PYRAMIDPROJECT_QUADTREE_H
#define PYRAMIDPROJECT_QUADTREE_H

#include <memory>
#include "../nsGameObject/GameObject.h"
#include "../nsGameObject/Interface.h"

namespace nsGameEngine
{
    typedef std::shared_ptr<nsGameObject::GameObject> sGameObject;

    typedef unsigned short int UInt16;

    class QuadTree
    {
    private:
        UInt16 level;
        static UInt16 maxLevel {12}; //le quadtree aura 12 noeuds au plus.
        static UInt16 maxCapacity  {5};

        UInt16 x;
        UInt16 y;
        UInt16 width;
        UInt16 height;
        bool splited {false};

        QuadTree *NW;
        QuadTree *NE;
        QuadTree *SW;
        QuadTree *SE;

        std::vector<sGameObject> goList;


        QuadTree (UInt16 level,UInt16 pX, UInt16 pY,UInt16 pWidth, UInt16 pHeight) noexcept;

        bool fits (QuadTree *Child, sGameObject & go) const noexcept;

        void prAdd(sGameObject & go) noexcept;

    public:
        QuadTree (UInt16 pWidth, UInt16 pHeight) noexcept;
        void add (sGameObject & go) noexcept;
        unsigned long long int size ();

        ~QuadTree ();
    };
}

#endif //PYRAMIDPROJECT_QUADTREE_H
