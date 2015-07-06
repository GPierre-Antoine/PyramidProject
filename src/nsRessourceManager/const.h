//
// Created by Theo on 30/06/2015
//

#ifndef PYRAMIDPROJECT_CONST_H
#define PYRAMIDPROJECT_CONST_H

//#include "RessourceManager.h"
#include "../nsGameEngine/Defines/typedef.hpp"

namespace nsGameConstants
{

    const unsigned CHARACTER_SPRITES_COUNT = 12;
    const unsigned TILESET_SPRITES_PER_ROW = 3;

    //Correspond a notre tileset personnage, a chaque ligne.
    const UInt16 PLAYER_UP = 0;
    const UInt16 PLAYER_RIGHT = 1;
    const UInt16 PLAYER_DOWN = 2;
    const UInt16 PLAYER_LEFT = 3;

    //Avance un des pieds
    const UInt16 PLAYER_STEPPING_FRAMES = 40;
    //Ramene l'autre pied
    const UInt16 PLAYER_STOP_STEP_FRAMES = 30;

    const sf::Vector2i PLAYER_SRITE_SIZE = sf::Vector2<int>(148, 200);

    const UInt16 WARRIOR_HEALTH = 100;

} // nsGameConstants

namespace nsRessourceManager
{

    //Ce sont les noms de personnages, qui classent la map de RsManager
    const std::string MARTINE = "../images/Martine.png";
    const std::string MOMIE = "../images/Momie.png";
    const std::string BASIC = "../images/Basic.png";//Perso pourri de base, si texture non trouvee

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