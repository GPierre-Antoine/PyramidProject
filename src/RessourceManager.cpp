//
// Created by Pierre-Antoine on 29/06/2015.
//

#include "RessourceManager.h"
#define RS nsRessourceManager::RessourceManager
using namespace sf;


RS::RessourceManager ()
{

}


void RS::SetRenderWindow(sf::RenderWindow & window) noexcept
{
    if (this->window) this->window = &window;
}
#undef  RS