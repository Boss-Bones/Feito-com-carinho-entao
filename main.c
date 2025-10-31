#include <ncurses.h>

int main() {
    // Inicializar janela
    initscr();

    int ho, ve, op;
    getmaxyx(stdscr, ve, ho);

    mvprintw(ve/2, ho/2, "CALCULADORA VETORIAL\n
        1: ADIÇÃO\n
        2: MULTIPLICAÇÃO POR ESCALAR\n
        3: PRODUTO ESCALAR\n
        4: PRODUTO VETORIAL\n
        5: PRODUTO MISTO");
    scanw("%d", &op);

    switch (op)
    {
    case 1:
        /* ADIÇÃO */
        break;
    
    case 2:
        /* MULTIPLICAÇÃO POR ESCALAR */
        break;

    case 3:
        /* PRODUTO ESCALAR */
        break;
    
    case 4:
        /* PRODUTO VETORIAL */
        break;
    
    case 5:
        /* PRODUTO MISTO */
        break;
    
    default:
        break;
    }


    refresh();
    getchar();
    
    //finalizar
    endwin();
}