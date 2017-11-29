/*
 * CUserCaseDesign.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: spider
 */

#include "CUserCaseDesign.h"

#include <architecture.h>
#include <mainapp/IApp.h>

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
	icmd.registerEvent(EVT_ON_CMD, &quiz, EVT_DO_MODAL);



	return 0;
}

int CUserCaseDesign::cmdLineTyping()
{
	return 0;
}

int CUserCaseDesign::cmdLineShowAutoCompletion()
{
	return 0;
}

int CUserCaseDesign::cmdLineDoQuiz()
{
	return 0;
}
