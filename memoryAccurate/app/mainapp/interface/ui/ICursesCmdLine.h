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
	// ICursesCmdLine();
	virtual ~ICursesCmdLine() {}

	virtual int initialize() = 0;						// Declare all needs here
	virtual int run() = 0;

	class IEventHandler;
	class IGrammarWork;

	virtual IEventHandler* eventHandler() = 0;
	virtual IGrammarWork* grammarWork() = 0;
};

class ICursesCmdLine::IEventHandler : public IPyramidPenta
{
public:
	virtual void onEnter(std::string) = 0;
	virtual void onExeCmd(std::string) = 0;
	virtual void onTyping(std::string currentLine,std::string currentWord) = 0;
};

class ICursesCmdLine::IGrammarWork : public IPyramidPenta
{
public:
	virtual int initialize() = 0;
	virtual void showAutoComplete(std::vector<std::string> list) = 0;
	virtual int onSelect() = 0;
	virtual int onCancel() = 0;
};

#endif /* APP_MAINAPP_UI_ICURSESCMDLINE_H_ */
