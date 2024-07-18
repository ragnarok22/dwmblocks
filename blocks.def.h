#include <stdio.h>
#include <unistd.h>

//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		    /*Update Interval*/	/*Update Signal*/
  {"",    "dwmdate",        5,		              0},
  {"",    "echo ';'",       0,                  0},
  {"",    "dwmupdates",		  5,		              0},
	{"",    "dwmmemory",	    30,		              0},
  {"",    "dwmdisk",        60,                 0},
  {"",    "dwmalsa",        5,                  0},
  {"",    "dwmwifi",        5,                  0},
  {"",    "dwmbattery",     5,                  0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
