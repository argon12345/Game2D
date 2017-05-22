#ifndef BUTTON_H
#define BUTTON_H
#include "Button.h"
#endif // !BUTTON_H





ctrl::Button::Button(int x, int y, int width, int height, sf::String title, sf::Font * font) {
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

bool ctrl::Button::checkPosition(sf::Vector2i vec) {
	if (vec.x > x && vec.x < x + width && vec.y > y && vec.y < y + height) {
		return true;
	}
	else {
		return false;
	}
}
