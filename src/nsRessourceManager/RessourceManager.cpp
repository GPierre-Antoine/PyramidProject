//
// Created by Pierre-Antoine on 29/06/2015
//

#include <SFML/Graphics/Texture.hpp>
#include "RessourceManager.h"

using namespace std;
using namespace sf;

#define RS nsRessourceManager::RessourceManager

RS::RessourceManager()
{
}

void RS::loadCharacterTextures(string characterName, const Vector2i & tailleDecoupe, unsigned spriteCount)
{
    //Si la texture n'existe pas encore, on la charge
    if (textures.find(characterName) == textures.end())
    {
        vector<Texture> textureVec;
        Texture characterTexture;

        int left, top;
        //Rectangle avec taille decoupe ainsi que position
        IntRect rectangleDecoupe(0, 0, tailleDecoupe.x, tailleDecoupe.y);

        for (unsigned i = 0; i < spriteCount; ++i)
        {
            /*** Calcul de la découpe, position du sprite ***/
            //left = i / 3      (division euclidienne)
            left = i / nsGameConstants::TILESET_SPRITES_PER_ROW;
            //top = i % 3       (reste)
            top = i % nsGameConstants::TILESET_SPRITES_PER_ROW;
            rectangleDecoupe.left = left;
            rectangleDecoupe.top = top;

            /*** Chargement texture i ***/
            characterTexture.loadFromFile(characterName, rectangleDecoupe);

            /*** Rangement dans tableau ***/
            textureVec.push_back(characterTexture);
        }

        //On ajoute le tableau de textures fraichement chargees
        textures[characterName] = textureVec;

    }
    else
    {
        //Si un jour on veut faire des exceptions
    }
}

const vector<sf::Texture> & RS::getTexture(const std::string & characterName)
{
    return textures[characterName];
}

#undef  RS
