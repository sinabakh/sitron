/*
 * STL.cpp
 *
 *  Created on: Jan 10, 2016
 *      Author: sina
 */
#include "STL.h"

bool is_stl(std::string func_name)
{
	if(func_name == "min")
		return true;
	if(func_name == "max")
		return true;
	if(func_name == "abs")
		return true;
	if(func_name == "round")
		return true;
	if(func_name == "floor")
		return true;
	if(func_name == "ceiling")
		return true;
	if(func_name == "log")
		return true;
	if(func_name == "log10")
		return true;
	if(func_name == "sqrt")
		return true;
	if(func_name == "sin")
		return true;
	if(func_name == "cos")
		return true;
	if(func_name == "tan")
		return true;
	if(func_name == "sinh")
		return true;
	if(func_name == "cosh")
		return true;
	if(func_name == "tanh")
		return true;
	if(func_name == "rad")
		return true;
	if(func_name == "deg")
		return true;
	return false;
}

double run_stl(std::string func_name, std::vector<double>args)
{
	double res = 0;
	float pi = 3.14159265;
	if(func_name == "sqrt")
	{
		res = sqrt(args[0]);
	}
	if(func_name == "min")
	{
		res = std::min(args[0], args[1]);
	}
	if(func_name == "max")
	{
		res = std::max(args[0], args[1]);
	}
	if(func_name == "abs")
	{
		res = std::abs((long)args[0]);
	}
	if(func_name == "round")
	{
		res = round(args[0]);
	}
	if(func_name == "floor")
	{
		res = floor(args[0]);
	}
	if(func_name == "ceiling")
	{
		res = ceil(args[0]);
	}
	if(func_name == "log")
	{
		res = log(args[0]);
	}
	if(func_name == "log10")
	{
		res = log10(args[0]);
	}
	if(func_name == "sin")
	{
		res = sin(args[0] * pi / 180);
	}
	if(func_name == "cos")
	{
		res = cos(args[0] * pi / 180);
	}
	if(func_name == "tan")
	{
		res = tan(args[0] * pi / 180);
	}
	if(func_name == "sinh")
	{
		res = sinh(args[0] * pi / 180);
	}
	if(func_name == "cosh")
	{
		res = cosh(args[0] * pi / 180);
	}
	if(func_name == "tanh")
	{
		res = tanh(args[0] * pi / 180);
	}
	if(func_name == "rad")
	{
		res = args[0] * pi / 180;
	}
	if(func_name == "deg")
	{
		res = args[0] * 180 / pi;
	}
	return res;
}
