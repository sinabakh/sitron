/*
 * Screen.cpp
 *
 *  Created on: Nov 11, 2015
 *      Author: sina
 */

#include "Screen.h"

Cursor::Cursor(long long screen_width, long long screen_height)
{
	this->i = 0;
	this->j = 0;
	this->current_color = 1;
	this->color_limit = 4;
	this->screen_height = screen_height;
	this->screen_width = screen_width;
}

void Cursor::goR(){
	//if(this->j + 1 >= this->screen_width )
	//	return;
	this->j++;
}

void Cursor::goL(){
	//if(this->j - 1 < 0 )
	//	return;
	this->j--;
}

void Cursor::goD(){
	//if(this->i + 1 >= this->screen_height )
	//	return;
	this->i++;
}


void Cursor::goU(){
	//if(this->i - 1 < 0 )
	//	return;
	this->i--;
}

void Cursor::nextColor(){
	this->current_color ++;
	if(current_color > color_limit)
		current_color = current_color - color_limit ;
}

void Cursor::jumpToStart(){
	this->i = 0;
	this->j = 0;
}

long long Cursor::getColor(){
	return this->current_color;
}

Screen::Screen(long long columns, long long rows, long long sColorLimit){
	this->columns = columns;
	this->rows = rows;
	this->matrix.resize(rows, vector<long long> (columns,0));
	this->cursor = new Cursor(columns, rows);
	this->s_color_limit = sColorLimit;
}

Screen::Screen(long long columns, long long rows){
	this->columns = columns;
	this->rows = rows;
	this->matrix.resize(rows, vector<long long> (columns,0));
	this->cursor = new Cursor(columns, rows);
	this->s_color_limit = 4;

}

Screen::~Screen(){

}

void Screen::setColumns(long long columns){
	this->columns = columns;
	this->matrix.resize(columns, vector<long long> (this->rows,0));
}

void Screen::setRows(long long rows){
	this->rows=rows;
	this->matrix.resize(this->columns, vector<long long> (rows,0));
}

void Screen::setCanvas(long long columns, long long rows){
	this->setColumns(columns);
	this->setRows(rows);
}

void Screen::paint(long long i, long long j){
	matrix[i][j] = this->cursor->current_color;
}

void Screen::paint(){
	//this->paint(cursor->i, cursor->j);
	if(cursor->i >= this->columns || cursor->j >= this->rows)
		return;
	this->paint(cursor->i, cursor->j);
}

void Screen::clearDot(long long i, long long j){
	matrix[i][j] = 0;
}

void Screen::clearDot(){
	if(cursor->i >= this->columns || cursor->j >= this->rows)
			return;
	this->clearDot(cursor->i, cursor->j);
}

Cursor* Screen::getCursor(){
	return this->cursor;
}

void Screen::prettyPrint(){
	for(unsigned long long i=0; i<this->rows; i++)
	{
		for(unsigned long long j=0; j<this->columns; j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
