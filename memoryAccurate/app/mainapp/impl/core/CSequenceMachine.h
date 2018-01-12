/*
 * CSequenceMachine.h
 *
 *  Created on: Jan 12, 2018
 *      Author: ducvd
 */

#ifndef APP_MAINAPP_IMPL_CORE_CSEQUENCEMACHINE_H_
#define APP_MAINAPP_IMPL_CORE_CSEQUENCEMACHINE_H_

#include <mainapp/interface/core/IStateMachine.h>
#include <queue>
#include <vector>

class CSequenceMachine: public IStateMachine {
public:
	CSequenceMachine();
	virtual ~CSequenceMachine();

	int queueEvent_(int msg, void* data=NULL) ;	// Send to me - Not process
	int processNextQueue_() ;
	int currentState_() ;

	int getNextState_(int currentState, int msg, void* data = NULL) ;	// Calculate next state (calculate only, not change anything inside machine)
	int step(int msg, void* data = NULL) ;		// Send event then process immediately

	// Events
	int onTransition_(int fromState, int toState, void* data=NULL) ;
	int onEnterState_(int theoldstate, void* data) ;
	int onLeaveState_(int state) ;

private:
	std::queue<int> q_event;
	std::queue<void*> qdata;
	std::vector<IStateMachine*> _v_sequence;
};

#endif /* APP_MAINAPP_IMPL_CORE_CSEQUENCEMACHINE_H_ */
