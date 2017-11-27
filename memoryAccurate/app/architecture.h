#ifndef MEMORY_ACCURATE_ARCHITECTURE_H_
#define MEMORY_ACCURATE_ARCHITECTURE_H_

#include <stdio.h>
#include <string>
#include <vector>

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
	virtual std::string name() { return ""; }
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
	virtual void initialize() {};

	/*
	 * Show all application logic by curses
	 */
	virtual void showApp() {};

	virtual std::vector<IComponent> getDependencies() { return std::vector<IComponent>(); }

	virtual ~ICursesEngine();


};

#endif
