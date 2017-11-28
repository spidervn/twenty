/*
 * CAppUI.cpp
 *
 *  Created on: Nov 28, 2017
 *      Author: spider
 */

#include "CAppUI.h"
#include <ncurses.h>

CAppUI::CAppUI() {

}

CAppUI::~CAppUI() {
}

int CAppUI::initialize()
{
	initscr();					/* Start curses mode 		*/
	raw();						/* Line buffering disabled	*/
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	return 0;
}

int CAppUI::start()
{
	return 0;
}

int CAppUI::shutdown()
{
	endwin();			/* End curses mode		  */
}

int CAppUI::getModel()
{
	return 0;
}

int CAppUI::main()
{
	/* Main procedure here */
	return 0;
}
