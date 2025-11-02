#include <ncurses.h>
#include <locale.h>

// Váriaveis globais

char ops[5][100] = {
    "ADIÇÃO",
    "MULTIPLICAÇÃO POR ESCALAR",
    "PRODUTO ESCALAR",
    "PRODUTO VETORIAL",
    "PRODUTO MISTO"
};

// Funções

int printops(int op, int ve, int ho) {
    mvprintw(ve/2-3, ho/2-21, "========== CALCULADORA VETORIAL ==========");
    for (int i = 0; i < 5; i++) {
        if(i == op) {
            mvprintw(ve/2-2+i, ho/2-21, "> %s", ops[i]);
        } else {
            mvprintw(ve/2-2+i, ho/2-21, "%s", ops[i]);
        }
    }
}

// Operações

int at_adicao() {
    printw("TESTE");
    refresh();
    getch();
}

// Principal

int main() {
    // Fazer o ncurses mostrar acentos
    setlocale (LC_ALL, "");

    // Inicializar janela
    initscr();
    keypad(stdscr, true);
    noecho();
    curs_set(0);

    // Váriaveis
    int ho, ve, op=0, tecla;

    // Obtendo o tamanho da tela
    getmaxyx(stdscr, ve, ho);

    // Apresentação e opções
    printops(op, ve, ho);
    
    // Escolhendo opção
    while(1) {
        tecla = getch();

        if(tecla == KEY_DOWN) {
            mvaddch(ve/2-2+op, 0, ' ');
            clrtoeol();
            mvprintw(ve/2-2+op, ho/2-21, "%s", ops[op]);
            if(op == 4) {
                op = 0;
                mvprintw(ve/2-2+op, ho/2-21, "> %s", ops[op]);
            } else {
                op = op + 1;
                mvprintw(ve/2-2+op, ho/2-21, "> %s", ops[op]);
            }
        } else {
            if(tecla == KEY_UP) {
                mvaddch(ve/2-2+op, 0, ' ');
                clrtoeol();
                mvprintw(ve/2-2+op, ho/2-21, "%s", ops[op]);
                if(op == 0) {
                    op = 4;
                    mvprintw(ve/2-2+op, ho/2-21, "> %s", ops[op]);
                } else {
                    op = op - 1;
                    mvprintw(ve/2-2+op, ho/2-21, "> %s", ops[op]);
                }
            } else {
                if(tecla == (int)'\n') {
                    // Limpando janela
                    erase();

                    // Tela de acordo com a opção escolhida
                    switch (op)
                    {
                        case 0:
                            at_adicao();
                            break;
                        case 1:
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            break; 
                        default:
                            break;
                    }

                    // Limpando a janela e voltando as opções
                    erase();
                    printops(op, ve, ho);
                }
            }
        }

        refresh();
    }
    
    // Finalizar janela
    endwin();
}