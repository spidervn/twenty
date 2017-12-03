/*
 * CCmdLineUI.cpp
 *
 *  Created on: Dec 1, 2017
 *      Author: ducvd
 */

#include "mainapp/impl/ui/CCmdLineUI.h"
#include <string>
#include <stdlib.h>
#include <ncurses.h>			/* ncurses.h includes stdio.h */
#include <curses.h>
#include <string.h>
#include <menu.h>

#include "mainapp/interface/model/cmdline_model.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

using namespace std;

class CCmdLineUI::Toolkit
{
public:
	static void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);
	static WINDOW* createWindowMenu(int starty, int startx, MENU* my_menu);
	static void destroyWindowMenu(WINDOW*, MENU*);
	static void destroyWin(WINDOW* win);
	static WINDOW *create_newwin(int height, int width, int starty, int startx);
	static void destroy_win(WINDOW *local_win);

	static void handleResiz();
};

CCmdLineUI::CCmdLineUI() {
	pEvent = new EventHandler();
	pGrammar = new GrammarWork();
	pUI = new UI();
}

CCmdLineUI::~CCmdLineUI() {
	delete pEvent;
	delete pGrammar;
}

int CCmdLineUI::initialize()
{
	return 0;
}

int CCmdLineUI::run()
{
	int ch;
	ITEM **my_items;
	MENU *my_menu;
	WINDOW* mywin = NULL;
	int n_choices, i;
	int PAIR_BLUE = 1;
	int PAIR_MAGENTA = 2;
	int PAIR_GREEN = 3;
	bool isCursor = false;
	CmdLineModel cmdLine;
	string strCurrentCmd("");

	cmdLine.outputHistory.push_back("ls -lah");
	cmdLine.outputHistory.push_back("tpcdump 0001");

	initscr();			/* Start curses mode 		*/
	raw();				/* Line buffering disabled	*/
	start_color();
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	noecho();			/* Don't echo() while we do getch */
	// halfdelay(10);

	init_pair(PAIR_BLUE, COLOR_WHITE, PAIR_BLUE);
	init_pair(PAIR_MAGENTA, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(PAIR_GREEN, COLOR_WHITE, COLOR_GREEN);

	// Menu Initialization
	const char *choices[] = {
		"Choice 1",
		"Choice 2",
		"Choice 3",
		"Choice 4",
		"Exit"
	};

	n_choices = ARRAY_SIZE(choices);
	my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));

	for(i = 0; i < n_choices; ++i) {
		my_items[i] = new_item(choices[i], choices[i]);
		set_item_userptr(my_items[i], NULL);
	}

	my_items[n_choices] = (ITEM *)NULL;
	my_menu = new_menu((ITEM **)my_items);

	set_menu_format(my_menu, 5, 1);
	set_menu_fore(my_menu,  COLOR_PAIR(PAIR_BLUE) | A_REVERSE);
	set_menu_back(my_menu, COLOR_PAIR(PAIR_MAGENTA));
	set_menu_back(my_menu, COLOR_PAIR(PAIR_GREEN));
	set_menu_mark(my_menu, " * "); /* Set menu mark to the string " * " */


	printw("Type any character to see it in bold\n");
	printw("Type any character to see it in bold\n");
	printw("Type any character to see it in bold\n");
	for (unsigned int i=0;i<cmdLine.outputHistory.size();i++)
	{
		char szBuff[200];
		sprintf(szBuff, "# %s\n", cmdLine.outputHistory[i].c_str());
		printw(szBuff);
	}

	while (1)
	{
		ch = getch();			/* If raw() hadn't been called
									* we have to press enter before it
									* gets to the program 		*/
		if(ch == KEY_F(1))		/* Without keypad enabled this will */
		{
			printw("F1 Key pressed");/*  not get to us either	*/
										/* Without noecho() some ugly escape
										 * charachters might have been printed
										 * on screen			*/
			break;
		}
		else if (ch == KEY_ENTER || ch == 13 || ch == 10)
		{
			int y, x;
			//printw("\r\n");
			printw("\n");
			printw("# ");
			strCurrentCmd = "";
			// mvwprintw(stdscr, y+1, 0, "# ");
			// move(y+1,0);
		}
		else if (ch == KEY_LEFT)
		{
			int y,x;
			getyx(stdscr, y, x);
			move(y,x-1);
		}
		else if (ch == KEY_RIGHT)
		{
			int y,x;
			getyx(stdscr, y, x);
			move(y,x+1);
		}
		else if (ch == 'r' || ch == 'R')
		{
			if (isCursor)
				curs_set(1);
			else
				curs_set(0);
			isCursor = !isCursor;
		}
		else if (ch == 'a' or ch == 'A')
		{
			int y, x;
			int menuy, menux;
			int screenRows, screenCols;
			int c;
			bool bExitMenu = false;
			getyx(stdscr, y, x);
			getmaxyx(stdscr, screenRows, screenCols);
			char szMenuSelected[255];

			// Turn off echo
			noecho();
			pUI->layout()->arrangePopup(y+1, x,screenCols, screenCols, 10, 40, menuy, menux);
			Toolkit::destroyWindowMenu(mywin, my_menu);
			mywin = Toolkit::createWindowMenu(menuy,menux,my_menu);

			while(!bExitMenu && (c = wgetch(mywin)) != 'q' )
			{
				switch(c)
				{
					case KEY_DOWN:
						menu_driver(my_menu, REQ_DOWN_ITEM);
						break;
					case KEY_UP:
						menu_driver(my_menu, REQ_UP_ITEM);
						break;
					case KEY_NPAGE:
						menu_driver(my_menu, REQ_SCR_DPAGE);
						break;
					case KEY_PPAGE:
						menu_driver(my_menu, REQ_SCR_UPAGE);
						break;
					case 10:
					case 13:
						bExitMenu = true;
						ITEM* curItem;
						curItem = current_item(my_menu);
						strcpy(szMenuSelected, item_name(curItem));
						break;
				}
				wrefresh(mywin);
			}

			// Turn on echo
			echo();
			move(y,x);
			// clrtoeol();
			mvprintw(y,x, szMenuSelected);
			Toolkit::destroyWindowMenu(mywin, my_menu);
			mywin = NULL;

			wrefresh(stdscr);
		}
		else if (ch == 'q' or ch =='Q')
		{
			break;
		}
		else if (ch == KEY_BACKSPACE || ch == 8 || ch == 9)
		{
			printw("----");
			// Back-space
			/*
			if (strCurrentCmd.length() > 0)
			{
				int y, x;
				// delch();
				strCurrentCmd.erase(strCurrentCmd.end()-1);
			}
			*/

			int y,x;
			getyx(stdscr, y, x);
			move(y,x-1);
			delch();
			move(y,x-2);
			delch();
			move(y,x-3);
			delch();
			refresh();
		}
		else if (ch =='s' || ch =='S')
		{
			int screenY, screenX;
			char szTmp[200];
			getmaxyx(stdscr, screenY, screenX);
			sprintf(szTmp, "ScreenWH=%d,%d", screenY, screenX);
			printw(szTmp);
		}
		else
		{
			// printw("The pressed key is ");
			// attron(A_BOLD);
			// printw("%c", ch);
			// attroff(A_BOLD);
			// Toolkit::destroyWindowMenu(mywin, my_menu);
			// mywin = NULL;
			strCurrentCmd = strCurrentCmd + (char)ch;
			char szTemp[2];
			sprintf(szTemp, "%c", ch);
			printw(szTemp);
		}
	}
	refresh();			/* Print it on to the real screen */

	unpost_menu(my_menu);
	free_menu(my_menu);
	for(i = 0; i < n_choices; ++i) {
		free_item(my_items[i]);
	}
	// getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
	return 0;
}

void CCmdLineUI::Toolkit::print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	wattron(win, color);
	mvwprintw(win, y, x, "%s", string);
	wattroff(win, color);
	refresh();
}

WINDOW* CCmdLineUI::Toolkit::createWindowMenu(int starty, int startx, MENU* my_menu)
{
    WINDOW* my_menu_win = newwin(10, 40, starty, startx); // starty, startx);
    keypad(my_menu_win, TRUE);
    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 10,38,0,0) ); // derwin(my_menu_win, 6, 38, 3, 1));

    // box(my_menu_win, 0, 0);
	//mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
	//mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
	//mvwaddch(my_menu_win, 2, 39, ACS_RTEE);

    post_menu(my_menu);
	wrefresh(my_menu_win);

	return my_menu_win;
}

void CCmdLineUI::Toolkit::destroyWindowMenu(WINDOW* win, MENU* menu)
{
    if (win != NULL)
    {
        unpost_menu(menu);
        wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
        wrefresh(win);
        delwin(win);
    }
}

void CCmdLineUI::Toolkit::destroyWin(WINDOW* win)
{
    if (win != NULL)
    {
        wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');

        wrefresh(win);
        delwin(win);
    }
}

WINDOW* CCmdLineUI::Toolkit::create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters
					 * for the vertical and horizontal
					 * lines			*/
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
}

void CCmdLineUI::Toolkit::destroy_win(WINDOW *local_win)
{
	/* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners
	 * and so an ugly remnant of window.
	 */
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	/* The parameters taken are
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window
	 * 3. rs: character to be used for the right side of the window
	 * 4. ts: character to be used for the top side of the window
	 * 5. bs: character to be used for the bottom side of the window
	 * 6. tl: character to be used for the top left corner of the window
	 * 7. tr: character to be used for the top right corner of the window
	 * 8. bl: character to be used for the bottom left corner of the window
	 * 9. br: character to be used for the bottom right corner of the window
	 */
	wrefresh(local_win);
	delwin(local_win);
}

