/*
 * Arendelle.h
 *
 *  Created on: Nov 11, 2015
 *      Author: Sina
 */

#include "Screen.h"
#include "Function.h"
//#include "../mingw.thread.h"
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <unordered_map>
#include <fstream>
#include <thread>
#include <boost/filesystem.hpp>
#include "../Renderer/RenderEngine.h"
using namespace std;

#ifndef BASE_ARENDELLE_H_
#define BASE_ARENDELLE_H_

//#include <thread>

class Arendelle{
public:
	Arendelle();
	virtual ~Arendelle();

	Screen* getScreen();
	void setScreen(Screen* screen);

	RenderEngine* renderEngine;
	void render();

	std::thread spawnRenderer() {
	    return std::thread(&Arendelle::render, this);
	}

	void initFunctions();
	bool functionExist(string name);
	Function* getLastFunctionSearch();

	void addOrUpdateSpace(string name, long long value, long long index);
	void addOrUpdateSpace(string name, long long value);
	bool spaceExist(string name);
	double getLastSpaceSearch(long long index);
	double getLastSpaceSearch();

	void addOrUpdateStoredSpace(string name, long long value);
	void addOrUpdateStoredSpace(string name, long long value, long long index);
	bool storedSpaceExist(string name);
	double getLastStoredSpaceSearch(long long index);
	double getLastStoredSpaceSearch();

	void initSources();
	void initStoredSpaces();

	bool sourceExist(string name);
	bool isExtendedSource(string name);
	double getLastSourceSearch();

	void setWorkingDir(string mainDir);
	string getWorkingDir();

	vector<boost::filesystem::path> findFunctionFiles(string cDir);
	vector<boost::filesystem::path> findStoredSpaceFiles(string cDir);

private:
	unordered_map<string, Function*>functions;
	unordered_map<string, Function*>::iterator functionSearch;

	unordered_map<string, vector<double> >spaces;
	unordered_map<string, vector<double> >::iterator spaceSearch;

	unordered_map<string, vector<double> >storedSpaces;
	unordered_map<string, vector<double> >::iterator storedSpaceSearch;

	unordered_map<string,long long*>sources;
	unordered_map<string,long long*>::iterator sourceSearch;
	bool extendedSource = false;
	double extendedSourceVal;

	Screen* screen;
	string workingDir;
};


#endif /* BASE_ARENDELLE_H_ */
