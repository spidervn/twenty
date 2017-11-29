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

	int EVT_ON_CMD = 0;
	int EVT_DO_MODAL = 1;

	pApp.start();

	icmd.initialize();
	icmd.declareEvents();

	icmd.onExeCmd();	// Execute command here
	quiz.doModal();		// Show quiz here
						// ...
	return 0;
}

int CUserCaseDesign::cmdLineTyping()
{
	IApp app;
	ICursesCmdLine icmd;
	IAutoComplete icomplete;
	vector<string> vhints;

	icmd.getEventHandle()->onTyping();
	vhints = icomplete.autoComplete("", "");
	icmd.viewAutoComplete();
	icmd.processAutoComplete();

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
