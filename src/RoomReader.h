/*
 * RoomReader.h
 *
 *  Created on: 29 juin 2015
 *      Author: kevin
 */

#ifndef ROOMREADER_H_
#define ROOMREADER_H_
#include <vector>
#include <SFML/Graphics.hpp>

typedef std::vector<sf::Sprite> VSprite;
typedef std::vector<VSprite> TSprite;

class RoomReader
{
	private:
		const unsigned KPixelSize = 60; // Taille de l'image (pixel)
		TSprite m_tabSprite;			// Vector contenant les sprites a afficher

	public:
		RoomReader (TSprite tabSprite) noexcept;
		void const Display (sf::RenderWindow & win) noexcept;	// Affiche tout les �l�ments du vector dans la fenetre pass�e en param�re

}; // RoomReader


#endif /* ROOMREADER_H_ */
