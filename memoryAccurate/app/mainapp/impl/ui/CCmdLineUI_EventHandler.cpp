/*
 * CCmdLineUI_EventHandler.cpp
 *
 *  Created on: Dec 5, 2017
 *      Author: spider
 */


#include "CCmdLineUI.h"

void CCmdLineUI::EventHandler::onEnter()
{
	std::string cmd;

	if (cmd == "add")
	{
		printw("Add quiz\n");
	}
	else if (cmd=="doquiz")
	{
		printw("Do quiz");
	}
	else if (cmd=="quit")
	{
		printw("exit program\n");
	}
	else
	{
		printw("Unknown command\n");
	}
}

void CCmdLineUI::EventHandler::onExeCmd(std::string)
{
}

void CCmdLineUI::EventHandler::onTyping()
{
}
