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

		template<class Event, class Fsm>
		void on_entry(Event const& evt, Fsm& fsm)
		{
			// Pass data to substates/sub machines
			launcher_::Launching& s = fms.get_state<launcher_::Launching&>();
			s.data = fms.current_calculation;
		}

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

	struct player_: public msm::front::state_machine_def<player_>
	{
		/* see below */
		typedef Empty initial_state;

		typedef msm::back::state_machine<player_> player;

		template <class Fsm, class Event>
		void no_transition(Event const& e, Fsm&, int state)
		{
			// Implementation here
		}

		struct Playing_: public msm::front::state_machine_def<Playing_>
		{
			struct transition_table: mpl::vector<
				// Start	Event	Target	Action Guard
				a_row< Song1, 	NextSong, Song2, &Playing_::start_next_song >,
				a_row< Song2, 	NextSong, Song1, &Playing_::start_prev_song >,
				a_row< Song2, 	NextSong, Song3, &Playing_::start_next_song >,
				a_row< Song3, 	NextSong, Song2, &Playing_::start_prev_song >,
			>{};

			typedef Song1 initial_state;
		};

		typedef msm::back::state_machine<Playing_> Playing;
	};

	BOOST_MPL_HAS_XXX_TRAIT_DEF(some_event_property)

	struct event1
	{
		// The property
		typedef int some_event_property;

		// the method required by this property
		void some_property()
		{
		}
	};

	// This event does not supports some_event_property
	struct event2
	{
	};

	struct some_state: public msm::front::state<>
	{
		template<class Event, class Fsm>
		// enable this version for events supporting some_event_property
		typename boost::enable_if<typename has_some_event_property<Event>::type, void>::type 
		on_entry(Event const& evt, Fsm& fsm)
		{
			evt.some_property();
		}

		// For events not supporting some_event_property
		template<class Event, class Fsm> 
		typename boost::disable_if<typename has_some_event_property<Event>::type, void>::type 
		on_entry(Event const&, Fsm&)
		{
		}
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
	outbox->addOutboxItem(NULL);
	// Different


	// Word order

	return 0;
}
