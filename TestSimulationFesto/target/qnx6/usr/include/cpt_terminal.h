#ifndef cpt_terminal_h
#define cpt_terminal_h

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------+
 | CONSTANTS                                                            |
 +----------------------------------------------------------------------*/
/* dimension-constants */    
#define TERMINAL_X_HOME 1
#define TERMINAL_Y_HOME 1
#define TERMINAL_X_MAX  80
#define TERMINAL_Y_MAX  24

/* flags for ANSI-terminal attributes.
 * These do work in any reasonable combination
 * (do not combine BRIGHT and DIM etc.) */
#define TERMINAL_ATTR_RESET      0x001 
#define TERMINAL_ATTR_BRIGHT     0x002 
#define TERMINAL_ATTR_DIM        0x004 
#define TERMINAL_ATTR_UNDERSCORE 0x008 
#define TERMINAL_ATTR_BLINK      0x010 
#define TERMINAL_ATTR_REVERSE    0x020 
#define TERMINAL_ATTR_HIDDEN     0x040 
#define TERMINAL_NOATTR          0x080

/* ANSI-terminal colors. */
#define TERMINAL_COLOR_BLACK     0x00
#define TERMINAL_COLOR_RED       0x01
#define TERMINAL_COLOR_GREEN     0x02
#define TERMINAL_COLOR_YELLOW    0x03
#define TERMINAL_COLOR_BLUE      0x04
#define TERMINAL_COLOR_MAGENTA   0x05
#define TERMINAL_COLOR_CYAN      0x06
#define TERMINAL_COLOR_WHITE     0x07
#define TERMINAL_NOCOLOR         0x08


/*----------------------------------------------------------------------+
 | INTERNAL ATTRIBUTE- AND COLOR-MACROS                                 |
 +----------------------------------------------------------------------*/
/* encoders for internal attribute format. You're pretty much weird if
 * you really want to use them. */
#define TERMINAL_FG_COLOR_ENC(col) (col<<8)
#define TERMINAL_BG_COLOR_ENC(col) (col<<12)

/* setup attribtutes and fg/bg-color */
#define TERMINAL_ATTR_COLOR(attr,fg,bg) \
	( TERMINAL_FG_COLOR_ENC(fg) \
	| TERMINAL_BG_COLOR_ENC(bg) \
	| attr )

/* setup only attributes */
#define TERMINAL_ATTR(attr) \
	( TERMINAL_ATTR_COLOR( attr, TERMINAL_NOCOLOR, TERMINAL_NOCOLOR ) )

/* setup foreground color attr */
#define TERMINAL_FGCOLOR(fg) \
	( TERMINAL_ATTR_COLOR( TERMINAL_NOATTR, fg, TERMINAL_NOCOLOR ) )

/* setup background color attr */
#define TERMINAL_BGCOLOR(bg) \
	( TERMINAL_ATTR_COLOR( TERMINAL_NOATTR, TERMINAL_NOCOLOR, bg ) )

/* setup fore-/background-color attr */
#define TERMINAL_COLOR(fg,bg) \
	( TERMINAL_ATTR_COLOR( TERMINAL_NOATTR, fg, bg ) )


/*----------------------------------------------------------------------+
 | ATTRIBUTE- AND COLOR-MACROS                                          |
 +----------------------------------------------------------------------*/
/* 
 * most likely this is the set of macros you'll really need. 8)
 */
#define TERMINAL_SETATTR(attr) \
	terminal_setattr(TERMINAL_ATTR(attr))
#define TERMINAL_RESET_ATTR() \
	terminal_setattr(TERMINAL_ATTR(TERMINAL_ATTR_RESET))
#define TERMINAL_SETFGCOLOR(fg) \
	terminal_setattr(TERMINAL_FGCOLOR(fg))
#define TERMINAL_SETBGCOLOR(bg) \
	terminal_setattr(TERMINAL_BGCOLOR(bg))
#define TERMINAL_SETCOLOR(fg,bg) \
	terminal_setattr(TERMINAL_COLOR(fg,bg))
#define TERMINAL_SET_ATTR_COLOR(attr,fg,bg) \
	terminal_setattr(TERMINAL_ATTR_COLOR(attr,fg,bg))

/*----------------------------------------------------------------------+
 | DATATYPES                                                            |
 +----------------------------------------------------------------------*/
/**
 * used to specify coordinates as argument.
 */
typedef struct point {
	int x;
	int y;
} point_t;

typedef struct character {
	int x;
	int y;
	char c;
	int attr;
} char_t;
/*----------------------------------------------------------------------+
 | TERMINAL-CONTROL FUNCTIONS                                           |
 +----------------------------------------------------------------------*/
/**
 * opens a VT100 compatible terminal in current photon-environment and starts
 * a terminal-thread for it.
 * stdin, stdout and stderr are attached to the terminal.
 * The specified priority is the scheduler-priority of the terminal-thread.
 * 
 * @param int prio
 *   the priority of the terminal-thread. If less or equal 0 the default
 *   priority (11) will be taken, if larger than 60 the priority is set to 60.
 */
int terminal_open(int prio);

/**
 * closes the terminal and terminates the terminal-thread.
 * 
 * @return in this implementation always 0
 */
int  terminal_close(void);

/*----------------------------------------------------------------------+
 | ERASING TEXT                                                         |
 +----------------------------------------------------------------------*/
/**
 * erases the screen with the background colour and moves the cursor to home.
 */
void terminal_clrscr(void);

/**
 * erases the entire current line.
 */
void terminal_clrln(void);

/**
 * erases from the current cursor position to the start of the current line.
 */
void terminal_clrsol(void);

/**
 * erases from the current cursor position to the end of the current line.
 */
void terminal_clreol(void);

/**
 * erases the screen from the current line up to the top of the screen.
 */
void terminal_clrsos(void);

/**
 * erases the screen from the current line down to the bottom of the screen.
 */
void terminal_clreos(void);

/*----------------------------------------------------------------------+
 | SET DISPLAY-ATTRIBUTES                                               |
 +----------------------------------------------------------------------*/
/** 
 * Sets terminal-attributes.
 * 
 * !! In order to avoid serious brain damage you should NOT use this 
 * !! function directly.
 * There is a set of macros (TERMINAL_RESET, TERMINAL_SETATTR, 
 * TERMINAL_SETCOLOR, etc.) that will do this for you.
 * 
 * The Attributes are constructed using the TERMINAL_ATTR_COLOR,
 * TERMINAL_ATTR, TERMINAL_FGCOLOR, TERMINAL_BGCOLOR and TERMINAL_COLOR
 * macros and the TERMINAL_COLOR_* and TERMINAL_ATTR_* constants.
 * The internal integer format for the attr-parameter is as follows:
 * 
 *   31   15   11    7        0
 *    +-//-+----+----+--------+ 
 *    | XX | BG | FG |  ATTR  |
 *    +-//-+----+----+--------+
 * 
 * @param int attr the attributes and colors to set
 */
void terminal_setattr(int attr);


/*----------------------------------------------------------------------+
 | TEXT-I/O FUNCTIONS                                                   |
 +----------------------------------------------------------------------*/
/**
 * reads a char from the input device of the terminal.
 * 
 * @return int the character read from the terminal or -1 on error.
 */
int terminal_getchar();

/**
 * writes the specified character and leaves the cursor at its current 
 * position.
 */
void terminal_putchar(char c);

/**
 * same as terminal_putchar but with xy-position.
 * The cursor position is not modified.
 */
void terminal_putcharxy(char c, int x, int y);
void terminal_putcharc(char_t c);
void terminal_printxy(char *c, int x, int y);
void terminal_printc(char_t *c);
/*----------------------------------------------------------------------+
 | CURSOR-CONTROL FUNCTIONS                                             |
 +----------------------------------------------------------------------*/
/**
 * move the cursor to the specified position.
 * 
 * @param int x the column to move to
 * @param int y the row to move to
 */
void terminal_gotoxy(int x, int y);

/**
 * retrieve the current cursor-position from the terminal.
 * 
 * @param int* x pointer to the integer to store the row-number
 * @param int* y pointer ti the integer to store the column-number
 * 
 * @return int '0' on success, '-1' on error
 */
int terminal_getxy(int *x, int *y);

/**
 * move the cursor forward.
 * 
 * @param int count the number of columns to move
 */
void terminal_cursor_fwd(int count);

/**
 * move the cursor backward.
 * 
 * @param int count the number of columns to move
 */
void terminal_cursor_back(int count);

/**
 * move the cursor up.
 * 
 * @param int count the number of rows to move
 */
void terminal_cursor_up(int count);

/**
 * move the cursor down.
 * 
 * @param int count the number of rows to move
 */
void terminal_cursor_down(int count);

/**
 * save the current cursor-position.
 */
void terminal_save_cursor();

/**
 * restore the last-saved cursor-position.
 */
void terminal_restore_cursor();

/**
 * save the current cursor-position and display attributes..
 */
void terminal_save_cursor_attrs();

/**
 * restore the last-saved cursor-position and display attributes.
 */
void terminal_restore_cursor_attrs();

#ifdef __cplusplus
}
#endif

#endif
