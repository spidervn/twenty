/*
 * CUserCaseDesign.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: spider
 */

#include "CUserCaseDesign.h"

#include <architecture.h>
#include <mainapp/IApp.h>
#include <mainapp/ui/ICursesCmdLine.h>
#include <mainapp/ui/ICursesWinQuiz.h>
#include <mainapp/lib/IAutoComplete.h>
#include <mainapp/lib/ICommandParser.h>

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
	IApp app;
	ICursesCmdLine icmd;
	ICommandParser iparser;
	vector<string> vhints;

	icmd.eventHandler()->onTyping();
	vhints = iparser.autoComplete("", "");
	icmd.grammarWork()->showAutoComplete(vhints);	// User interation here

	icmd.grammarWork()->onSelect();					// User select onComplete
	icmd.grammarWork()->onCancel();					// User do not select onComplete

	// ON_ENTER inside GrammarWork auto complete?

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
