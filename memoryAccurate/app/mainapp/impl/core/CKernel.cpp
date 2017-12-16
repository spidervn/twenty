/*
 * CKernel.cpp
 *
 *  Created on: Dec 16, 2017
 *      Author: spider
 */

#include <mainapp/impl/core/CKernel.h>
#include "mainapp/impl/lib/CGrammar.h"
#include "mainapp/impl/lib/CMemoryTest.h"

IKernel* CKernel::kernel = new CKernel();

CKernel::CKernel() {
	_pgrammar__ = new CGrammar();
	_pmtest = new CMemoryTest();
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
