#include <ncurses.h>
#include <chrono>
#include <vector>

int main() {
	initscr();
    noecho();
    std::vector<int> time;
    for (int i = 0; i < 1000; ++i) {
        auto start = std::chrono::steady_clock::now();
        addch('a');
        refresh();
        auto end = std::chrono::steady_clock::now();
        time.push_back(std::chrono::duration_cast<std::chrono::microseconds>(end-start).count());
    }
    clear();
    for (auto t : time)
        printw("%4d", t);
    getch();
	endwin();
}
