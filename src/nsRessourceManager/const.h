//
// Created by Theo on 30/06/2015.
//

#ifndef PYRAMIDPROJECT_CONST_H
#define PYRAMIDPROJECT_CONST_H

//#include "RessourceManager.h"

namespace nsGameConstants
{
    //Pour la taille du tableau de textures, actuellement on a Martine, Momie donc 2

    const int CHARACTER_SPRITES_COUNT = 12;

} // nsGameConstants

namespace nsRessourceManager
{
    //Notre enumeration contenant tous les personnages
    enum CharTexturesIndex : unsigned
    {
        MARTINE = 0,
        MOMIE = 1,


        SIZE = 2   //Size = le dernier + 1. ne pas oublier d'update à chaque ajout
    };

}

#endif //PYRAMIDPROJECT_CONST_H
