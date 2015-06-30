//
// Created by Pierre-Antoine on 01/07/2015.
//

#ifndef PYRAMIDPROJECT_INTERFACE_H
#define PYRAMIDPROJECT_INTERFACE_H
namespace nsGameObject
{
    typedef unsigned short int UInt16;
    typedef short int Int16;
    class ICollidable
    {
        virtual UInt16 getWidth () const noexcept = 0;
        virtual UInt16 getHeight () const noexcept = 0;
        virtual ~ICollidable () {}
    };
    class IMovable
    {
        virtual void move(Int16 Up,Int16 Right) noexcept = 0;
        virtual ~IMovable () {}
    };
}

#endif //PYRAMIDPROJECT_INTERFACE_H
