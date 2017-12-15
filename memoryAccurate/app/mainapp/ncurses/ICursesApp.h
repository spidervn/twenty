/*
 * ICursesApp.h
 *
 *  Created on: Nov 30, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_NCURSES_ICURSESAPP_H_
#define APP_MAINAPP_NCURSES_ICURSESAPP_H_

#include <arch/pyramid.h>
/*
#include "ICursesUI.h"

// Including raw/noraw/halfdelay/keypad
struct CursesMode
{};

// Inter-classes events
#define EVENT_ON_KEYPRESS 1
#define EVENT_MOUSE_MOVE 2
#define EVENT_MOUSE_CLICK 3
#define EVENT_MOUSE_DRAG 4
#define EVENT_STD_OUT 5
#define EVENT_CLOSE_UI 6

class ICursesApp: public IPyramidPenta {
public:
	ICursesApp();
	virtual ~ICursesApp();

	virtual void initialize(CursesMode) {};
	virtual void registerUI(ICursesUI* ui) {}
	virtual ICursesUI* getActiveUI() { return NULL; }

	// virtual int onKeyPress() { return 0; };
	// virtual int onMouseEvent() { return 0; };

	virtual int onEvent() = 0;

	class IUI
	{
	};

	class IEvent
	{
		virtual int onKeyPress(void* data=NULL) = 0;
		virtual int onMouseMove(void* data=NULL) = 0;
		virtual int onMouseClick(void* data=NULL) = 0;
		virtual int onMouseDrag(void* data=NULL) = 0;
		virtual int onStdOut(void* data=NULL) = 0;
	
		class IUIEvent
		{
			virtual int onCloseUI(void* data=NULL)=0;	// Close one UI
			
		};
	};
};
*/

#endif /* APP_MAINAPP_NCURSES_ICURSESAPP_H_ */
