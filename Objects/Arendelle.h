/*
 * Arendelle.h
 *
 *  Created on: Nov 11, 2015
 *      Author: Sina
 */

#include "Screen.h"
#include <string>
#include <unordered_map>
using namespace std;

#ifndef BASE_ARENDELLE_H_
#define BASE_ARENDELLE_H_


class Arendelle{
public:
	Arendelle();
	virtual ~Arendelle();

	Screen* getScreen();
	void setScreen(Screen* screen);

	void addOrUpdateSpace(string name, long long value);
	bool spaceExist(string name);
	long long getLastSpaceSearch();

	void initSources();

	bool sourceExist(string name);
	bool isExtendedSource(string name);
	long long getLastSourceSearch();

private:
	unordered_map<string,long long>spaces;
	unordered_map<string,long long>::iterator spaceSearch;

	unordered_map<string,long long*>sources;
	unordered_map<string,long long*>::iterator sourceSearch;
	Screen* screen;
};


#endif /* BASE_ARENDELLE_H_ */
