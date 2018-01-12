/*
 * CStateMachine.h
 *
 *  Created on: Jan 12, 2018
 *      Author: ducvd
 */

#ifndef APP_MAINAPP_IMPL_CORE_CSTATEMACHINE_H_
#define APP_MAINAPP_IMPL_CORE_CSTATEMACHINE_H_

#include <mainapp/interface/core/IStateMachine.h>

class CStateMachine: public IStateMachine {
public:
	CStateMachine();
	virtual ~CStateMachine();

	int queueEvent_(int msg, void* data=NULL) = 0;	// Send to me - Not process
	int processNextQueue_() = 0;
	int currentState_() = 0;

	int getNextState_(int currentState, int msg, void* data = NULL) = 0;	// Calculate next state (calculate only, not change anything inside machine)
	int step(int msg, void* data = NULL) = 0;		// Send event then process immediately

	// Events
	int onTransition_(int fromState, int toState, void* data=NULL) = 0;
	int onEnterState_(int theoldstate, void* data) = 0;
	int onLeaveState_(int state) = 0;
private:
	
};

#endif /* APP_MAINAPP_IMPL_CORE_CSTATEMACHINE_H_ */
