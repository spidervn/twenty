/*
 * CCmdLineUI_EventHandler.cpp
 *
 *  Created on: Dec 5, 2017
 *      Author: spider
 */


#include "CCmdLineUI.h"
#include <string>

using namespace std;

void CCmdLineUI::EventHandler::onEnter()
{
	// Get CCmdLineUI here
	std::string cmd;

	CCmdLineUI* pCmdUI =  vertex<CCmdLineUI>();

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
	CCmdLineUI* pCmdUI =  vertex<CCmdLineUI>();
}

void CCmdLineUI::EventHandler::onTyping()
{
	string currentCmd;
	string currentWord;

	
}
