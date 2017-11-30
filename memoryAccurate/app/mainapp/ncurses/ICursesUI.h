/*
 * ICursesUI.h
 *
 *  Created on: Nov 30, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_NCURSES_ICURSESUI_H_
#define APP_MAINAPP_NCURSES_ICURSESUI_H_

#include <arch/pyramid.h>

class ICursesUI: public IPyramidPenta {
public:
	ICursesUI();
	virtual ~ICursesUI();
};

#endif /* APP_MAINAPP_NCURSES_ICURSESUI_H_ */
