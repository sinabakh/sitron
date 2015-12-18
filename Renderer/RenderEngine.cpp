/*
 * RenderEngine.cpp
 *
 *  Created on: Dec 6, 2015
 *      Author: sina
 */
#include "RenderEngine.h"


RenderEngine::RenderEngine(Screen* screen)
{
	this->width_unit = 20;
	this->height_unit = this->width_unit;
	block.setSize(sf::Vector2f(width_unit, height_unit));
	block.setFillColor(sf::Color::Cyan);
	//block = shape;
	this->sceen = screen;
	this->matrix = screen->getMatrix();
}

void RenderEngine::initWindow()
{
	cout<<"Initing Window: ("<<matrix[0].size()<<" , "<<matrix.size()<<")"<<endl;
	long long width = width_unit * matrix.size();
	long long height = height_unit * matrix[0].size();
	window.create(sf::VideoMode(width, height), "Arendelle Works!");
}

void RenderEngine::render()
{
	//this->matrix = this->sceen->getMatrix();
	initWindow();

    while (window.isOpen())
    {
	sf::Event event;
	while (window.pollEvent(event))
	{
	    if (event.type == sf::Event::Closed)
		window.close();
	}

	window.clear();
	this->matrix = this->sceen->getMatrix();
	for(long long x = 0; x<matrix.size(); x++)
	{
		for(long long y=0; y<matrix[0].size(); y++)
		{
			if(matrix[x][y] != 0)
			{
				sf::RectangleShape shape = block;
				shape.setPosition(sf::Vector2f(width_unit*x,height_unit*y));
				int color_unit = 255 / 5;
				int color = 255 - (color_unit*(matrix[x][y]-1));
				shape.setFillColor(sf::Color(255,255,255,color));
				window.draw(shape);
			}
		}
	}
	//window.draw(shape);
	window.display();
    }
}
