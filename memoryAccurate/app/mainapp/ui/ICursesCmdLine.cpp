/*
 * ICursesCmdLine.cpp
 *
 *  Created on: Nov 28, 2017
 *      Author: ducvd
 */

#include "ICursesCmdLine.h"
#include <string>

using namespace std;

ICursesCmdLine::ICursesCmdLine():pEvent(NULL), pGrammar(NULL)
{
}

ICursesCmdLine::~ICursesCmdLine() {

}

int ICursesCmdLine::initialize()
{
	pGrammar->initialize();	// Init UI here

	return 0;
}
