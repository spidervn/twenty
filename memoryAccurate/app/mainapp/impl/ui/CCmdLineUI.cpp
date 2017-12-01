/*
 * CCmdLineUI.cpp
 *
 *  Created on: Dec 1, 2017
 *      Author: ducvd
 */

#include <mainapp/impl/ui/CCmdLineUI.h>
#include <string>
#include <stdlib.h>
#include <ncurses.h>			/* ncurses.h includes stdio.h */
#include <curses.h>
#include <string.h>
#include <menu.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

class CCmdLineUI::Toolkit
{
public:
	static void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);
	static WINDOW* createWindowMenu(int starty, int startx, MENU* my_menu);
	static void destroyWindowMenu(WINDOW*, MENU*);
	static void destroyWin(WINDOW* win);
	static WINDOW *create_newwin(int height, int width, int starty, int startx);
	static void destroy_win(WINDOW *local_win);
};

CCmdLineUI::CCmdLineUI() {
	pEvent = new EventHandler();
	pGrammar = new GrammarWork();
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
		WINDOW *my_menu_win;
		WINDOW* mywin = NULL;
		int n_choices, i;

		initscr();			/* Start curses mode 		*/
		raw();				/* Line buffering disabled	*/
		start_color();
		keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
		// noecho();			/* Don't echo() while we do getch */
	    // halfdelay(10);

	    init_pair(1, COLOR_RED, COLOR_BLACK);
		init_pair(2, COLOR_CYAN, COLOR_BLACK);

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
	    }

		my_items[n_choices] = (ITEM *)NULL;
		my_menu = new_menu((ITEM **)my_items);
		set_menu_format(my_menu, 5, 1);
	    set_menu_mark(my_menu, " * "); /* Set menu mark to the string " * " */

	    printw("Type any character to see it in bold\n");
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
	        else if (ch == KEY_ENTER)
	        {
	            int y, x;
	            //printw("\r\n");
	            char szTemp[200];

	            getyx(stdscr, y, x);
	            sprintf(szTemp, "%d-%d", y, x);
	            printw(szTemp);

	            mvwprintw(stdscr, y+1, x, "#");
	        }
	        else if (ch == 'a' or ch == 'A')
	        {
	            // post_menu(my_menu);
	            // refresh();
	            int y, x;
	            getyx(stdscr, y, x);

	            //destroy_win(mywin);
	            //mywin = create_newwin(10,10,y,x+1);
	            Toolkit::destroyWindowMenu(mywin, my_menu);
	            mywin = Toolkit::createWindowMenu(y,x+1,my_menu);
	        }
	        else if (ch == 'q' or ch =='Q')
	        {
	        	break;
	        }
	        else
	        {	// printw("The pressed key is ");
	            // attron(A_BOLD);
	            // printw("%c", ch);
	            // attroff(A_BOLD);
	            Toolkit::destroyWindowMenu(mywin, my_menu);
	            mywin = NULL;
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
    WINDOW* my_menu_win = newwin(10, 40, starty, startx);
    keypad(my_menu_win, TRUE);
    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));

    box(my_menu_win, 0, 0);
	mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
	mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
	mvwaddch(my_menu_win, 2, 39, ACS_RTEE);

    post_menu(my_menu);
	wrefresh(my_menu_win);

	return my_menu_win;
}

void CCmdLineUI::Toolkit::destroyWindowMenu(WINDOW* win, MENU* menu)
{
    if (win != NULL)
    {
        unpost_menu(menu);
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

