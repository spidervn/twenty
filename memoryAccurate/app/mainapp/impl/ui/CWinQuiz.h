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

	void init_curses_mode() {}
	int onEvent(int event, void* data) { return 1; }
	void tear_down() {}

	void doModal();

	class Util
	{
	public:
		static void print_in_middle(WINDOW* win, int starty, int startx, int width, const char* string, chtype color);
		static void fill(WINDOW* win, int starty, int startx, int width, int height, int color_pair);
	};
};

#endif /* APP_MAINAPP_IMPL_UI_CWINQUIZ_H_ */
