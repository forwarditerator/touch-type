#include <ncurses.h>
int main() {
	initscr();
	refresh();
	getch();
	endwin();
}
