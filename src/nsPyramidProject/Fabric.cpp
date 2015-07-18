//
// Created by Pierre-Antoine on 01/07/2015.
//

#include "Fabric.h"
#define PF nsPyramidProject::Fabric


PF PF::m_instance=Fabric ();

PF & PF::Instance ()
{
    return m_instance;
}

PF::Fabric()
{

}

PF::~Fabric ()
{

}

#undef PF