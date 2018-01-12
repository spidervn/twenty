/*
 * IStateMachine.h
 *
 *  Created on: Dec 19, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_INTERFACE_CORE_ISTATEMACHINE_H_
#define APP_MAINAPP_INTERFACE_CORE_ISTATEMACHINE_H_

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>

class IStateMachine
{
public:
	virtual ~IStateMachine() {};

	virtual int queueEvent_(int msg, void* data=NULL) = 0;	// Send to me - Not process
	virtual int processNextQueue_() = 0;
	virtual int currentState_() = 0;

	virtual int getNextState_(int currentState, int msg, void* data = NULL) = 0;	// Calculate next state (calculate only, not change anything inside machine)
	virtual int step(int msg, void* data = NULL) = 0;		// Send event then process immediately

	// Events
	virtual int onTransition_(int fromState, int toState, void* data=NULL) = 0;
	virtual int onEnterState_(int theoldstate, void* data) = 0;
	virtual int onLeaveState_(int state) = 0;
};

#endif /* APP_MAINAPP_INTERFACE_CORE_ISTATEMACHINE_H_ */
