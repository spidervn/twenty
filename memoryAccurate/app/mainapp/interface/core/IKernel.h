/*
 * IKernel.h
 *
 *  Created on: Dec 16, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_INTERFACE_CORE_IKERNEL_H_
#define APP_MAINAPP_INTERFACE_CORE_IKERNEL_H_

#include "mainapp/interface/lib/IMemoryTest.h"
#include "mainapp/interface/lib/IGrammar.h"

class IKernel
{
public:
	virtual ~IKernel() {}

	virtual IGrammar* grammar() = 0;
	virtual IMemoryTest* memorytest_() = 0;
};



#endif /* APP_MAINAPP_INTERFACE_CORE_IKERNEL_H_ */
