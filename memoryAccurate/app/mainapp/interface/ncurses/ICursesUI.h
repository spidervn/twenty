/*
 * ICursesUI.h
 *
 *  Created on: Nov 30, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_NCURSES_ICURSESUI_H_
#define APP_MAINAPP_NCURSES_ICURSESUI_H_

#include "arch/pyramid.h"
class ICursesApp;

class ICursesUI: public IPyramidPenta {
public:
	virtual void init_curses_mode() = 0;
	virtual int onEvent(int event, void* data) = 0;
	virtual int enqueueEvent(int event, void*data = NULL) = 0;
	virtual void tear_down() = 0;

	virtual ICursesApp* app() = 0;	// Application
};

#endif /* APP_MAINAPP_NCURSES_ICURSESUI_H_ */
