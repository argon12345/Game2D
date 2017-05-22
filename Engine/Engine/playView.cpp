
#ifndef PLAYVIEW_H
#define PLAYVIEW_H
#include "playView.h"
#endif // !PLAYVIEW_H


namespace view {

	PlayView::PlayView(sf::RenderWindow * window)
		:window(window)
	{
		window->setFramerateLimit(30);
		if (!font.loadFromFile("segoesc.ttf"))
		{
			// error...
			std::cout << "error: Font not loaded" << std::endl;
			window->close();
		}

		int width = windowSettings::width / 10 * 7.5;
		int height = windowSettings::height / 10;
		button.push_back(ctrl::Button(width, height * 6, 200, 55, sf::String("New"), &font));
		button.push_back(ctrl::Button(width, height * 7, 200, 55, sf::String("Load"), &font));
		button.push_back(ctrl::Button(width, height * 8, 200, 55, sf::String("Quit"), &font));
	}

	PlayView::~PlayView()
	{
	}

	void PlayView::run() {
		bool windowEnabled = true;
		while (window->isOpen() && windowEnabled) {
			window->display();
			window->clear();
			size_t positionMenuClick = 0;
			button[positionMenuClick].title.setFillColor(sf::Color::Red);
			draw();

			sf::Event event;
			while (window->pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window->close();
				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true) {
					sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
					int i = 0;
					for (ctrl::Button & vec : button) {
						if (vec.checkPosition(mousePosition)) {
							switch (i) {
							case 0:
								
								break;
							case 1:
								
								break;
							case 2:
								windowEnabled = false;
								break;
							}
						}
						i++;
					}
				}
			}
		}
	}

	void PlayView::draw() {
		for (ctrl::Button var : button) {
			window->draw(var.title);
		}
	}
}