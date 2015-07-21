//
// Created by Pierre-Antoine on 01/07/2015.
//

#include "Fabric.h"
#define PF nsPyramidProject


PF::Fabric PF::Fabric::m_instance=Fabric ();

PF::Fabric & PF::Fabric::Instance ()
{
    return m_instance;
}

PF::Fabric::Fabric()
{

}

PF::Fabric::~Fabric ()
{

}

void PF::Fabric::reach_Stair (byte_t)
{

}

#undef PF