/*
 * CWinQuiz.h
 *
 *  Created on: Dec 12, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_IMPL_UI_CWINQUIZ_H_
#define APP_MAINAPP_IMPL_UI_CWINQUIZ_H_

#include "mainapp/interface/ui/ICursesWinQuiz.h"
#include "mainapp/interface/model/quiz_model.h"
#include "mainapp/interface/core/IStateMachine.h"
#include <form.h>
#include <vector>
#include <queue>

#define WQZ_FLAG_IS_QUIZING 0x00000001
#define 

class CWinQuiz: public ICursesWinQuiz, public IStateMachine {
public:
	CWinQuiz();
	virtual ~CWinQuiz();

	// Inherit virtual functions
	void init_curses_mode() {}
	void tear_down() {}
	ICursesApp* app() { return NULL; }

	void doModal();
	void doModal1();

	// Inherited state machine
	int queueEvent_(int msg, void* data=NULL);	// Send to me - Not process
	int processNextQueue_();	// 0; Success; 1-Failed; 2-No message on queue
	int currentState_();
	int getNextState_(int currentState, int msg, void* data = NULL);	// Calculate next state (calculate only, not change anything inside machine)
	int next(int msg, void* data = NULL);		// Send event then process

	int onTransition_(int fromState, int toState, void* data=NULL);
	int onEnterState_(int state, void* data);
	int onLeaveState_(int state);

	class Util
	{
	public:
		static void print_in_middle(WINDOW* win, int starty, int startx, int width, const char* string, chtype color);
		static void fill(WINDOW* win, int starty, int startx, int width, int height, int color_pair);
	};
protected:

	/*
		States and Events:
		--------------------
		init
			--(msg_show)--> (onLoadQuiz_)loading_quiz 
		loading_quiz
			--(loaded_memquiz){ initDoingQuiz( [ init_curses, draw_quizform ]) } --> user choice
			--(load_failed_memquiz) { [ uninit_curses, drawErrorForm ] } --> display_error
		user_choice
			--(click_start_quiz_)--{ onWaitStart([ drawWaitstart ]) } ---> wait_start
			--(click_close_quiz_) { onCloseQuiz[ uninit_curses ] }---> quit
		wait_start
			--(timer ([ drawWaitStart ]) )--> wait_start
			--(timeup_wait_start{[ erase_wait_start_ ]})--> doing_quiz
		doing_quiz
			--(timer{ drawStopwatch } )---> doing_quiz
			--(timeup_ { stopStopwatch, calc_score_ } )--> display_score
			--(click_cancel_{[ draw_quizform, erase_stop_watch_ ]})--> user_choice
			--(click_complete_quiz)---> confirm_finish_quiz
		confirm_finish_quiz
			--(click_Y { stopStopwatch, calc_score_ })--> display_score
			--(click_N { } )--> doing_quiz
		display_error
			--(click_close_quiz_ { uninit_curses } ) --> quit
		display_score
			--(click_restart)--> wait_start
			--(click_close_quiz_)--> quit
		quit
			--(show_form)--> loading_quiz
		<<any_state>>
			--(keyboard{ onKeyboard[] })--><<any_state>>
		<<any_state>>
			--(mouse{ onMouse[] })--><<any_state>>
	 */

	// Supported functions
	void checkActiveFields();

	// Event functions
	void onInitialize();	// Init windows
	void onTearDown();		// Break ncurses

	void onLoadMemoryUnit(std::string);
	void onStartQuiz();
	void onCancel1Quiz();
	void onCompleteTheQuiz();

	void onTimer();			// Timer to
	void onClose();			//

	void onKeyboard(int ch);
	void onMouse(int ch);

	// Supported functions for events & transtions
	int onLoadQuiz_();		// Loading quiz
	int init_curses();		// Init curses mode
	int uninit_curses();	
	int initDoingQuiz();
	int draw_quizform();
	int drawErrorForm();

	int drawWaitstart();
	int erase_wait_start_();

	int drawStopwatch();
	int stopStopwatch();

	// Events
	int onWaitStart();
	int onCloseQuiz();
private:
	void drawClock__();
	void drawReadyMessage_();

	int _nextState_(int msg, void* data);
	int _getNextState(int currentState, int msg, void* data);

	FORM* _pForm_;
	WINDOW* _pWin;
	WINDOW* _pWinSb; 	// Win sub
	FIELD* _fields[7];	// Fields

	MemoryStick _memory;
	QuizTestModel _modelt; 	// Test model
	QuizAnswer _answer;

	int _innerstate = 1;	// 1. NotReady; 2. IsQuizing; 3. Finished Quiz; 4. Display
	int _sw_seconds;		// Stopwach seconds for
							//	=> 

	// Windows position
	int _toppos;
	int _left;
	int _win_width_;
	int _win_height;

	std::queue<int> _q_messages;
	std::queue<void*> _q_data;
};

#endif /* APP_MAINAPP_IMPL_UI_CWINQUIZ_H_ */
