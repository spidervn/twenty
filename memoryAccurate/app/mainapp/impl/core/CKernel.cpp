/*
 * CKernel.cpp
 *
 *  Created on: Dec 16, 2017
 *      Author: spider
 */

#include "CKernel.h"
#include "mainapp/impl/lib/CGrammar.h"
#include "mainapp/impl/lib/CMemoryTest.h"
#include "mainapp/impl/ncurses/CCursesApp.h"

IKernel* CKernel::kernel = new CKernel();

CKernel::CKernel() {
	_pgrammar__ = new CGrammar();
	_pmtest = new CMemoryTest();
	_pApp = new CCursesApp();
}

CKernel::~CKernel() {
}

IKernel* CKernel::Instance()
{
	return kernel;
}

IGrammar* CKernel::grammar()
{
	return _pgrammar__;
}

IMemoryTest* CKernel::memorytest_()
{
	return _pmtest;
}

ICursesApp* CKernel::curses_app_()
{
	return _pApp;
}
