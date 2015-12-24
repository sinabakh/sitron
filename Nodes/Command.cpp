/*
 * Command.cpp
 *
 *  Created on: Nov 28, 2015
 *      Author: sina
 */
#include "Base.h"
#include "Command.h"

Value* NCommand::codeGen(Arendelle* arendelle)
{
	std::cout<<std::endl<<"Command : "<<cmd<<std::endl;
	Value* resVal = new Value;
	resVal = new VResult(1);
	std::string::iterator it;
	for(it= this->cmd.begin(); it != this->cmd.end(); it++)
	{
		if(*it == 'p')
			arendelle->getScreen()->paint();
		if(*it == 'n')
			arendelle->getScreen()->getCursor()->nextColor();
		if(*it == 'r')
			arendelle->getScreen()->getCursor()->goR();
		if(*it == 'd')
			arendelle->getScreen()->getCursor()->goD();
		if(*it == 'l')
			arendelle->getScreen()->getCursor()->goL();
		if(*it == 'u')
			arendelle->getScreen()->getCursor()->goU();
		if(*it == 'c')
			arendelle->getScreen()->clearDot();
		if(*it == 'i')
			arendelle->getScreen()->getCursor()->jumpToStart();
		if(*it == 'e')
			resVal = new VResult(0);
		if(*it == 'w')
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	return resVal;
}



