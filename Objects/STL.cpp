/*
 * STL.cpp
 *
 *  Created on: Jan 10, 2016
 *      Author: sina
 */
#include "STL.h"

bool is_stl(std::string func_name)
{
	if(func_name == "sqrt")
		return true;
	return false;
}

double run_stl(std::string func_name, std::vector<double>args)
{
	double res = 0;
	if(func_name == "sqrt")
	{
		res = sqrt(args[0]);
	}
	return res;
}
