/*
 * Function.h
 *
 *  Created on: Dec 6, 2015
 *      Author: sina
 */

#ifndef OBJECTS_FUNCTION_H_
#define OBJECTS_FUNCTION_H_

#include <iostream>
#include <string>
#include <vector>

class Function{
public:
	std::string name;
	std::string code;
	std::vector<std::string>args;
	Function(std::string name, std::string headerStr, std::string code);
};



#endif /* OBJECTS_FUNCTION_H_ */
