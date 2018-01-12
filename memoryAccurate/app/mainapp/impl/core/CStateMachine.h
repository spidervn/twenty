/*
 * CStateMachine.h
 *
 *  Created on: Jan 12, 2018
 *      Author: ducvd
 */

#ifndef APP_MAINAPP_IMPL_CORE_CSTATEMACHINE_H_
#define APP_MAINAPP_IMPL_CORE_CSTATEMACHINE_H_

#include <mainapp/interface/core/IStateMachine.h>
#include <queue>
#include <vector>

class CStateMachine: public IStateMachine {
public:
	CStateMachine(int initial_State);
	virtual ~CStateMachine();

	int queueEvent_(int msg, void* data=NULL);	// Send to me - Not process
	int processNextQueue_();
	int currentState_();

	int step(int msg, void* data = NULL);		// Send event then process immediately
	/*
	int getNextState_(int currentState, int msg, void* data = NULL) = 0;	// Calculate next state (calculate only, not change anything inside machine)

	// Events
	int onTransition_(int fromState, int toState, void* data=NULL) = 0;
	int onEnterState_(int theoldstate, void* data);
	int onLeaveState_(int state);
	*/
private:
	std::queue<int> q_event;
	std::queue<void*> qdata;

	int state;
};

#endif /* APP_MAINAPP_IMPL_CORE_CSTATEMACHINE_H_ */
