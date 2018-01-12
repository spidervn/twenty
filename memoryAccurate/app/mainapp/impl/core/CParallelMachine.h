/*
 * CParallelMachine.h
 *
 *  Created on: Jan 12, 2018
 *      Author: ducvd
 */

#ifndef APP_MAINAPP_IMPL_CORE_CPARALLELMACHINE_H_
#define APP_MAINAPP_IMPL_CORE_CPARALLELMACHINE_H_

#include <mainapp/interface/core/IStateMachine.h>

class CParallelMachine: public IStateMachine {
public:
	CParallelMachine();
	virtual ~CParallelMachine();
};

#endif /* APP_MAINAPP_IMPL_CORE_CPARALLELMACHINE_H_ */
