#include "SFML\Graphics.hpp"
#include "gSettings.h"
#include <vector>
#include <iostream>

#pragma once

#define FONT_IN_CENTER		gSettings::width/2
#define COLOR_WHITE			sf::Color::White
#define COLOR_RED			sf::Color::Red


struct Button {
public:
	size_t x, y, width, height;
	sf::Text title;
	Button(int, int, int, int, sf::String title, sf::Font *);
	inline bool checkPosition(sf::Vector2i);
};






class mainView
{
public:
	mainView();
	~mainView();
	sf::RenderWindow * window;

	void run();
private:
	void draw();

	gSettings settings;
	std::vector<Button> button;
	sf::Font font;
	

};

