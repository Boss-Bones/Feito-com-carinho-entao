#include <ncurses.h>

int main() {
    // Inicializar janela
    initscr();

    int ho, ve;
    getmaxyx(stdscr, ve, ho);

    mvprintw(ve/2, ho/2, "X");
    refresh();
    getchar();

    //
    endwin();
}