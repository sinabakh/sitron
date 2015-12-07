/*
 * RenderEngine.h
 *
 *  Created on: Dec 6, 2015
 *      Author: sina
 */

#ifndef RENDERER_RENDERENGINE_H_
#define RENDERER_RENDERENGINE_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "../Objects/Screen.h"
using namespace std;

class RenderEngine{
public:
	vector< vector<long long> >matrix;
	Screen* sceen;
	long long width_unit;
	long long height_unit;
	sf::RenderWindow window;
	sf::RectangleShape block;
	RenderEngine(Screen* screen);
	void initWindow();
	void render();

};


#endif /* RENDERER_RENDERENGINE_H_ */
