/*
 * CWinQuiz.h
 *
 *  Created on: Dec 12, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_IMPL_UI_CWINQUIZ_H_
#define APP_MAINAPP_IMPL_UI_CWINQUIZ_H_

#include <mainapp/interface/ui/ICursesWinQuiz.h>

class CWinQuiz: public ICursesWinQuiz {
public:
	CWinQuiz();
	virtual ~CWinQuiz();

	void doModal();

	class Util
	{
	public:
		static void print_in_middle(WINDOW* win, int starty, int startx, int width, char* string, chtype color);
	};
};

#endif /* APP_MAINAPP_IMPL_UI_CWINQUIZ_H_ */