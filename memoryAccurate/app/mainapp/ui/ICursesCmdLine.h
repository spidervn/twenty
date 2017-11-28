/*
 * ICursesCmdLine.h
 *
 *  Created on: Nov 28, 2017
 *      Author: ducvd
 */

#ifndef APP_MAINAPP_UI_ICURSESCMDLINE_H_
#define APP_MAINAPP_UI_ICURSESCMDLINE_H_

#include <architecture.h>

class ICursesCmdLine : public IPyramid {
public:
	ICursesCmdLine();
	virtual ~ICursesCmdLine();

	int initialize();		// Declare all needs here
	int declareEvents();	// 
};

// Data structure for
struct CmdLine
{

};

#endif /* APP_MAINAPP_UI_ICURSESCMDLINE_H_ */
