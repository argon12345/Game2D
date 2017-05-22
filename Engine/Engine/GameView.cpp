#include "GameView.h"


namespace view {

	

	GameView::GameView()
	{
	}
	GameView::GameView(sf::RenderWindow * window) {
		this->window = window;
		scale.x = 0.5f;
		scale.y = 0.5f;
		windowPostion.x = START_SECTOR * (SECTOR_SIZE - 1) + SECTOR_SIZE / 2;
		windowPostion.y = START_SECTOR * (SECTOR_SIZE - 1) + SECTOR_SIZE / 2;
	}


	GameView::~GameView()
	{
	}

	void GameView::run() {
		bool active = true;
		while (window->isOpen() && active) {
			window->display();
			window->clear();
			model::Tile ** tile = gameModel.getTileToDraw(windowPostion);
			drawTileSector(tile);
			sf::Event event;
			while (window->pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window->close();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
					windowPostion.x--;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					windowPostion.x++;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					windowPostion.y--;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					windowPostion.y++;
				}
			}
		}
	}
	void GameView::drawTileSector(model::Tile** tile) {
		sf::Sprite field;
		field.setTexture(model::TextureContainer::grass1);
		field.setPosition(0, 0);
		window->draw(field);
		for (int i = 0; i < SECTOR_SIZE; i++) {
			for (int j = 0; j < SECTOR_SIZE; j++) {
				field.setTexture(*tile[i][j].type);
				field.setScale(scale);
				sf::Vector2f position = windowPostion - tile[i][j].position;
				position.x = position.x * TEXTURE_SIZE_X * scale.x;
				position.y = position.y * TEXTURE_SIZE_Y * scale.y;
				field.setPosition(position);
				window->draw(field);
			}
		}
	}
}