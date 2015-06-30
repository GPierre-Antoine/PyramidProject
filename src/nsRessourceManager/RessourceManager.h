    //
    // Created by Pierre-Antoine on 29/06/2015.
    //

    #ifndef PYRAMIDPROJECT_RESSOURCEMANAGER_H
    #define PYRAMIDPROJECT_RESSOURCEMANAGER_H

    #include <SFML/Graphics/RenderWindow.hpp>
    #include "const.h"

    namespace nsRessourceManager
    {

        class RessourceManager
        {
        private:

            static sf::RenderWindow* window;

            static const std::vector<sf::Texture*> tablePointers [CharTexturesIndex::SIZE];

            //static const std::vector<std::vector<sf::Texture>>
            //        textures[nsGameConstants::CHARACTER_SPRITES_COUNT][CharTexturesIndex::SIZE];

        public:
            //Verifie aussi si la texture n'a pas deja ete chargee
            void loadCharacterTextures(std::string imageFileName, const sf::Vector2i & tailleDecoupe);

            const sf::Texture* getTextureTablePointer(int characterLine);

            RessourceManager();

        };

    }

    #endif //PYRAMIDPROJECT_RESSOURCEMANAGER_H