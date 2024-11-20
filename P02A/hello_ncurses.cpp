#include <ncurses.h>

int main() {
    initscr();            // Start ncurses mode
    box(stdscr, 0, 0);
    printw("Hello, World!"); // Print message on the screen
    refresh();            // Refresh to show the message
    getch();              // Wait for user input
    endwin();             // End ncurses mode
    return 0;
}
