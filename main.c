#include <ncurses.h>

int contar(char str[100]) {
    int i;
    for(i = 0; str[i] != '\0'; i++);

    return i;
}

void printc(int y, int xmax, char str[100]) {
    if(y != -1) {
        mvprintw(y, xmax/2-(contar(str)/2), str);
    } else {
        mvprintw(getcury(stdscr), xmax/2-(contar(str)/2), str);
    }
}

int main() {
    // Inicializar janela
    initscr();

    int ho, ve, op;
    getmaxyx(stdscr, ve, ho);

    printc(ve/2-3, ho, "Olá mundo\n");
    printc(-1, ho, "Olá mundo2\n");
    printc(-1, ho, "Olá mun878979do2\n");
    printc(-1, ho, "Olá mundo2\n");
    printc(-1, ho, "Olá mundo2\n");
    printc(-1, ho, "Olá mundo2\n");
    //mvprintw(ve/2, ho/2, "CALCULADORA VETORIAL\n1: ADIÇÃO\n2: MULTIPLICAÇÃO POR ESCALAR\n3: PRODUTO ESCALAR\n4: PRODUTO VETORIAL\n5: PRODUTO MISTO\n");
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