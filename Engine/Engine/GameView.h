#ifndef GAMEMODEL_H
#define GAMEMODEL_H
#include "GameModel.h"
#endif // !GAMEMODEL_H

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif // !IOSTREAM

#ifndef SSTREAM
#define SSTREAM
#include <sstream>
#endif // !OSSTREAM


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
		sf::Vector2i mouseButtonRightClickedPosition;
		void drawTileSector(model::Tile** tile);
		sf::Clock clock;
	};

}