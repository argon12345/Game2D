#pragma once
#include "GameObject.h"
#include "TextureContainer.h"

namespace model {



	class Tile :
		public GameObject
	{
	public:
		sf::Texture * type;
		sf::Vector2f position;
		Tile();
		Tile(int x, int y);
		~Tile();
	};






}