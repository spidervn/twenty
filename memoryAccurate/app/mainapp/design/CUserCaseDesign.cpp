/*
 * CUserCaseDesign.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: spider
 */

#include "CUserCaseDesign.h"

#include <architecture.h>
#include <mainapp/IApp.h>
#include <mainapp/CAppUI.h>
#include <mainapp/ui/ICursesCmdLine.h>
#include <mainapp/ui/ICursesWinQuiz.h>
#include <mainapp/lib/IAutoComplete.h>
#include <mainapp/lib/ICommandParser.h>
#include <mainapp/ncurses/ICursesApp.h>

using namespace std;

CUserCaseDesign::CUserCaseDesign() {
}

CUserCaseDesign::~CUserCaseDesign() {
}

int CUserCaseDesign::cmdLineExecute()
{
	IApp pApp;
	ICursesCmdLine icmd;
	ICursesWinQuiz quiz;
	IAutoComplete icomplete;
	ICommandParser iparser;

	icmd.initialize();

	if (iparser.parseCmd(icmd.getModel()) == 0)
	{
		icmd.eventHandler()->onExeCmd("");
	}
	return 0;
}

int CUserCaseDesign::cmdLineTyping()
{
	CAppUI appUI;
	ICursesCmdLine icmd;
	ICommandParser iparser;
	ICursesPyr curses;
	vector<string> vhints;

	int EVT_WAITKEY = 0;
	int EVT_WORK = 1;

	icmd.eventHandler()->onTyping();
	vhints = iparser.autoComplete(icmd.getModel(), "");

	icmd.grammarWork()->showAutoComplete(vhints);	// User interation here (Do Modal)
	icmd.sendEvent(EVT_WORK, &curses);				// Curses work
	curses.onEvent(EVT_WORK, &icmd);

	// Keyboard enter here ?
	icmd.grammarWork()->onSelect();					// User select onComplete
	icmd.grammarWork()->onCancel();					// User do not select onComplete

	appUI.windowManager()->setActiveWindow(&icmd);

	return 0;
}

int CUserCaseDesign::cmdLineShowAutoCompletion()
{
	IApp app;
	ICursesCmdLine icmd;

	return 0;
}

int CUserCaseDesign::cmdLineDoQuiz()
{
	return 0;
}

int CUserCaseDesign::cmdLineOnResize()
{
	return 0;
}
