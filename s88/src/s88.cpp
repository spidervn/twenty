//============================================================================
// Name        : s88.cpp
// Author      : ducvd
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#include "IMemoryUnit.h"
#include "IMemoryRegion.h"
#include "ioutbox.h"

#include <boost/msm/back/state_machine.hpp>
#include <boost/msm/front/state_machine_def.hpp>
#include <iostream>


using namespace std;
using namespace boost;

/*
 * State machine for memory unit
 *	Including
 *
 */

namespace
{
	// What do you actually do inside actions/guards?
	template<class Fire>
	void send_rocket(Fire const&)
	{
		fire_rocket();
	}

	// Event
	struct Fire { int direction; };
	template<class Fire> void send_rocket(Fire const& evt)
	{
		fire_rocket(evt.direction);
	}

	struct launcher_: public msm::front::state_machine_def<launcher_>
	{
		int current_calculation;

		template<class Fire>
		void send_rocket(Fire const& evt)
		{
			fire_rocket(evt.direction, current_calculation);
		}

		//---
		struct Launching: public msm::front::state<>
		{
			template<class Event, class Fsm>
			void on_entry(Event const& evt, Fsm& fsm)
			{
				fire_rocket(evt.direction, fsm.current_calculation);
			}
		};
	};
};

int main() {
	cout << "!!!Hello World!!!" << endl;
	printf("---- Pulzze (Accuracy)");

	/*
	 * State definition
	 *	=> Remember item
	 *		=> 5_breakdown = Parse item into 05 pieces (W, E,N, S, C)
	 */

	vector<int> v1;

	v1.push_back(1);
	v1.push_back(2);

	IMemoryRegion* pMr;
	IMemoryUnit* pWorldClass;

	IOutbox* outbox;

	outbox->addOutboxItem(NULL);	// Out of the box
	outbox->addOutboxItem(NULL);

	// Different


	// Word order

	return 0;
}
