//
// Created by Pierre-Antoine on 29/06/2015
//

#include <SFML/Graphics/Texture.hpp>
#include "RessourceManager.h"
#include <iostream>

using namespace nsGameConstants;
using namespace std;
using namespace sf;

#define RS nsRessourceManager::RessourceManager

RS::RessourceManager()
{
}

//Definition, necessaire en plus de la declaration
map<const string, const vector<Texture>> RS::textures;

void RS::loadCharacterTextures(string characterName, const Vector2i & tailleDecoupe, unsigned spriteCount)
{
    //Si la texture n'existe pas encore, on la charge
    if (textures.find(characterName) == textures.end())
    {
        vector<Texture> textureVec;
        textureVec.reserve(textureVec.size());
        Texture characterTexture;

        int left, top;
        //Rectangle avec taille decoupe ainsi que position
        IntRect rectangleDecoupe(0, 0, tailleDecoupe.x, tailleDecoupe.y);

        //Pour trouver quelle ligne ainsi que colonne on est
        unsigned ligne = 0;
        unsigned colonne = 0;

        for (unsigned i = 0; i < spriteCount; ++i)
        {
            if (i != 0 && i % TILESET_SPRITES_PER_ROW == 0)
            {
                ++ligne;
                colonne = 0;
            }

            /*** Calcul de la découpe, position du sprite ***/
            left = colonne++ * PLAYER_SRITE_SIZE.x;
            top = ligne * PLAYER_SRITE_SIZE.y;

            rectangleDecoupe.left = left;
            rectangleDecoupe.top = top;

            //Ajustement colonne/ligne : si on est sur ligne suivante du tileset

            /*** Chargement texture i ***/
            characterTexture.loadFromFile(characterName, rectangleDecoupe);

            /*** Rangement dans tableau ***/
            textureVec.push_back(characterTexture);
        }

        //On ajoute le tableau de textures fraichement chargees
        textures.insert(pair<string, vector<Texture>>(characterName, textureVec));
    }
    else
    {
        cout << "\nRsManager::LoadTexture, texture deja chargee";
        //Si un jour on veut faire des exceptions
    }
}

const vector<sf::Texture> & RS::getTexture(const std::string & characterName)
{
    return textures[characterName];
}

#undef  RS
