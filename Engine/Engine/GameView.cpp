#include "GameView.h"


namespace view {

	

	GameView::GameView()
	{
	}
	GameView::GameView(sf::RenderWindow * window) {
		this->window = window;
		scale.x = 0.25f;
		scale.y = 0.25f;
		windowPostion.x = START_SECTOR * (SECTOR_SIZE - 1) + SECTOR_SIZE / 2;
		windowPostion.y = START_SECTOR * (SECTOR_SIZE - 1) + SECTOR_SIZE / 2;
	}


	GameView::~GameView()
	{
	}

	void GameView::run() {
		bool active = true;
		sf::Uint64 FPS = 0;
		sf::Time time;
		window->setFramerateLimit(200);
		while (window->isOpen() && active) {
			window->display();
			window->clear();
			FPS++;
		


			for (int i = -1; i < 1; i++) {
				for (int j = -1; j < 1; j++) {
					model::Tile ** tile = gameModel.getTileToDraw(windowPostion + sf::Vector2f(i*SECTOR_SIZE, j*SECTOR_SIZE));
					drawTileSector(tile);
				}
			}

			/*
			Test Function
			*/
			if (FPS % 50 == 1) {
				time = clock.getElapsedTime();
				clock.restart();
			}
			sf::Uint32 x = 50000/time.asMilliseconds();
			sf::Text text;
			std::ostringstream oss;
			oss << x;
			text.setString(oss.str());
			sf::Font font;
			font.loadFromFile("segoesc.ttf");
			text.setFont(font);
			text.setPosition(100, 100);
			text.setCharacterSize(80);
			window->draw(text);
			
			sf::Event event;
			while (window->pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window->close();
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
					windowPostion.x-=2;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					windowPostion.x+=2;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					windowPostion.y-=2;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					windowPostion.y+=2;
				}
				else if (event.type == sf::Event::MouseWheelMoved) {
					if (event.mouseWheel.delta > 0) {
						if (scale.x < SCALE_MAX) {
							scale.x *= 2;
							scale.y *= 2;
						}
					}
					else {
						if (scale.x > SCALE_MIN) {
							scale.x *= 0.5;
							scale.y *= 0.5;
						}
					}
				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {			
					windowPostion -= (sf::Vector2f(mouseButtonRightClickedPosition) - sf::Vector2f(sf::Mouse::getPosition(*window)));
					mouseButtonRightClickedPosition = sf::Mouse::getPosition(*window);
				}
				else if (event.type == sf::Event::MouseButtonPressed && (event.mouseButton.button == sf::Mouse::Right)) {
					mouseButtonRightClickedPosition = sf::Mouse::getPosition(*window);
					
				}
			}
			if (windowPostion.x > SECTOR_SIZE*NUMBER_OF_SECTORS - 128) {
				windowPostion.x = SECTOR_SIZE*NUMBER_OF_SECTORS - 128;
			}
			if (windowPostion.x < 128) {
				windowPostion.x = 128;
			}
			if (windowPostion.y > SECTOR_SIZE*NUMBER_OF_SECTORS - 128) {
				windowPostion.y = SECTOR_SIZE*NUMBER_OF_SECTORS - 128;
			}
			if (windowPostion.y < 128) {
				windowPostion.y = 128;
			}

		}
	}
	void GameView::drawTileSector(model::Tile** tile) {
		sf::Sprite field;
		field.setScale(scale);
		field.setOrigin(TEXTURE_SIZE_X / 2, TEXTURE_SIZE_Y / 2);
		for (int i = 0; i < SECTOR_SIZE; i++) {
			for (int j = 0; j < SECTOR_SIZE; j++) {
				sf::Vector2f position = windowPostion - tile[i][j].position;		
				if (position.x < 0 || position.y < 0) {
					continue;
				}
				position.x = position.x * TEXTURE_SIZE_X * scale.x;
				if (position.x > 1920) continue;
				position.y = position.y * TEXTURE_SIZE_Y * scale.y;
				if (position.y > 1080) continue;
				field.setPosition(position);
				field.setTexture(*tile[i][j].type);
				window->draw(field);
			}
		}
	}
}