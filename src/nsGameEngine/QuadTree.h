//
// Created by Pierre-Antoine on 30/06/2015.
//

#ifndef PYRAMIDPROJECT_QUADTREE_H
#define PYRAMIDPROJECT_QUADTREE_H

#define  DEBUG_QUADTREE_VISUAL


#include <memory> //shared pointer, unique ptr
#include <array>  //array

#include "../nsGameObject/GameObject.h"
#include "../nsGameObject/Interface.h"

#include "SFML/Graphics/renderWindow.hpp"

#include "../Utility/typedef.hpp"

namespace nsGameEngine
{
    class QuadTree;
    typedef std::shared_ptr<nsGameObject::ICollidable> sICollidable;
    typedef std::unique_ptr<QuadTree> QTptr;

    namespace
    {
        enum EQT
        {
            NW,
            NE,
            SW,
            SE,
            size
        };
    }


    class QuadTree : sf::NonCopyable
    {
    private:
        static const UInt16 maxLevel {4};
        //le quadtree aura 4 niveaux au plus.
        static const size_t maxCapacity  {5};


        UInt16 level;
        bool splited {false};


        nsCollider::Rectangle area;
        std::array<QTptr,EQT::size> quad;

        QuadTree *parent;

        //Allocate method, tells a Quadtree to generate subnodes
        void allocate   () noexcept;
        void deAllocate () noexcept;
        void split () noexcept;
        //I have to rethink about the predefined size.
        std::vector<sICollidable> goList;


        QuadTree (unsigned short level, UInt16 pX, UInt16 pY,
                  UInt16 pWidth, UInt16 pHeight, QuadTree & parent)
                  noexcept;

        bool contains (const sICollidable & go) const noexcept;
        void prAdd(sICollidable & go) noexcept;

    public:

        QuadTree (UInt16 pWidth, UInt16 pHeight) noexcept;
        void add (sICollidable & go) noexcept;


        size_t size () const noexcept;

        ~QuadTree ();

        void update () noexcept;




//if in debug mode, function exists.
#ifndef NDEBUG
        static sf::RenderWindow *window;
        void render (sf::RenderWindow * renderWindow = nullptr) const noexcept;
        void forceSplit(int n = 1) noexcept;
        size_t getByteCount () const noexcept;
#endif

    };
}

#endif //PYRAMIDPROJECT_QUADTREE_H
