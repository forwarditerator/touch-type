#include <ncurses.h>
#include <chrono>
#include <vector>
#include <numeric>
#include <string>

int main() {
	initscr();
    noecho();
    std::string text = "start typing these words to practice touch type, try not to look to the keyboard, more to come";
    std::vector<unsigned long> time;
    time.reserve(text.size());
    addstr(text.data());
    move(0,0);
    int i = 0;
    while (i < text.size()) {
        auto start = std::chrono::steady_clock::now();
        char c = getch();
        auto end = std::chrono::steady_clock::now();
        if (c == text[i]) {
            attron(A_REVERSE);
            mvaddch(0, i++, c);
            attroff(A_REVERSE);
            refresh();
            time.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count());
        } else {
            beep();
        }
    }
    clear();
    auto avg = std::accumulate(time.begin() + 1, time.end(), 0lu)/(time.size() - 1);
    printw("your average miliseconds per keystroke: %lu\n", avg);
    printw("\npress ~ to quit");
    char c;
    while ((c = getch()) != '~')
        ;
	endwin();
}
