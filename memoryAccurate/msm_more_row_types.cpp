#include <iostream>
// back-end
#include <boost/msm/back/state_machine.hpp>
//front-end
#include <boost/msm/front/state_machine_def.hpp>
#include <boost/msm/front/row2.hpp>

namespace msm = boost::msm;
namespace mpl = boost::mpl;
using namespace msm::front;

namespace
{
    // events
    struct play {};
    struct end_pause {};
    struct stop {};
    struct pause {};
    struct open_close {};


    // A "complicated" event type that carries some data.
    enum DiskTypeEnum
    {
        DISK_CD=0,
        DISK_DVD=1
    };
    struct cd_detected
    {
        cd_detected(std::string name, DiskTypeEnum diskType)
            : name(name),
            disc_type(diskType)
        {}

        std::string name;
        DiskTypeEnum disc_type;
    };

     // front-end: define the FSM structure 
    struct player_ : public msm::front::state_machine_def<player_>
    {
    	template <class Event,class FSM>
        void on_entry(Event const& ,FSM&) 
        {
            std::cout << "entering: Player" << std::endl;
        }
        template <class Event,class FSM>
        void on_exit(Event const&,FSM& ) 
        {
            std::cout << "leaving: Player" << std::endl;
        }
        // The list of FSM states
        struct Empty : public msm::front::state<> 
        {
        	// every (optional) entry/exit methods get the event passed.
            template <class Event,class FSM>
            void on_entry(Event const&,FSM& ) {std::cout << "entering: Empty" << std::endl;}
            template <class Event,class FSM>
            void on_exit(Event const&,FSM& ) {std::cout << "leaving: Empty" << std::endl;}
            void open_drawer(open_close const&)    { std::cout << "Empty::open_drawer\n"; }
            // actions for Empty's internal transitions
            void internal_action(cd_detected const&){ std::cout << "Empty::internal action\n"; }
            bool internal_guard(cd_detected const&)
            {
                std::cout << "Empty::internal guard\n";
                return false;
            }
        };

        struct Open : public msm::front::state<> 
        { 
        	template <class Event,class FSM>
            void on_entry(Event const& ,FSM&) {std::cout << "entering: Open" << std::endl;}
            template <class Event,class FSM>
            void on_exit(Event const&,FSM& ) {std::cout << "leaving: Open" << std::endl;}
            void close_drawer(open_close const&)   { std::cout << "Open::close_drawer\n"; }
            void stop_and_open(open_close const&)  { std::cout << "Open::stop_and_open\n"; }
        };
        // sm_ptr still supported but deprecated as functors are a much better way to do the same thing
        struct Stopped : public msm::front::state<msm::front::default_base_state,msm::front::sm_ptr> 
        { 
        	template <class Event,class FSM>
            void on_entry(Event const& ,FSM&) {std::cout << "entering: Stopped" << std::endl;}
            template <class Event,class FSM>
            void on_exit(Event const&,FSM& ) {std::cout << "leaving: Stopped" << std::endl;}
            void set_sm_ptr(player_* pl)
            {
                m_player=pl;
            }
            player_* m_player;
            void start_playback(play const&)       { std::cout << "Stopped::start_playback\n"; }
            void stop_playback(stop const&)        { std::cout << "Stopped::stop_playback\n"; }
        };

        struct Playing : public msm::front::state<>
        {
            template <class Event,class FSM>
            void on_entry(Event const&,FSM& ) {std::cout << "entering: Playing" << std::endl;}
            template <class Event,class FSM>
            void on_exit(Event const&,FSM& ) {std::cout << "leaving: Playing" << std::endl;}
            // guard conditions
            // used to show a transition conflict. This guard will simply deactivate one transition and thus
            // solve the conflict
            bool auto_start(cd_detected const&)
            {
                return false;
            }
        };
        
    };
}


