#pragma once
#include "GameTile.h"


namespace model {
	class GameModel
	{
	public:
		GameModel();
		~GameModel();
		void run();
		void update();
		Tile ** getTileToDraw(sf::Vector2f);
	private:
		GameTile gameTile;
		TextureContainer textureContainer;

	};
}