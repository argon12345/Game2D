#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP
#include "SFML\Graphics.hpp"
#endif // !GRAPHICS_HPP

#ifndef BUTTON_H
#define BUTTON_H
#include "Button.h"
#endif // !BUTTON_HPP

#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif // !IOSTREAM

#ifndef GSETTINGS_H
#define GSETTINGS_H
#include "gSettings.h"
#endif // !GSETTINGS_H


namespace view {
	class PlayView
	{
	public:
		PlayView(sf::RenderWindow * window);
		~PlayView();
		void run();

	private:
		void draw();
		sf::RenderWindow * window;
		sf::Font font;
		std::vector<ctrl::Button> button;
	};

}