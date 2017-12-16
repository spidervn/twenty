/*
 * CWinQuiz.cpp
 *
 *  Created on: Dec 12, 2017
 *      Author: spider
 */

#include <mainapp/impl/ui/CWinQuiz.h>
#include "mainapp/interface/ncurses/ICursesApp.h"
#include "mainapp/interface/ncurses/curses_events.h"
#include "mainapp/interface/model/quiz_model.h"
#include "mainapp/impl/core/CKernel.h"
#include <form.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <chrono>
#include <iostream>

using namespace std;

/*
 +----------+--------------------------------------------------+
 | 21:00    |  Quiz Name: Name                                 |
 +----------+  Quiz Code: Code                                 |
 |             Author: author                                  |
 |                                                             |
 | Code01 +----------------------------------------+           |
 |        +----------------------------------------+           |
 |                                                             |
 | Item02 +----------------------------------------+           |
 |        +----------------------------------------+           |
 |                                                             |
 | Item03 +----------------------------------------+           |
 |        +----------------------------------------+           |
 |                                  +-----------++-----------+ |
 |                                  |  Start    ||  CANCEL   | |
 |                                  +-----------++-----------+ |
 +-------------------------------------------------------------+
*/

CWinQuiz::CWinQuiz() {
	_sw_seconds = 0;
	pWin = NULL;
	pForm = NULL;

	std::chrono::time_point<std::chrono::system_clock> tnow;
	tnow = std::chrono::system_clock::now();

	_memory.code = "Twenty";
	_memory.name = "Twenty quiz code";
	_memory.created_date = 0;
	_memory.author = "ducvd";

	_memory.listmemory_.push_back("1. World-class engineer");
	_memory.listmemory_.push_back("1.2. Solving 1000 stackexchange computer science's problems");
	_memory.listmemory_.push_back("1.3. Solving 1000 stackexchange mathematics's problems");
	_memory.listmemory_.push_back("2. True stamina 99");
	_memory.listmemory_.push_back("2.1. Easily run 3km in 20 minutes");
	_memory.listmemory_.push_back("2.2. Easily enjoy two ugly woman at the same time");
	_memory.listmemory_.push_back("3. Keep Ph-back");
	_memory.listmemory_.push_back("3.1. Find the right method to treat Ph's father for fully recover from disaster.");
	_memory.listmemory_.push_back("3.3. Give 60% stock of a company to her");

	_modelt = KERNEL->memorytest_()->generateTest(_memory);	// Model for test
}

CWinQuiz::~CWinQuiz() {
}

void CWinQuiz::doModal()
{
	FIELD* field[5];
	FORM* my_form;
	WINDOW* my_form_win;
	WINDOW* win_sub;
	int ch, rows, cols;
	MEVENT m_event;					// Mouse events

	/* Initialize curses */
	initscr();
	start_color();
	cbreak();
	noecho();
	// raw();
	keypad(stdscr, TRUE);

	/* Initialize few color paris */
	init_pair(1, COLOR_RED, COLOR_YELLOW);
	init_pair(2, COLOR_WHITE, COLOR_BLUE);

	/* Initialize the fields */
	field[0] = new_field(1, 20, 6, 1, 0, 3);
	field[1] = new_field(1, 10, 8, 1, 0, 0);
	field[2] = new_field(1, 10, 10, 1, 0, 0);
	field[3] = new_field(1, 10, 12, 1, 0, 0);
	field[4] = NULL;

	/* Set field options */
	set_field_back(field[0], A_UNDERLINE);
	field_opts_off(field[0], O_AUTOSKIP);	/* Don't go to next field when this */
											/* Field is filled up */
	set_field_back(field[1], A_UNDERLINE);
	field_opts_off(field[1], O_AUTOSKIP);
	set_field_pad(field[1], '@');
	set_field_fore(field[1], COLOR_PAIR(2));

	set_field_back(field[2], A_UNDERLINE);
	field_opts_off(field[2], O_AUTOSKIP);
	set_field_fore(field[2], COLOR_PAIR(2));

	set_field_back(field[3], A_UNDERLINE);
	field_opts_off(field[3], O_AUTOSKIP);
	set_field_fore(field[3], COLOR_PAIR(2));

	/* Create the form and post it */
	my_form = new_form(field);

	/* Create the window and sub window */
	scale_form(my_form, &rows, &cols);

	/* Create the Window to be associated with the form */
	my_form_win = newwin(rows + 4, cols + 4, 4, 4);	
	keypad(my_form_win, TRUE);

	/* Set main window and sub window */
	win_sub = derwin(my_form_win, rows, cols, 2, 2);
	set_form_win(my_form, my_form_win);
	set_form_sub(my_form, win_sub);

	/* Print a border around the main Window and print a title */
	
	// box(my_form_win, 0, 0);	
	wborder(my_form_win, '|', '|', '-', '-', '+', '+', '+', '+');
	// wborder(my_form_win, '|', '║', '-', '╧', '╗', '╚','╔','╝');
	// wborder(my_form_win, '|', ':', '-', '_', '+', '&','*','@');
	Util::print_in_middle(my_form_win, 1, 0, cols + 4, "My Form", COLOR_PAIR(1));

	// wrefresh(my_form_win);
	post_form(my_form);

	mvprintw(LINES - 2, 0, "Use UP, DOWN arrow keys to switch between fields");
	refresh();

	while ((ch = wgetch(my_form_win)) != KEY_F(1)) {
		switch (ch) {
			case KEY_MOUSE:
				//
				onMouse(ch);
				break;
			case KEY_DOWN:
				/* Go to next field */
				form_driver(my_form, REQ_NEXT_FIELD);
				/* Go to the end of the present buffer */
				/* Leaves nicely at the last character */
				form_driver(my_form, REQ_END_LINE);
				break;
			case KEY_UP:
				/* Go to previous field */
				form_driver(my_form, REQ_PREV_FIELD);
				form_driver(my_form, REQ_END_LINE);
				break;
			case KEY_LEFT:
				form_driver(my_form, REQ_PREV_CHAR);
				break;
			case KEY_RIGHT:
				form_driver(my_form, REQ_NEXT_CHAR);
				break;
			case KEY_BACKSPACE:
			case 8:
				form_driver(my_form, REQ_DEL_PREV);
				break;
			default:
				/* If this is a normal character, it gets */
				/* printed */
				form_driver(my_form, ch);
				break;
		}
	}

	/* Un post form and free the memory */
	unpost_form(my_form);
	free_form(my_form);
	free_field(field[0]);
	free_field(field[1]);
	free_field(field[2]);
	free_field(field[3]);

	endwin();
}

void CWinQuiz::Util::print_in_middle(WINDOW* win, int starty, int startx, int width, const char*string, chtype color) {
	int length, x, y;
	float temp;

	if (win == NULL) {
		win = stdscr;
	}

	getyx(win, y, x);

	if (startx != 0) {
		x = startx;
	}

	if (starty != 0) {
		y = starty;
	}

	if (width == 0) {
		width = 80;
	}

	length = strlen(string);
	temp = (width - length)/2;

	x = startx + (int)temp;
	wattron(win, color);
	mvwprintw(win, y, x, "%s", string);
	wattroff(win, color);
	refresh();
}

void CWinQuiz::Util::fill(WINDOW* win, int starty, int startx, int width, int height, int color_pair) {
	wattron(win, COLOR_PAIR(color_pair));

	for (int i=startx;i<width;i++)
	{
		for (int j=starty;j<height;j++)
		{
			mvwprintw(win,j,i," ");
		}
	}

	wrefresh(win);
	wattroff(win, COLOR_PAIR(color_pair));
}

void CWinQuiz::onInitialize()
{
	raw();		// Raw mode ncurses
}

void CWinQuiz::onTearDown()
{
	if (pForm)
	{
		unpost_form(pForm);
		free_form(pForm);
		pForm = NULL;
	}
}

void CWinQuiz::onTimer()
{
	int minute = 0;
	int seconds = 0;
	_sw_seconds++;

	minute = _sw_seconds / 60;
	seconds = _sw_seconds % 60;
	// Draw the Clock
	mvwhline(pWin, 0, 0, '_', 7);
	mvwhline(pWin, 2, 0, '_', 7);
	mvwvline(pWin, 0, 0, '|', 3);
	mvwvline(pWin, 0, 7, '|', 3);

	mvwprintw(pWin, 1, 1, "%0.2d:0.2d", minute, seconds);
}

void CWinQuiz::onMouse(int ch)
{
	MEVENT m_event;					// Mouse events
	if(getmouse(&m_event) == OK)
	{
		/* When the user clicks left mouse button */
		if(m_event.bstate & BUTTON1_PRESSED)
		{
			move(m_event.y, m_event.x);
		}
	}
}

void CWinQuiz::onClose()
{
	// Send Event to main App
	this->app()->enqueueEvent(CURSESAPP_EVENT_WINQUIZ_CLOSE, (void*)this);	// Send event to main App
}

void CWinQuiz::onStartQuiz()
{
	_sw_seconds = 0;
}

void CWinQuiz::onCancel1Quiz()
{
}

void CWinQuiz::onCompleteTheQuiz()
{
}

void CWinQuiz::checkActiveFields()
{
	FIELD* fields[4];
	std::string strStatus = "";

	for (int i=0;i<4;i++)
	{
	}
}
