//
// Created by Theo on 30/06/2015
//

#ifndef PYRAMIDPROJECT_CONST_H
#define PYRAMIDPROJECT_CONST_H

//#include "RessourceManager.h"

namespace nsGameConstants
{

    const unsigned CHARACTER_SPRITES_COUNT = 12;
    const unsigned TILESET_SPRITES_PER_ROW = 3;

} // nsGameConstants

namespace nsRessourceManager
{

    //Ce sont les noms de personnages, qui classent la map de RsManager
    const std::string MARTINE = "../images/Martine.png";
    const std::string MOMIE = "../images/Momie.png";

}

#endif //PYRAMIDPROJECT_CONST_H














//vieux truc
//Notre enumeration contenant tous les personnages
/*enum CharTexturesIndex : unsigned
{
    MARTINE = 0,
    MOMIE = 1,


    SIZE = 2   //Size = le dernier + 1. ne pas oublier d'update à chaque ajout
};*/