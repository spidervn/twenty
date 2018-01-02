/*
 * CCursesApp.cpp
 *
 *  Created on: Dec 20, 2017
 *      Author: spider
 */

#include <mainapp/impl/ncurses/CCursesApp.h>
#include <form.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <chrono>
#include <iostream>

#define STATE_INIT 0

CCursesApp::CCursesApp()
{
	_pActive_UI = NULL;
}

CCursesApp::~CCursesApp() {
}

int CCursesApp::initialize()
{
	// Init all curses here
	initscr();
	start_color();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	return 0;
}

void CCursesApp::registerUI(ICursesUI* ui)
{
	_v_ui.push_back(ui);
}

void CCursesApp::setActiveUI(ICursesUI* ui)
{
	_pActive_UI = ui;
}

ICursesUI* CCursesApp::getActiveUI()
{
	return _pActive_UI;
}

int CCursesApp::main()					// Main procedure -An IUnkown thing = Everything - the most complex Curses in the world here
{
	return 0;
}

int CCursesApp::onEvent(int)			// onEvent here?
{
	return 0;
}

int CCursesApp::enqueueEvent(int event, void*data)
{
	return 0;
}

int CCursesApp::processEvent(int event, void*data)	// send event & immediately process it
{
	return 0;
}

// State Machine inheritance
int CCursesApp::queueEvent_(int msg, void* data)	// Send to me - Not process
{
	_q_messages.push(msg);
	_q_data.push(data);
	return 0;
}

int CCursesApp::processNextQueue_()
{
	if (_q_messages.size() > 0)
	{
		int msg = _q_messages.front();
		void* data = _q_data.front();

		_q_messages.pop();
		_q_data.pop();

		step(msg, data);
	}

	return 0;
}

int CCursesApp::currentState_()
{
	return 0;
}

int CCursesApp::getNextState_(int currentState, int msg, void* data)	// Calculate next state (calculate only, not change anything inside machine)
{
	return 0;
}

int CCursesApp::step(int msg, void* data)		// Send event then process immediately
{
	return 0;
}

// Events
int CCursesApp::onTransition_(int fromState, int toState, void* data)
{
	return 0;
}

int CCursesApp::onEnterState_(int theoldstate, void* data)
{
	return 0;
}

int CCursesApp::onLeaveState_(int state)
{
	return 0;
}
