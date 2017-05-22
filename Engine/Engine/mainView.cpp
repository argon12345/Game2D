#ifndef MAINVIEW_H
#define	MAINVIEW_H
#include "mainView.h"
#endif // !MAINVIEW_H

namespace view {
	void clickPlay(sf::RenderWindow * window) {
		PlayView playView(window);
		playView.run();
	}
	void clickSettings() {

	}

	void clickAbout() {

	}


	mainView::mainView()
		: window(new sf::RenderWindow(sf::VideoMode(windowSettings::width, windowSettings::height, windowSettings::bpp), "Game2D", sf::Style::Default))
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
		button.push_back(ctrl::Button(width, height * 6, 200, 55, sf::String("Play"), &font));
		button.push_back(ctrl::Button(width, height * 7, 200, 55, sf::String("Settings"), &font));
		button.push_back(ctrl::Button(width, height * 8, 200, 55, sf::String("About"), &font));
		button.push_back(ctrl::Button(width, height * 9, 200, 55, sf::String("Quit"), &font));
	}


	mainView::~mainView() {
		window->~RenderWindow();
	}

	void mainView::run() {
		size_t positionMenuClick = 0;
		button[positionMenuClick].title.setFillColor(sf::Color::Red);
		while (window->isOpen()) {
			draw();
			window->display();
			window->clear();
			sf::Event _event;
			while (window->pollEvent(_event)) {
				if (_event.type == sf::Event::Closed) {
					window->close();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					window->close();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					if (positionMenuClick == 0) {
						button[positionMenuClick].title.setFillColor(sf::Color::White);
						positionMenuClick = button.size() - 1;
						button[positionMenuClick].title.setFillColor(sf::Color::Red);
					}
					else {
						button[positionMenuClick].title.setFillColor(sf::Color::White);
						positionMenuClick--;
						button[positionMenuClick].title.setFillColor(sf::Color::Red);
					}

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					if (positionMenuClick == button.size() - 1) {
						button[positionMenuClick].title.setFillColor(sf::Color::White);
						positionMenuClick = 0;
						button[positionMenuClick].title.setFillColor(sf::Color::Red);
					}
					else {
						button[positionMenuClick].title.setFillColor(sf::Color::White);
						positionMenuClick++;
						button[positionMenuClick].title.setFillColor(sf::Color::Red);
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
					switch (positionMenuClick) {
					case 0:
						clickPlay(window);
						break;
					case 1:
						clickSettings();
						break;
					case 2:
						clickAbout();
						break;
					case 3:
						window->close();
						break;
					}
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true) {
					sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
					int i = 0;
					for (ctrl::Button & vec : button) {
						if (vec.checkPosition(mousePosition)) {
							switch (i) {
							case 0:
								clickPlay(window);
								break;
							case 1:
								clickSettings();
								break;
							case 2:
								clickAbout();
								break;
							case 3:
								window->close();
								break;
							}
						}
						i++;
					}
				}
				if (_event.type == sf::Event::Resized) {
					const sf::Vector2u newWindowSize(windowSettings::width, windowSettings::height);
					window->setSize(newWindowSize);
				}
			}
		}
	}

	void mainView::draw() {
		for (ctrl::Button var : button) {
			window->draw(var.title);
		}

	}




}