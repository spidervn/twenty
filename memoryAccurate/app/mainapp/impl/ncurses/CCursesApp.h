/*
 * CCursesApp.h
 *
 *  Created on: Dec 20, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_IMPL_NCURSES_CCURSESAPP_H_
#define APP_MAINAPP_IMPL_NCURSES_CCURSESAPP_H_

#include "mainapp/interface/ncurses/ICursesApp.h"

class CCursesApp: public ICursesApp {
public:
	CCursesApp();
	virtual ~CCursesApp();
};

#endif /* APP_MAINAPP_IMPL_NCURSES_CCURSESAPP_H_ */
