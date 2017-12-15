/*
 * CArchitectureView.cpp
 *
 *  Created on: Dec 1, 2017
 *      Author: ducvd
 */

#include <mainapp/design/CArchitectureView.h>
#include <arch/program_abstract.h>
#include "mainapp/interface/ncurses/ICursesApp.h"
#include "mainapp/interface/ui/ICursesCmdLine.h"
#include "mainapp/interface/ui/ICursesWinQuiz.h"

// Top level view
CArchitectureView::CArchitectureView() {
}

CArchitectureView::~CArchitectureView() {
}

int CArchitectureView::viewCursesICmdLine()
{
	// View01: by program
	IProgram* icurses = NULL;
	IProgram* icmd = NULL;
	IProgram* iquiz = NULL;
	IProgram* arr[] = { icurses, icmd, iquiz };
	IUnknown* iapp = new CUnknownProg(arr,3);

	iapp->main();
	
	// View02: by application
	ICursesApp* pApp;
	ICursesCmdLine* pIcmd;
	ICursesWinQuiz* pIquiz;
	int EVT_ONCLICK = 0;

	pApp->initialize();
	pApp->registerUI(pIcmd);
	pApp->registerUI(pIquiz);

	pApp->onEvent(EVT_ONCLICK);

	return 1;
}

int CArchitectureView::insideCursesCmdLine()
{
	// View01: Program based
	IProgram* keyboard;
	IProgram* mouse;
	IUnknown* curses;
	IProgram* icmd;

	curses->add(keyboard);
	curses->add(mouse);
	curses->add(icmd);

	//Viewo02: application abstraction logic
	// Single thread
	ICursesApp* pApp;
	ICursesCmdLine* pCmdLine;

	pApp->main();
	
	while (1)	// Detail of main
	{
		int newEvent = 1;	// Whatever do to get EventHere		
		{
			pApp->onEvent(newEvent);	// Send Event to pApp first
			pApp->getActiveUI()->onEvent(newEvent, NULL);	// Send Event & Data to active UI
			// Inside activeUI->onEvent
			{
				// Do anything then quit

				// Special cases
				//	i. Action too long ?
				//	ii. External cases
				//		ii.1. Call other UI functions?
				//		ii.2. Call pApp event ?
			
				// i. Action too long ?
				//	=> Wait action quit.				


				// ii. External cases
				//	ii.1. Call other UI functions
				//		pApp->event()->queue(OTHER_UI_EVENT);
				//		then quit.
				//	
				//		Do not directly call that UI.
				//			Example 
				//			pApp->getAnotherUI()->callFunction();
				//				=> callFunction() must be private function.
				//
				//	ii.2. Call other UI functions
				//		pApp->event()->queue(OTHER_UI_EVENT);
				//		
				//		

				// pApp->sendEvent(eventName, destination);

				// SingleThread EventQueue.
				//

				// IEventDispatcher();
				// IEventSender();
			}
		}

		// Change UI
		{
			/*
			ICursesUI* pNewUI;
			pApp->getActiveUI()->tear_down();	// Shut down App
			pNewUI->init_curses_mode();			// Initialize new

			pApp->ui()->getActiveUI();
			pApp->ui()->setActiveUI(NULL);
			pApp->event()->setActiveUI(NULL);
			*/
		}
	}

	return 0;
}
