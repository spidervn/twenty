#include <iostream>

#include <boost/msm/back/state_machine.hpp>
#include <boost/msm/front/state_machine_def.hpp>
#include <iostream>

namespace msm = boost::msm;
namespace mpl = boost::mpl;
using namespace std;

namespace
{
    // events
    struct play {};
    struct end_pause {};
    struct stop {};
    struct pause {};
    struct open_close {};

    // A "complicated" event type that carries some data
    enum DiskTypeEnum
    {
        DISK_CD = 0,
        DISK_DVD = 1
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

    // font-end: define the FSM structure
    struct player_ : public msm::front::state_machine_def<player_>
    {
        template<class Event, class FSM>
        void on_entry(Event const&, FSM&)
        {
            std::cout << "entering: Player" << std::endl;
        }

        // The list of FSM states
        struct Empty : public msm::front::state<>
        {
            // every (optional) entry/exit methods get the event passed.
            template<class Event,class FSM>
            void on_entry(Event const&, FSM&)
            {
                cout << "entering: Empty" << std::endl;
            }

            template<class Event,class FSM>
            void on_exit(Event const&, FSM& )
            {
                cout << "leaving: Empty" << endl;
            }
        };

        struct Open: public msm::front::state<>
        {
            template<class Event, class FSM>
            void on_entry(Event const&, FSM&)
            {
                std::cout << "entering: Open" << std::endl;
            }

            template<class Event, class FSM>
            void on_exit(Event const&, FSM&)
            {
                std::cout << "Leaving: Open" << std::endl;
            }
        };

        struct Stopped: public msm::front::state<msm::front::default_base_state, msm::front::sm_ptr>
        {
            template<class Event, class FSM>
            void on_entry(Event const&, FSM&)
            {
                std::cout << "entering: Stopped" << endl;
            }

            template<class Event, class FSM>
            void on_exit(Event const&, FSM&)
            {
                std::cout << "leaving: Stopped" << std::endl;
            }

            void set_sm_ptr(player_* pl)
            {
                m_player = pl;
            }

            player_* m_player;
        };

        struct Playing: public msm::front::state<>
        {
            template<class Event, class FSM>
            void on_entry(Event const&, FSM&)
            {
                std::cout << "entering: Playing" << endl;
            }

            template<class Event, class FSM>
            void on_exit(Event const&, FSM&)
            {
                std::cout << "leaving: Playing" << endl;
            }
        };

        struct Paused: public msm::front::state<>
        {

        };

        typedef Empty initial_state;

        // transition actions
        void start_playback(play const&) { cout << "Player::start_playback\n"; }
        void open_drawer(open_close const&) { cout << "player::open_drawer\n"; }
        void close_drawer(open_close const&) { cout << "player::close_drawer\n";}
        void store_cd_info(cd_detected const&) { cout << "player::store_cd_info\n"; }
        void stop_playback(stop const&) { cout << "player::stop_playback\n";}
        void pause_playback(pause const&) { cout << "player::pause_playback\n"; }
        void resume_playback(end_pause const&) { cout << "player::resume_playback\n"; }
        void stop_and_open(open_close const&) { cout << "player::stop_and_open\n"; }
        void stopped_again(stop const&) { cout  << "player::stopped_again\n";}

        // guard conditions
        bool good_disk_format(cd_detected const& evt)
        {
            // to test a guard condition, let's say we understand only CDs, not DVD
            if (evt.disc_type != DISK_CD)
            {
                cout << "wrong disk, sorry" << endl;
                return false;
            }

            return true;
        }

        // used to show a transition conflict. This guard will simply deactivate one transition ans thus solve the conflict
        bool auto_start(cd_detected const&)
        {
            return false;
        }

        typedef player_ p;	// makes transition table cleaner

        // transition table for player
        struct transition_table: mpl::vector<
            // Start 	Event		Next 	Action		Guard
            a_row< Stopped, play,	Playing, &p::start_playback>,
            a_row< Stopped, open_close, Open, &p::open_drawer>,
            _row< Stopped, stop, Stopped>,
            a_row<Open, open_close, Empty, &p::close_drawer >,

            a_row<Empty, open_close, Open,  &p::open_drawer>,

            row<Empty, cd_detected, Stopped, &p::store_cd_info, &p::good_disk_format >,
            row<Empty, cd_detected, Playing, &p::store_cd_info, &p::auto_start>,

            a_row<Playing, stop, Stopped, &p::stop_playback >,
            a_row<Playing, pause, Paused, &p::pause_playback >,
            a_row<Playing, open_close, Open, &p::stop_and_open >,

            a_row<Paused, end_pause, Playing, &p::resume_playback >,
            a_row<Paused, open_close, Open, &p::stop_and_open >
        > {};

        // Replaces the default no-transition response
        template<class FSM, class Event>
        void no_transition(Event const& e, FSM&, int state)
        {
            cout << "No transition from state  " << state
                    << " on event" << typeid(e).name() << endl;
        }
    };

    // Pick a back-end
    typedef msm::back::state_machine<player_> player;

    static char const* const state_names[] = { "Stopped", "Open", "Empty", "Playing", "Paused" };

    void pstate(player const& p)
    {
            cout << " -> " << state_names[p.current_state()[0]] << endl;
    }

    void test()
    {
        player p;
        // needed to start the highest-level SM. This will call on_entry and mark tne start of SM

        p.start();

        p.process_event(open_close());	pstate(p);
        p.process_event(open_close()); pstate(p);

        p.process_event(cd_detected("louie, louie", DISK_DVD));	pstate(p);
        p.process_event(cd_detected("louie, louie", DISK_CD)); pstate(p);

        p.process_event(pause());	pstate(p);

        p.process_event(end_pause()); pstate(p);
        p.process_event(pause()); pstate(p);
        p.process_event(stop()); pstate(p);

        p.process_event(stop()); pstate(p);
        cout << "stop fsm" << endl;
        p.stop();
    }
};

int main()
{
    cout << "Hello world!" << endl;

    test();
    return 0;
}
