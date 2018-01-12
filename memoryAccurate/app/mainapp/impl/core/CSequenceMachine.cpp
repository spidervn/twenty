/*
 * CSequenceMachine.cpp
 *
 *  Created on: Jan 12, 2018
 *      Author: ducvd
 */

#include <mainapp/impl/core/CSequenceMachine.h>

#define STATE_INIT_ 1
#define STATE_END__ 2
#define STATE_PROCESS 3

CSequenceMachine::CSequenceMachine() {
	q_event.clear();
	_v_sequence.clear();
}

CSequenceMachine::~CSequenceMachine() {
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
		int msg = _q_messages.front();
		void* data = _q_data.front();

		_q_messages.pop();
		_q_data.pop();

		step(msg, data);
	}
	
	return 0;
}

int CSequenceMachine::currentState_() 
{
	return state;
}

int CSequenceMachine::getNextState_(int currentState, int msg, void* data) 	// Calculate next state (calculate only, not change anything inside machine)
{
	int nextStt = STATE_INIT_;
	if (currentState == STATE_INIT_)
	{
		nextStt = STATE_PROCESS;
	}
	else
	{
		nextStt - STATE_END__;
	}

	return nextStt;
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
	}
	return 0;
}

// Events
int CSequenceMachine::onTransition_(int fromState, int toState, void* data)
{

}

int CSequenceMachine::onEnterState_(int theoldstate, void* data) 
{
	if (state == STATE_PROCESS && theoldstate == STATE_INIT_)
	{
		for (int i=0;i<_v_sequence.size();++i)
		{
			_v_sequence[i].step(0, data);
		}
	}
	
	return 0;
}

int CSequenceMachine::onLeaveState_(int state) 
{
	return 0;
}