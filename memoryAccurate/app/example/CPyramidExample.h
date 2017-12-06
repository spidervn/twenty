/*
 * CPyramidExample.h
 *
 *  Created on: Dec 6, 2017
 *      Author: spider
 */

#ifndef APP_EXAMPLE_CPYRAMIDEXAMPLE_H_
#define APP_EXAMPLE_CPYRAMIDEXAMPLE_H_

#include "arch/pyramid.h"

class CPyramidExample : public IPyramid, public IPyramidArchitecture {
public:
	class UI;
	class Layout;
	class Event;

	CPyramidExample();
	virtual ~CPyramidExample();

	void designPyramid();

	UI* ui() { return _pui; }
	Layout* layout() { return _playout; }
	Event* event() { return _pevent; }

private:
	UI* _pui;
	Layout* _playout;
	Event* _pevent;
};

class CPyramidExample::UI : public IPyramid
{
public:
	class MenuSub;
	class Toolbar;
	class StatusBar;

	void drawModel() { printf("Draw Model"); }
	void refresh() { printf("Refresh"); }

	MenuSub* menu() { return _pmenu; }
	Toolbar* toolbar() { return _ptoolbar; }
	StatusBar* statusbar() { return _pstatus; }
private:
	MenuSub* _pmenu;
	Toolbar* _ptoolbar;
	StatusBar* _pstatus;
};

class CPyramidExample::Layout : public IPyramid
{
public:
	void dockElement() { printf("DockElement"); }
};

class CPyramidExample::Event : public IPyramid
{
public:
	void onEvent() { printf("onEvent\r\n"); }
	void onClick() { printf("Click"); }
	void registerEvent() { printf("Register Event"); }
};

class CPyramidExample::UI::MenuSub : public IPyramid
{
public:
	void addMenu() { printf("Add Menu"); }
	void removeMenu() { printf("Remove Menu"); }
	void destroyMenu() { printf("DestroyMenu"); }
};

class CPyramidExample::UI::StatusBar : public IPyramid
{
public:
	void getStatusName() { printf("StatusName");}
};

class CPyramidExample::UI::Toolbar : public IPyramid
{
public:
	void addToolbar() { printf("Add Toolbar");}
};

#endif /* APP_EXAMPLE_CPYRAMIDEXAMPLE_H_ */
