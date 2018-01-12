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

template <class T>
typedef struct STRUCTStateMachineTransitRow
{
	int from_State_;	
	int toState;
	int 
} StateMachineTransit_Row;

typedef struct STRUCT_StateMachineEntryEvent
{
	int state;
	void* test();
} SM_EntryEvent;

typedef struct STRUCT_StateMachineCircuit
{
	int vertex[];
	std::vector<int> _vertex;

	StateMachineCircuit& defineVertex_(int v[])
	{
		int n = sizeof(v)/sizeof(int);

		_vertex.clear();		
		for (int i = 0; i < n; ++i)
		{
			_vertex.push_back(v[i]);
		}

		return this;
	}

	StateMachineCircuit& defineEntry(int v[])
	{		
		return this;
	}

	StateMachineCircuit& transitions()
	{

	}

} StateMachineCircuit;

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
