/*
 * ICursesApp.h
 *
 *  Created on: Nov 30, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_NCURSES_ICURSESAPP_H_
#define APP_MAINAPP_NCURSES_ICURSESAPP_H_

#include <arch/pyramid.h>
#include "ICursesUI.h"

// Including raw/noraw/halfdelay/keypad
struct CursesMode
{};

class ICursesApp: public IPyramidPenta {
public:
	ICursesApp();
	virtual ~ICursesApp();

	virtual void initialize(CursesMode) {};
	virtual void registerUI(ICursesUI* ui) {}
	virtual ICursesUI* getActiveUI() { return NULL; }
	virtual int onKeyPress() { return 0; };
	virtual int onMouseEvent() { return 0; };

};


#endif /* APP_MAINAPP_NCURSES_ICURSESAPP_H_ */
