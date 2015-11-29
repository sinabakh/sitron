/*
 * Screen.h
 *
 *  Created on: Nov 11, 2015
 *      Author: Sina
 */

#include <vector>
#include <iostream>
using namespace std;

#ifndef BASE_SCREEN_H_
#define BASE_SCREEN_H_

struct Cursor{
	Cursor(long long screen_width, long long screen_height);
	void jumpToStart();
	long long getColor();
	void nextColor();
	void goR();
	void goL();
	void goU();
	void goD();
	long long i;
	long long j;
	long long current_color;
	long long color_limit;
	long long screen_height;
	long long screen_width;
};

class Screen{
public:
	Screen(long long columns, long long rows,  long long sColorLimit);
	Screen(long long columns,long long rows);
	Screen();
	~Screen();

	void setRows(long long rows);
	void setColumns(long long columns);
	void setCanvas(long long columns, long long rows);
	void paint(long long i, long long j);
	void paint();
	Cursor* getCursor();

	void prettyPrint();

private:
	vector< vector<long long> >matrix;
	long long columns, rows;
	Cursor* cursor;
	long long s_color_limit;
	//int i,j;
	//vector<int>::iterator columnIt;
	//vector< vector<int> >::iterator rowIt;
};



#endif /* BASE_SCREEN_H_ */
