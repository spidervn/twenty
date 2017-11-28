/*
 * CAppUI.h
 *
 *  Created on: Nov 28, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_CAPPUI_H_
#define APP_MAINAPP_CAPPUI_H_

#include <architecture.h>

class CAppUI: public ICursesPyr {
public:
	CAppUI();
	virtual ~CAppUI();

	int initialize();

	int start();

	int shutdown();

	int getModel();

	int main();
};

#endif /* APP_MAINAPP_CAPPUI_H_ */
