//
// Created by Pierre-Antoine on 01/07/2015.
//

#ifndef PYRAMIDPROJECT_FABRIC_H
#define PYRAMIDPROJECT_FABRIC_H

#include <vector> //container of entity
#include <memory>
#include <stack>


#include "../Utility/typedef.hpp"
#include "../nsGameObject/GameObject.h"
#include "../nsGameObject/Player.h"
#include "../nsGameObject/Foreground.h"
#include "../nsPyramidProject/Stair.h"
#include "../nsPyramidProject/Map.h"


namespace nsPyramidProject
{

    class Fabric final
    {
    //La durée de vie de la fabrique est celle du programme.
        //singleton

    private:
        long long int                                           seed;

        static Fabric m_instance;
        Fabric & operator= (const Fabric &) {}

        Fabric (const Fabric &) {}
        Fabric ();
        ~Fabric ();

        std::stack<std::shared_ptr<nsPyramidProject::Stair>>    stairs;

        std::vector<nsPyramidProject::Map>                      maps;


        //std::vector<nsGameObject::InteractiveDecoration>    interactiveObjects;
        std::vector<nsGameObject::Player>                       players;
        //std::vector<nsGameObject::Attack>                   attacks;


    public:
        static Fabric & Instance ();

        void reach_Stair (byte_t );

        //fabrique

        //Utilisé avec Prototype (implémenté dans GameObject

    };
}


#endif //PYRAMIDPROJECT_FABRIC_H
