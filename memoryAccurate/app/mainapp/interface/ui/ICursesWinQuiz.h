/*
 * ICursesWinQuiz.h
 *
 *  Created on: Nov 28, 2017
 *      Author: ducvd
 */

#ifndef APP_MAINAPP_UI_ICURSESWINQUIZ_H_
#define APP_MAINAPP_UI_ICURSESWINQUIZ_H_

#include "architecture.h"
#include "mainapp/interface/ncurses/ICursesUI.h"

class ICursesWinQuiz : public ICursesUI  {
public:
	virtual void doModal() = 0;
	virtual ~ICursesWinQuiz() {};
};

#endif /* APP_MAINAPP_UI_ICURSESWINQUIZ_H_ */
