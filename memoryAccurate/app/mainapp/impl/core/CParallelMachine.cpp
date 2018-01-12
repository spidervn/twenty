/*
 * CParallelMachine.cpp
 *
 *  Created on: Jan 12, 2018
 *      Author: ducvd
 */

#include <mainapp/impl/core/CParallelMachine.h>

#define STATE_INIT_ 1
#define STATE_END__ 2
#define STATE_PROCESS 3

CParallelMachine::CParallelMachine(IStateMachine* a_parallel_[])
{
	int n = sizeof(a_parallel_)/sizeof(IStateMachine*);
	_v_parallel.clear();

	for (int i = 0; i < n; ++i)
	{
		_v_parallel.push_back(a_parallel_[i]);
	}
}

CParallelMachine::~CParallelMachine()
{
}

int CParallelMachine::getNextState_(int currentState, int msg, void* data = NULL)	// Calculate next state (calculate only, not change anything inside machine)
{
	if (currentState == STATE_INIT_)
	{
		return STATE_PROCESS;
	}
	else
	{
		return STATE_END__;
	}
}

// Events
int CParallelMachine::onTransition_(int fromState, int toState, void* data=NULL)
{
	return 0;
}

int CParallelMachine::onEnterState_(int theoldstate, void* data)
{
	if (currentState_() == STATE_PROCESS && theoldstate == STATE_INIT_)
	{
		for (int i = 0; i < _v_parallel.size(); ++i) {
			_v_parallel[i]->step(NULL, data);
		}
	}

	return 0;
}

int CParallelMachine::onLeaveState_(int state)
{
	return 0;
}
