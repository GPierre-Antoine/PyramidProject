//
// Created by Pierre-Antoine on 17/07/2015.
//

#ifndef PYRAMIDPROJECT_STAIR_H
#define PYRAMIDPROJECT_STAIR_H

#include "../Utility/typedef.hpp"

namespace nsPyramidProject
{
    class Stair
    {
    private:
        byte_t floor;
    public:
        byte_t getFloor () const noexcept;
    };

}

#endif //PYRAMIDPROJECT_STAIR_H
