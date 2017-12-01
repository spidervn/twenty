/*
 * CCmdLineUI.h
 *
 *  Created on: Dec 1, 2017
 *      Author: ducvd
 */

#ifndef APP_MAINAPP_IMPL_UI_CCMDLINEUI_H_
#define APP_MAINAPP_IMPL_UI_CCMDLINEUI_H_

#include <mainapp/interface/ui/ICursesCmdLine.h>

class CCmdLineUI: public ICursesCmdLine {
public:
	CCmdLineUI();
	virtual ~CCmdLineUI();

	int initialize();						// Declare all needs here
	int run();

	class EventHandler;
	class GrammarWork;
	class Toolkit;
	IEventHandler* eventHandler() { return pEvent;}
	IGrammarWork* grammarWork() { return pGrammar;}
private:
	IEventHandler* pEvent;
	IGrammarWork* pGrammar;
};

class CCmdLineUI::EventHandler : public IEventHandler
{
public:
	void onEnter() {}
	void onExeCmd(std::string) {}
	void onTyping() {}
};

class CCmdLineUI::GrammarWork : public IGrammarWork
{
public:
	int initialize() { return 0; }
	void showAutoComplete(std::vector<std::string> list) {}
	int onSelect() { return 0; }
	int onCancel() { return 0; }
};

#endif /* APP_MAINAPP_IMPL_UI_CCMDLINEUI_H_ */
