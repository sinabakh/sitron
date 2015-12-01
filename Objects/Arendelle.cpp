/*
 * Arendelle.cpp
 *
 *  Created on: Nov 11, 2015
 *      Author: Sina
 */

#include "Arendelle.h"

Arendelle::Arendelle(){
	this->screen = new Screen(5,5);
	this->initSources();
}

Arendelle::~Arendelle(){

}

Screen* Arendelle::getScreen(){
	return this->screen;
}

void Arendelle::setScreen(Screen* screen){
	this->screen = screen;
}

void Arendelle::addOrUpdateSpace(string name, long long value)
{
	this->spaces[name] = value;
}

bool Arendelle::spaceExist(string name)
{
	spaceSearch = spaces.find(name);
	if(spaceSearch != spaces.end())
	{
	        return true;
	}
	else
	{
	        return false;
	}
}

long long Arendelle::getLastSpaceSearch()
{
	return spaceSearch->second;
}


void Arendelle::initSources()
{
	sources.insert(std::make_pair("i",&screen->getCursor()->screen_width));
	sources.insert(std::make_pair("width",&screen->getCursor()->screen_width));
	sources.insert(std::make_pair("j",&screen->getCursor()->screen_height));
	sources.insert(std::make_pair("height",&screen->getCursor()->screen_height));
	sources.insert(std::make_pair("n",&screen->getCursor()->current_color));
	sources.insert(std::make_pair("x",&screen->getCursor()->i));
	sources.insert(std::make_pair("y",&screen->getCursor()->j));
	//sources.insert(std::make_pair(,));
}


bool Arendelle::sourceExist(string name)
{
	sourceSearch = sources.find(name);
	if(sourceSearch != sources.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Arendelle::isExtendedSource(string name)
{
	if(name == "rnd")
		return true;
	if(name == "pi")
		return true;
	return false;
}

long long Arendelle::getLastSourceSearch()
{
	return *sourceSearch->second;
}
