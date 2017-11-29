/*
 * ICursesCmdLine.cpp
 *
 *  Created on: Nov 28, 2017
 *      Author: ducvd
 */

#include "ICursesCmdLine.h"
#include <string>

using namespace std;

ICursesCmdLine::ICursesCmdLine() {

}

ICursesCmdLine::~ICursesCmdLine() {

}

int ICursesCmdLine::initialize()
{
	return 0;
}

class ICursesCmdLine::EventHandler
{
	// Internal API
	void onCmdTyping()
	{
		// Execute command suggest here
	}

	void onCmd(string cmd)
	{
	}

	int onEvent(int event_code, string data)
	{
		/*
		 * All events here
		 *		-onCmdTyping
		 *		-onCommand (Enter)
		 *		-
		 */
		return 0;
	}

	int onSpecialKeysPress()
	{
		return 0;
	}

	// API for External calling
	int registerEvent()
	{
		return 0;
	}

	// External API? ICursesCmdLine call another Events
	int queryAPI()
	{
		return 0;
	}
};
