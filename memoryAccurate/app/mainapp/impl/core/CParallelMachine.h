/*
 * CParallelMachine.h
 *
 *  Created on: Jan 12, 2018
 *      Author: ducvd
 */

#ifndef APP_MAINAPP_IMPL_CORE_CPARALLELMACHINE_H_
#define APP_MAINAPP_IMPL_CORE_CPARALLELMACHINE_H_

#include "CStateMachine.h"
#include <vector>

class CParallelMachine: public CStateMachine {
public:
	CParallelMachine(IStateMachine* a_parallel_[]);
	~CParallelMachine();

	int getNextState_(int currentState, int msg, void* data = NULL);	// Calculate next state (calculate only, not change anything inside machine)

	// Events
	int onTransition_(int fromState, int toState, void* data=NULL);
	int onEnterState_(int theoldstate, void* data);
	int onLeaveState_(int state);
private:
	std::vector<IStateMachine*> _v_parallel;
};

#endif /* APP_MAINAPP_IMPL_CORE_CPARALLELMACHINE_H_ */
