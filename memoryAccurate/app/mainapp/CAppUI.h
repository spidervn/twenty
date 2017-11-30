/*
 * CAppUI.h
 *
 *  Created on: Nov 28, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_CAPPUI_H_
#define APP_MAINAPP_CAPPUI_H_

#include <stdlib.h>
#include <architecture.h>
#include <arch/abstract.h>
#include <mainapp/ncurses/ICursesApp.h>

class CAppUI: public ICursesApp, public IEventDispatching {
public:
	CAppUI();
	virtual ~CAppUI();

	int initialize();

	int start();

	int shutdown();

	int getModel();

	int main();

	class WindowManager;
	WindowManager* windowManager() { return NULL; }
};

class CAppUI::WindowManager
{
public:
	int setActiveWindow(IPyramid* win) { return 0; }
};

#endif /* APP_MAINAPP_CAPPUI_H_ */
