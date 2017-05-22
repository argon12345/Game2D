#ifndef BUTTON_H
#define BUTTON_H
#include "Button.h"
#endif // !BUTTON_H
#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP
#include "SFML\Graphics.hpp"
#endif // !GRAPHICS_HPP
#ifndef GSETTINGS_H
#define GSETTINGS_H
#include "gSettings.h"
#endif // !GSETTINGS_H
#ifndef VECTOR
#define VECTOR
#include <vector>
#endif // !VECTOR
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif // !IOSTREAM
#ifndef PLAYVIEW_H
#define PLAYVIEW_H
#include "playView.h"
#endif // !PLAYVIEW_H








#define FONT_IN_CENTER		windowSettings::width/2
#define COLOR_WHITE			sf::Color::White
#define COLOR_RED			sf::Color::Red








namespace view {
	class mainView
	{
	public:
		mainView();
		~mainView();
		sf::RenderWindow * window;

		void run();
	private:
		void draw();

		windowSettings settings;
		std::vector<ctrl::Button> button;
		sf::Font font;


	};

}