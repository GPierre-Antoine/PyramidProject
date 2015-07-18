//
// Created by Pierre-Antoine on 01/07/2015.
//

#ifndef PYRAMIDPROJECT_FABRIC_H
#define PYRAMIDPROJECT_FABRIC_H

#include <vector>
#include <list>
#include <memory>


#include "../nsGameObject/GameObject.h"
#include "../nsGameObject/Player.h"
#include "../nsGameObject/Foreground.h"
#include "../nsPyramidProject/Stair.h"
#include "../nsPyramidProject/Map.h"


namespace nsPyramidProject
{

    class Fabric
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

        std::list<std::shared_ptr<nsPyramidProject::Stair>>     stairs;
        std::shared_ptr<nsPyramidProject::Stair>                actualStair;

        std::vector<nsPyramidProject::Map>                      maps;


        //std::vector<nsGameObject::InteractiveDecoration>    interactiveObjects;
        std::vector<nsGameObject::Player>                       players;
        //std::vector<nsGameObject::Attack>                   attacks;


    public:
        static Fabric & Instance ();

        //fabrique

        //Utilisé avec Prototype (implémenté dans GameObject

    };
}


#endif //PYRAMIDPROJECT_FABRIC_H
