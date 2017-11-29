/*
 * ICursesWinQuiz.h
 *
 *  Created on: Nov 28, 2017
 *      Author: ducvd
 */

#ifndef APP_MAINAPP_UI_ICURSESWINQUIZ_H_
#define APP_MAINAPP_UI_ICURSESWINQUIZ_H_

#include <architecture.h>

class ICursesWinQuiz : public IPyramid  {
public:
	ICursesWinQuiz();
	virtual ~ICursesWinQuiz();

	virtual void doModal() {};

};

#endif /* APP_MAINAPP_UI_ICURSESWINQUIZ_H_ */
