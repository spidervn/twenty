/*
 * ICmdLineEventHandler.h
 *
 *  Created on: Nov 29, 2017
 *      Author: ducvd
 */

#ifndef APP_MAINAPP_UI_ICMDLINEEVENTHANDLER_H_
#define APP_MAINAPP_UI_ICMDLINEEVENTHANDLER_H_

class ICmdLineEventHandler {
public:
	ICmdLineEventHandler();
	virtual ~ICmdLineEventHandler();

	void onTyping() {};
	void onExeCmd() {};

};

#endif /* APP_MAINAPP_UI_ICMDLINEEVENTHANDLER_H_ */
