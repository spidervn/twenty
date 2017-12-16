/*
 * ICursesApp.h
 *
 *  Created on: Nov 30, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_NCURSES_ICURSESAPP_H_
#define APP_MAINAPP_NCURSES_ICURSESAPP_H_

#include "arch/pyramid.h"
#include "ICursesUI.h"

// Including raw/noraw/halfdelay/keypad

class ICursesApp: public IPyramidPenta {
public:
	virtual int initialize() = 0;

	virtual void registerUI(ICursesUI* ui) = 0;
	virtual void setActiveUI(ICursesUI*) = 0;
	virtual ICursesUI* getActiveUI() = 0;

	virtual int main() = 0;				// Main procedure -An IUnkown thing = Everything - the most complex Curses in the world here
	virtual int onEvent(int) = 0;		// onEvent here?

	virtual int enqueueEvent(int event, void*data = NULL) = 0;
	virtual int processEvent(int event, void*data = NULL) = 0;	// send event & immediately process it

	class IUI;
	class IEvent;
	virtual IUI* ui() = 0;
	virtual IEvent* event() = 0;
};

class ICursesApp::IUI : public IPyramidPenta
{
public:
	virtual void setActiveUI(ICursesUI*) = 0;
	virtual ICursesUI* getActiveUI() = 0;
};

class ICursesApp::IEvent : public IPyramidPenta
{
public:
	virtual void onEvent() = 0;
	virtual void sendEvent() = 0;
};

#endif /* APP_MAINAPP_NCURSES_ICURSESAPP_H_ */
