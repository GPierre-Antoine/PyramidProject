//
// Created by Pierre-Antoine on 01/07/2015.
//

#include "Collider.h"
#define COLL nsGameEngine::nsCollider
    void COLL::Collider::accept ()
    {

    }


    bool  COLL::Rectangle::collides (const Collider & other) const noexcept
    {
        bool boolean;
        switch (other.type)
        {
            case RECTANGLE:
                boolean = (contains (other.origin) || contains (other.origin.first));
                break;
            case CIRCLE:
                break;
            default:
                break;
        }
        return boolean;
    }

#undef COLL