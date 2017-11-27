
#include <iostream>
#include <boost/msm/back/state_machine.hpp> // back-end
#include <boost/msm/front/state_machine_def.hpp> //front-end
#include <boost/msm/front/functor_row.hpp>
#include <stdlib.h>
#include <stdio.h>

namespace msm = boost::msm;
namespace mpl = boost::mpl;
using namespace boost::msm::front;

namespace
{
	//
	//	Program features
	//		Command line support
	//			- Take a memory Accuracy quiz
	//			- Display score
	//			- Define new Memory accuracy
	//			- Quit app
	//	States
	//		- CommandLine
	//		- DoingMemoryTest
	//		- DisplayScore
	//		- AddNewMemoryTest
	//

	// Events
	struct end_error {};
	struct command_line_doquiz {};
	struct command_line_display {};
	struct command_line_addnew {};
	struct command_line_quit {};	
	struct on_ok {};
	struct on_cancel {};
	
	// State Machine
	struct MemAccurate_: public msm::front::state_machine_def<MemAccurate_>
	{
		struct CommandLine: public msm::front::state<>
		{
			template <class Event,class FSM>
            void on_entry(Event const&,FSM& ) 
            {
            	std::cout << "entering: CommandLine" << std::endl;
            }

            template <class Event,class FSM>
            void on_exit(Event const&,FSM& ) 
            {
            	std::cout << "leaving: CommandLine" << std::endl;
           	}
		};

		struct DoingMemoryTest: public msm::front::state<>
		{
			template <class Event,class FSM>
            void on_entry(Event const&,FSM& ) 
            {
            		std::cout << "entering: DoingMemoryTest" << std::endl;
            }

            template <class Event,class FSM>
            void on_exit(Event const&,FSM& ) 
            {
            	std::cout << "leaving: DoingMemoryTest" << std::endl;
           	}
		};

		struct  DisplayScore: public msm::front::state<>
		{
			template <class Event,class FSM>
            void on_entry(Event const&,FSM& ) 
            {
            		std::cout << "entering: DisplayScore" << std::endl;
            }

            template <class Event,class FSM>
            void on_exit(Event const&,FSM& ) 
            {
            	std::cout << "leaving: DisplayScore" << std::endl;
           	}
		};

		struct AddNewMemoryTest: public msm::front::state<>
		{
			template <class Event,class FSM>
            void on_entry(Event const&,FSM& ) 
            {
            		std::cout << "entering: AddNewMemoryTest" << std::endl;
            }

            template <class Event,class FSM>
            void on_exit(Event const&,FSM& ) 
            {
            	std::cout << "leaving: AddNewMemoryTest" << std::endl;
           	}
		};

		struct ExitState: public msm::front::state<>
		{
			template <class Event,class FSM>
            void on_entry(Event const&,FSM& ) 
            {
            		std::cout << "entering: ExitState" << std::endl;
            }

            template <class Event,class FSM>
            void on_exit(Event const&,FSM& ) 
            {
            	std::cout << "leaving: ExitState" << std::endl;
           	}
		};
	
		struct AllOk: public msm::front::state<>
		{
		};

		struct ErrorMode: public msm::front::interrupt_state<end_error>
		{
		};

		// Guard conditions 
		typedef MemAccurate_ M;
		typedef CommandLine initial_state;

		// Transition table for MemAccurate
		struct transition_table : mpl::vector<
			//      Start     Event         Next      Action               Guard
        	//    +---------+-------------+---------+---------------------+----------------------+
			_row<CommandLine, command_line_addnew, AddNewMemoryTest >,
			_row<CommandLine, command_line_doquiz, DoingMemoryTest >,
			_row<CommandLine, command_line_display, DisplayScore >,
			_row<CommandLine, command_line_quit, ExitState >,
        	//    +---------+-------------+---------+---------------------+----------------------+
        	_row<AddNewMemoryTest, on_ok, CommandLine>,
        	_row<AddNewMemoryTest, on_cancel, CommandLine>,
			//    +---------+-------------+---------+---------------------+----------------------+        	
        	_row<DoingMemoryTest, on_ok, CommandLine>,
			_row<DoingMemoryTest, on_cancel, CommandLine>,
			//    +---------+-------------+---------+---------------------+----------------------+        	
			_row<DisplayScore, on_ok, CommandLine>,
			_row<DisplayScore, on_cancel, CommandLine>
		>{};

		// Replaces the default no-transition response.
        template <class FSM,class Event>
        void no_transition(Event const& e, FSM&,int state)
        {
            std::cout << "no transition from state " << state
                << " on event " << typeid(e).name() << std::endl;
        }
	};

	// Backend
	typedef msm::back::state_machine<MemAccurate_> MemAccurate;

	void test()
	{
		MemAccurate m;

		m.start();
		m.process_event(command_line_display());
		m.process_event(command_line_display());
		m.process_event(on_ok());
		m.process_event(command_line_addnew());
		m.process_event(on_cancel());
		m.process_event(command_line_quit());
		m.stop();
	}
};

// MVC Here 
namespace mvc
{
	// We choose Ncurses for MVC
	
}

int main(int argc, char const *argv[])
{
	const char* szTest = "Test";
	printf("%s\r\n", szTest);
	
	test();
	return 0;
}

