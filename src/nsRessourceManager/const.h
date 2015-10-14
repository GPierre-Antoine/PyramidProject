//
// Created by Theo on 30/06/2015
//

#include "../Utility/typedef.hpp"
#include <SFML/Graphics.hpp>

#pragma once

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
    const float MAX_SPEED_PIXEL_PER_FRAME = 2.f; // todo remettre 10.f

    ///////////////////////////////////////////////////////////////////////////////////////////////
    //                                  TILESET                                                  //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    const byte_t CHARACTER_SPRITES_COUNT = 4 * 13;
    const byte_t TILESET_SPRITES_PER_ROW = 13;

    // Ligne correspondante dans le spriteset
    const byte_t PLAYER_UP = 0;
    const byte_t PLAYER_DOWN = 1;
    const byte_t PLAYER_LEFT = 2;
    const byte_t PLAYER_RIGHT = 3;

    // Colonne correspondante dans le spriteset
    const byte_t CHARACTER_IDLE = 0;
    const byte_t CHARACTER_RIGHT_LEG_FORWARD = 1;
    const byte_t CHARACTER_RIGHT_LEG_MID = 2;
    const byte_t CHARACTER_LEFT_LEG_MID = 3;
    const byte_t CHARACTER_LEFT_LEG_FORWARD = 4;
    const byte_t CHARACTER_TORSO = 5;
    const byte_t CHARACTER_HEAD = 6;
    const byte_t CHARACTER_LEFT_ARM = 7;
    const byte_t CHARACTER_RIGHT_ARM = 8;
    const byte_t CHARACTER_ACTION1 = 9;
    const byte_t CHARACTER_ACTION2 = 10;
    const byte_t CHARACTER_ACTION3 = 11;
    const byte_t CHARACTER_ACTION4 = 12;

    ////Avance un des pieds
    const UInt16 PLAYER_MID_STEPPING_FRAMES = 30;
    const UInt16 PLAYER_FORWARD_STEPPING_FRAMES = 50;
    ////Ramene l'autre pied
    //const UInt16 PLAYER_STOP_STEP_FRAMES = 30;

    const sf::Vector2i CHARACTER_SPRITE_SIZE = sf::Vector2<int>(200, 200);

    ///////////////////////////////////////////////////////////////////////////////////////////////
    //                                  PLAYER CONSTANTS                                         //
    ///////////////////////////////////////////////////////////////////////////////////////////////
    const UInt16 WARRIOR_HEALTH = 100;

} // nsGameConstants

namespace nsRessourceManager
{
    //La pair contient le characterID, et le filePath du spriteset
    typedef const std::pair<byte_t, std::string> KPair_t;

    //L'id de nos personnages
    KPair_t BASIC (0, "../images/Basic.png");
    KPair_t WARRIOR (1, "../images/Warrior.png");
    KPair_t MARTINE (45, "../images/Martine.png");

}