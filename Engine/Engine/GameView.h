#ifndef GAMEMODEL_H
#define GAMEMODEL_H
#include "GameModel.h"
#endif // !GAMEMODEL_H

namespace view {
	class GameView
	{
	public:
		GameView();
		GameView(sf::RenderWindow * window);
		~GameView();
		void run();
	private:

		sf::RenderWindow * window;
		model::GameModel gameModel;
		sf::Vector2f windowPostion;
		sf::Vector2f scale;

		void drawTileSector(model::Tile** tile);
	};

}