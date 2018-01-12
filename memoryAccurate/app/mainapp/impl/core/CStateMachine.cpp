/*
 * CStateMachine.cpp
 *
 *  Created on: Jan 12, 2018
 *      Author: ducvd
 */

#include <mainapp/impl/core/CStateMachine.h>

CStateMachine::CStateMachine(int initial_State) {
	state = initial_State;

}

CStateMachine::~CStateMachine() {
}

int CSequenceMachine::queueEvent_(int msg, void* data=NULL) 	// Send to me - Not process
{
	q_event.push(msg);
	qdata.push(data);
	return 0;
}

int CSequenceMachine::processNextQueue_()
{
	int num_processed = 0;
	// Do not process more than 5 a time
	while (q_event.size() > 0 && num_processed < 5)
	{
		int msg = q_event.front();
		void* data = qdata.front();

		q_event.pop();
		qdata.pop();
		step(msg, data);
	}

	return 0;
}

int CSequenceMachine::currentState_()
{
	return state;
}

int CSequenceMachine::step(int msg, void* data) 		// Send event then process immediately
{
	int nextStt = getNextState_(state, msg, data);
	int old_Stt = state;

	if (state != nextStt)
	{
		onTransition_(state, nextStt, data);
		onLeaveState_(state);
		onTransition_(state, nextStt, data);

		state = nextStt;	// Change state
		onEnterState_(old_Stt, data);
	}
	else
	{
		// Internal state processing here ? Not need for sequence machine!
		// Internal processing ?
	}
	return 0;
}
