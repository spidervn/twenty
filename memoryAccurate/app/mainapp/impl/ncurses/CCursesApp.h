/*
 * CCursesApp.h
 *
 *  Created on: Dec 20, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_IMPL_NCURSES_CCURSESAPP_H_
#define APP_MAINAPP_IMPL_NCURSES_CCURSESAPP_H_

#include "mainapp/interface/ncurses/ICursesApp.h"
#include "mainapp/interface/core/IStateMachine.h"
#include <vector>
#include <queue>

class CCursesApp: public ICursesApp, public IStateMachine {
private:
	static int _v_transits[][4];	// Transition definition
	static int _v_entries_[][2];	// Entry event
	static int _v_exit[][2];		// Exit event

	int call_function(int fnc_id, void* data);
public:
	CCursesApp();
	~CCursesApp();

	// Inherited
	int initialize();
	void registerUI(ICursesUI* ui);
	void setActiveUI(ICursesUI*);
	ICursesUI* getActiveUI();

	int main();					// Main procedure -An IUnkown thing = Everything - the most complex Curses in the world here
	int onEvent(int);			// onEvent here?

	int enqueueEvent(int event, void*data = NULL);
	int processEvent(int event, void*data = NULL);	// send event & immediately process it

	// State Machine inheritance
	int queueEvent_(int msg, void* data=NULL);	// Send to me - Not process
	int processNextQueue_();
	int currentState_();

	int getNextState_(int currentState, int msg, void* data = NULL);	// Calculate next state (calculate only, not change anything inside machine)
	int step(int msg, void* data = NULL);		// Send event then process immediately

	// Events
	int onTransition_(int fromState, int toState, void* data=NULL);
	int onEnterState_(int theoldstate, void* data);
	int onLeaveState_(int state);

	IUI* ui() { return NULL; }
	IEvent* event() { return NULL; }
protected:
	std::vector<ICursesUI*> _v_ui;
	ICursesUI* _pActive_UI;
	std::queue<int> _q_messages;
	std::queue<void*> _q_data;

private:
	int _state_;
};

#endif /* APP_MAINAPP_IMPL_NCURSES_CCURSESAPP_H_ */
