/*
 * CKernel.h
 *
 *  Created on: Dec 16, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_IMPL_CORE_CKERNEL_H_
#define APP_MAINAPP_IMPL_CORE_CKERNEL_H_

#include "mainapp/interface/core/IKernel.h"
#include "mainapp/interface/ncurses/ICursesApp.h"
#define KERNEL CKernel::Instance()

class CKernel: public IKernel {
private:
	CKernel();
	static IKernel* kernel;

	IGrammar* _pgrammar__;
	IMemoryTest* _pmtest;
	ICursesApp* _pApp;
	IDatabase* _pDatabase_;
public:
	static IKernel* Instance();
	virtual ~CKernel();

	IGrammar* grammar();
	IMemoryTest* memorytest_();
	ICursesApp* curses_app_();
	IDatabase* db() { return _pDatabase_; }
};

#endif /* APP_MAINAPP_IMPL_CORE_CKERNEL_H_ */
