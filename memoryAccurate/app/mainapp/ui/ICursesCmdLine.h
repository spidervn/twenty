/*
 * ICursesCmdLine.h
 *
 *  Created on: Nov 28, 2017
 *      Author: ducvd
 */

#ifndef APP_MAINAPP_UI_ICURSESCMDLINE_H_
#define APP_MAINAPP_UI_ICURSESCMDLINE_H_

#include <architecture.h>
#include <arch/abstract.h>
#include <mainapp/ncurses/ICursesUI.h>
#include <string>
#include <vector>
#include "ICmdLineEventHandler.h"

class ICursesCmdLine : public ICursesUI, public IEventDispatching {
public:
	ICursesCmdLine();
	virtual ~ICursesCmdLine();

	int initialize();						// Declare all needs here
	int run();
	std::string getModel() { return ""; }	// Current Model (Command)


	class EventHandler;
	class GrammarWork;
	class Toolkit;
	EventHandler* eventHandler() { return pEvent;}
	GrammarWork* grammarWork() { return pGrammar;}
private:
	EventHandler* pEvent;
	GrammarWork* pGrammar;
};

class ICursesCmdLine::EventHandler : public IPyramidPenta
{
public:
	void onEnter();
	void onExeCmd(std::string);
	void onTyping();
};

class ICursesCmdLine::GrammarWork : public IPyramidPenta
{
public:
	int initialize() { return 0; }
	void showAutoComplete(std::vector<std::string> list) {};
	int onSelect() { return 0; }
	int onCancel() { return 0; }
};

// Data structure for
struct CmdLine
{

};

#endif /* APP_MAINAPP_UI_ICURSESCMDLINE_H_ */
