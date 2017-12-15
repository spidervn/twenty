/*
 * CCmdLineUI.h
 *
 *  Created on: Dec 1, 2017
 *      Author: ducvd
 */

#ifndef APP_MAINAPP_IMPL_UI_CCMDLINEUI_H_
#define APP_MAINAPP_IMPL_UI_CCMDLINEUI_H_

#include "mainapp/interface/ui/ICursesCmdLine.h"

class CCmdLineUI: public ICursesCmdLine, public IPyramidArchitecture {
private:
	class EventHandler;
	class GrammarWork;
	class Toolkit;
	class UI;

	IEventHandler* pEvent;
	IGrammarWork* pGrammar;
	UI* pUI;
public:
	CCmdLineUI();
	virtual ~CCmdLineUI();

	int initialize();						// Declare all needs here
	int run();

	IEventHandler* eventHandler() { return pEvent;}
	IGrammarWork* grammarWork() { return pGrammar;}
	UI* ui() { return pUI; }
private:
	void drawModel();
	void designPyramid();
	void testVertex();
};

class CCmdLineUI::EventHandler : public IEventHandler
{
public:
	void onEnter(std::string);
	void onExeCmd(std::string);
	void onTyping(std::string currentLine,std::string currentWord);
};

class CCmdLineUI::GrammarWork : public IGrammarWork
{
public:
	int initialize() { return 0; }
	void showAutoComplete(std::vector<std::string> list) {}
	int onSelect() { return 0; }
	int onCancel() { return 0; }
};

class CCmdLineUI::UI : public IPyramidPenta
{
public:
	UI();
	class Layout;
	Layout* layout() { return pLayout; }

private:
	Layout* pLayout;
};

class CCmdLineUI::UI::Layout : public IPyramidPenta
{
public:
	int arrangePopup(int candidatey, int candidatex, int screenRows, int screenCols, int popupRows, int popupCols, int& outputy, int& outputx);
};

#endif /* APP_MAINAPP_IMPL_UI_CCMDLINEUI_H_ */
