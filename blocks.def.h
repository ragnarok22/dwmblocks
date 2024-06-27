#include <stdio.h>
#include <unistd.h>

static int *hasBattery(void) {
  return access("/sys/class/power_supply/BAT0", F_OK) == 0;
}

//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		                                                    /*Update Interval*/	/*Update Signal*/
  {" ",  "date '+%b %d (%a) %I:%M%p'",					                              5,		              0},
	{"󰍛 ",  "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	        30,		              0},
  {" ",  "df -h | awk '$NF==\"/home/Data\"{printf \"%s/%s\", $4, $2}'",      60,                 0},
  {" ",  "amixer get Master | grep -oE '[0-9]+%'",                           5,                  0},
  {" ",  "nmcli -t -f active,ssid dev wifi | grep -E '^yes' | cut -d: -f2",  5,                  0},
  {" ",  "upower -i /org/freedesktop/UPower/devices/battery_BAT0 | grep percentage | awk '{print $2}'",5,    0},
};

// check if it has battery and add info to blocks
static const Block blocksBattery[] = {
  {" ",  "upower -i /org/freedesktop/UPower/devices/battery_BAT0 | grep percentage | awk '{print $2}'",5,    0},
};
if (*hasBattery()) {
  for (unsigned int i = 0; i < sizeof(blocksBattery) / sizeof(Block); i++) {
    blocks[i] = blocksBattery[i];
  }
}

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
