/*
 * ICursesCmdLine.h
 *
 *  Created on: Nov 28, 2017
 *      Author: ducvd
 */

#ifndef APP_MAINAPP_UI_ICURSESCMDLINE_H_
#define APP_MAINAPP_UI_ICURSESCMDLINE_H_

#include <architecture.h>
#include "ICmdLineEventHandler.h"

class ICursesCmdLine : public IPyramidPenta {
private:
	class EventHandler;
	ICmdLineEventHandler* pEvent;
public:
	ICursesCmdLine();
	virtual ~ICursesCmdLine();

	int initialize();		// Declare all needs here
	int declareEvents();
	int onExeCmd() { return 0; }

	ICmdLineEventHandler* getEventHandle() { return pEvent; }
};

// Data structure for
struct CmdLine
{

};

#endif /* APP_MAINAPP_UI_ICURSESCMDLINE_H_ */
