/*
 * CArchitectureView.cpp
 *
 *  Created on: Dec 1, 2017
 *      Author: ducvd
 */

#include <mainapp/design/CArchitectureView.h>
#include <arch/program_abstract.h>

// Top level view
CArchitectureView::CArchitectureView() {
}

CArchitectureView::~CArchitectureView() {
}

int CArchitectureView::viewCursesICmdLine()
{
	IProgram* icurses = NULL;
	IProgram* icmd = NULL;
	IProgram* iquiz = NULL;
	IProgram* arr[] = { icurses, icmd, iquiz };
	IUnknown* iapp = new CUnknownProg(arr,3);

	iapp->main();
	
	return 1;
}

int CArchitectureView::insideCursesCmdLine()
{
	IProgram* keyboard;
	IProgram* mouse;
	IUnknown* curses;
	IProgram* icmd;

	curses->add(keyboard);
	curses->add(mouse);
	curses->add(icmd);

	return 0;
}
