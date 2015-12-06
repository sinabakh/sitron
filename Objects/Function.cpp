/*
 * Function.cpp
 *
 *  Created on: Dec 6, 2015
 *      Author: sina
 */
#include "Function.h"

std::vector<std::string> headerStr_to_vecStr(std::string headerStr)
{
	std::vector<std::string>arguments;
	std::string::iterator it = headerStr.begin();
	while(it != headerStr.end())
	{
		if(*it == ' ' || *it == '\t' || *it == '\n')
			headerStr.erase(it);
		else
			it++;

	}
	int start=1;
	for(int i=1; i<headerStr.size(); i++)
	{
		if(headerStr[i]==',' || headerStr[i]=='>')
		{
			std::string arg = headerStr.substr(start,i-start);
			start = i+1;
			std::cout<<"---> Func Arg: "<<arg<<std::endl;
			arguments.push_back(arg);
		}
	}
	return arguments;
}

Function::Function(std::string name,std::string headerStr, std::string code)
{
	std::cout<<"--->Func Name: "<<name<<std::endl;
	this->name = name;
	this->args = headerStr_to_vecStr(headerStr);
	std::cout<<"---> Code: "<<code<<std::endl;
	this->code = code;
}
