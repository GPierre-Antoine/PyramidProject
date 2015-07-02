/*
 * RoomReader.cpp
 *
 *  Created on: 29 juin 2015
 *      Author: kevin
 */

#include <iostream>
#include "RoomReader.h"
#include <SFML/Graphics.hpp>



nsRessourceManager::RoomReader::RoomReader (TSprite tabSprite) noexcept
	: m_tabSprite(tabSprite)
{} // RoomReader ()

void const nsRessourceManager::RoomReader::Display (sf::RenderWindow & win) noexcept
{
	for (unsigned i (0) ; i < m_tabSprite.size() ; ++i)
	{
		for (unsigned j (0) ; j < m_tabSprite[i].size() ; ++j)
		{
			win.draw(m_tabSprite[i][j]);
		}
	}

} // Display ()
