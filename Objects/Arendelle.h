/*
 * Arendelle.h
 *
 *  Created on: Nov 11, 2015
 *      Author: Sina
 */

#include "Screen.h"
#include <string>
#include <unordered_map>
#include <fstream>
#include <boost/filesystem.hpp>
using namespace std;

#ifndef BASE_ARENDELLE_H_
#define BASE_ARENDELLE_H_


class Arendelle{
public:
	Arendelle();
	virtual ~Arendelle();

	Screen* getScreen();
	void setScreen(Screen* screen);


	void initFunctions();

	void addOrUpdateSpace(string name, long long value);
	bool spaceExist(string name);
	long long getLastSpaceSearch();

	void addOrUpdateStoredSpace(string name, long long value);
	bool storedSpaceExist(string name);
	long long getLastStoredSpaceSearch();

	void initSources();
	void initStoredSpaces();

	bool sourceExist(string name);
	bool isExtendedSource(string name);
	long long getLastSourceSearch();

	void setWorkingDir(string mainDir);
	string getWorkingDir();

	vector<boost::filesystem::path> findFunctionFiles(string cDir);
	vector<boost::filesystem::path> findStoredSpaceFiles(string cDir);

private:
	unordered_map<string,long long>spaces;
	unordered_map<string,long long>::iterator spaceSearch;

	unordered_map<string,long long>storedSpaces;
	unordered_map<string,long long>::iterator storedSpaceSearch;

	unordered_map<string,long long*>sources;
	unordered_map<string,long long*>::iterator sourceSearch;
	Screen* screen;
	string workingDir;
};


#endif /* BASE_ARENDELLE_H_ */
