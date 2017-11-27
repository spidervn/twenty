#ifndef MEMORY_ACCURATE_ARCHITECTURE_H_
#define MEMORY_ACCURATE_ARCHITECTURE_H_

#include <stdio.h>
#include <string>
#include <vector>
#include <ncurses.h>
#include <menu.h>
#include "arch/pyramid.h"

class IUIEngine
{
public:
    virtual void initialize() {}
    virtual void start() {}
    virtual void run() {}
    virtual ~IUIEngine() {};
};

class ILogicEngine
{
public:
    virtual void run() {}
    virtual ~ILogicEngine() {}
};

class IModel
{
public:
    void* getData() { return NULL; }
    virtual ~IModel() {}
};

class IComponent
{
public:
	virtual int initialize() { return 0; }
	virtual int shutdown() { return 0; }
	virtual std::string name() { return ""; }
	virtual int main() { return 0; }			// Main procedure
	virtual ~IComponent() {};
};

/*
 * Curses engine
 * 	i. Provide interface for completed curses engine.
 * 	ii. No detail implementation
 *
 */
class ICursesEngine : public IComponent
{
public:
	/*
	 * Initialize all curses here
	 * 	i. raw or noraw
	 * 	ii. cbreak/halfmode/keypad ...
	 */
	// Workflow functions
	virtual void initialize() {};		// Force to call
	virtual void shutdown() {};			// How to force calling
	virtual int start() { return 0; }
	/*
	 * Show all application logic by curses
	 */

	virtual int addWindow() { return 0; }
	virtual int addPanel() { return 0; }
	virtual int addMenu(WINDOW* win, MENU* m) { return 0; }
	virtual int declareEvent(int eventCode, void* function) { return 0; }


	virtual ~ICursesEngine();
};

class IMemoryAccurateApp : public IComponent
{
	/*
	 * Rules:
	 * 	1. MUST call initialize before start
	 * 	2. Start all Components inside start
	 *
	 */
	std::vector<IComponent> _components;
public:
	virtual void registerComponent(IComponent& comp)
	{
		_components.push_back(comp);
	}

	virtual int initialize()
	{
		for (int i = 0; i< _components.size(); ++i) {
			_components[i].initialize();
		}

		return 1;
	}

	virtual void start()
	{
	}

	virtual void stop()
	{
	}
};

class ICursesPyr : public IPyramidPenta
{
protected:

public:
	virtual int initialize()
	{
		return 0;	// Init curses&mode + declare all windows/panel/menu
	}

	virtual int shutdown()
	{
		return 0;	// shutdown curses
	}

	virtual int getModel()
	{
		return 0;
	}

	virtual int main()
	{
		return 0;	// main procedure of functions (Million line of code inside here)
	}

};

class IWindowManagerPyr
{

};

#endif
