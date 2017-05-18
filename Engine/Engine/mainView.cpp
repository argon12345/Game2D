#include "mainView.h"





mainView::mainView()
	: window(new sf::RenderWindow(sf::VideoMode(gSettings::width, gSettings::height, gSettings::bpp), "Game2D", sf::Style::Default))
{
	window->setFramerateLimit(30);
	if (!font.loadFromFile("segoesc.ttf"))
	{
		// error...
		std::cout << "error: Font not loaded" << std::endl;
		window->close();
	}
	int width = gSettings::width / 10 * 7.5;
	int height = gSettings::height / 10;
	button.push_back(Button(width, height * 6, 200, 55, sf::String("Play"), &font));
	button.push_back(Button(width, height * 7, 200, 55, sf::String("Settings"), &font));
	button.push_back(Button(width, height * 8, 200, 55, sf::String("About"), &font));
	button.push_back(Button(width, height * 9, 200, 55, sf::String("Quit"), &font));
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
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window->close();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
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
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
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
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
				if (positionMenuClick == button.size() - 1) {
					window->close();
				}
			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == true) {
				sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
				for (auto &vec : button) {
					if (vec.checkPosition(mousePosition)) {
						window->close();
					}
				}
			}
		}
	}
}

void mainView::draw() {
	for (auto &var : button) {
		window->draw(var.title);
	}

}

Button::Button(int x, int y, int width, int height, sf::String title, sf::Font * font) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->title.setPosition(x, y);
	this->title.setString(title);
	this->title.setCharacterSize(48);
	this->title.setFillColor(sf::Color::White);
	this->title.setStyle(sf::Text::Bold);
	this->title.setFont(*font);
}

inline bool Button::checkPosition(sf::Vector2i vec) {
	if (vec.x > x && vec.x < x + width && vec.y > y && vec.y < y + height) {
		return true;
	}
	else {
		return false;
	}
}
