/*
 * RenderEngine.cpp
 *
 *  Created on: Dec 6, 2015
 *      Author: sina
 */
#include "RenderEngine.h"

void RenderEngine::render()
{
		sf::RenderWindow window(sf::VideoMode(200, 200), "Arendelle Works!");
	    sf::RectangleShape shape(sf::Vector2f(120, 120));
	    shape.setFillColor(sf::Color::Cyan);

	    while (window.isOpen())
	    {
	        sf::Event event;
	        while (window.pollEvent(event))
	        {
	            if (event.type == sf::Event::Closed)
	                window.close();
	        }

	        window.clear();
	        window.draw(shape);
	        window.display();
	    }
}
