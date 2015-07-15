//
// Created by Theo on 30/06/2015
//

#include "../Utility/typedef.hpp"
#include <SFML/Graphics.hpp>

#ifndef PYRAMIDPROJECT_CONST_H
#define PYRAMIDPROJECT_CONST_H

namespace nsGameConstants
{
    ///////////////////////////////////////////////////////////////////////////////////////////////
    //                                  MOUVEMENT                                                //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    //Le personnage prend 40 frames (~0.6 s) pour arriver a pleine vitesse
    const Int16 ACCELERATION_FRAMES_NUMBER = 40;
    //Le personnage ralentit plus vite qu'il n'accelere
    const Int16 STOPPING_FRAMES_NUMBER = 20;

    //On est à 60 update/s donc 10*60 = 600pixel/s, float car utilisee seulement en float
    const float MAX_SPEED_PIXEL_PER_FRAME = 10.f;

    ///////////////////////////////////////////////////////////////////////////////////////////////
    //                                  TILESET                                                  //
    ///////////////////////////////////////////////////////////////////////////////////////////////
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

    ///////////////////////////////////////////////////////////////////////////////////////////////
    //                                  PLAYER CONSTANTS                                         //
    ///////////////////////////////////////////////////////////////////////////////////////////////
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
