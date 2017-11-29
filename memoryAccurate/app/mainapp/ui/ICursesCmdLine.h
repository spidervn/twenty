/*
 * ICursesCmdLine.h
 *
 *  Created on: Nov 28, 2017
 *      Author: ducvd
 */

#ifndef APP_MAINAPP_UI_ICURSESCMDLINE_H_
#define APP_MAINAPP_UI_ICURSESCMDLINE_H_

#include <architecture.h>
#include <string>
#include <vector>
#include "ICmdLineEventHandler.h"

class ICursesCmdLine : public IPyramidPenta {
public:
	ICursesCmdLine();
	virtual ~ICursesCmdLine();

	int initialize();						// Declare all needs here
	std::string getModel() { return ""; }	// Current Model (Command)

	class EventHandler;
	class GrammarWork;
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
	void showAutoComplete(std::vector<std::string> list) {};
	int onSelect() { return 0; }
	int onCancel() { return 0; }
};

// Data structure for
struct CmdLine
{

};

#endif /* APP_MAINAPP_UI_ICURSESCMDLINE_H_ */
