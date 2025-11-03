#include <ncurses.h>
#include <locale.h>
#include <unistd.h>

#define tamanho_vetor 3

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

void ler_vetor(float vetor[], int size) {
    printw("escrever %d valores do vetor separados por espaço): ", size);
    refresh();
    //for (int i = 0; i < size; i++) {
        scanw("%f %f %f", &vetor[0], &vetor[1], &vetor[2]);
    //}
}

float calculo_produto_escalar(float vetor1[], float vetor2[], int size) {
    float produto = 0.0;
    for (int i = 0; i < size; i++) {
        produto += vetor1[i] * vetor2[i];
    }
    return produto;
}

void calculo_produto_vetorial(float vetor1[], float vetor2[], float resultado[]) {
    resultado[0] = vetor1[1] * vetor2[2] - vetor1[2] * vetor2[1];
    resultado[1] = vetor1[2] * vetor2[0] - vetor1[0] * vetor2[2];
    resultado[2] = vetor1[0] * vetor2[1] - vetor1[1] * vetor2[0];
}

// Operações

int at_adicao() {
    echo();
    curs_set(1);

    int times, i;
    double x, y, z; 
    double Xtotal = 0, Ytotal = 0, Ztotal = 0;

    printw("Digite a quantidade de vetores: ");
    refresh();
    scanw("%d", &times);


    for (i = 0; i < times; i++) {
        printw("\n--- Vetor %d ---\n", i + 1);

        printw("Digite o valor X: ");
        refresh();
        scanw("%lf", &x);
        Xtotal += x; 

        printw("Digite o valor Y: ");
        refresh();
        scanw("%lf", &y);
        Ytotal += y; 

        printw("Digite o valor Z: ");
        refresh();
        scanw("%lf", &z);
        Ztotal += z; 
    }

    printw("\nResultante: (%.6f, %.6f, %.6f)\n", Xtotal, Ytotal, Ztotal);
    refresh();

    getch();
    noecho();
    curs_set(0);
}

int at_multiplicacao_escalar() {
    // Configurações dessa tela
    curs_set(1);
    echo();

    // Textos
    attron(A_BOLD);
    mvprintw(0, 0, "Digite o vetor (x y z): ");
    mvprintw(1, 0, "Digite o número (a): ");
    attroff(A_BOLD);
    refresh();

    double x, y, z, a;

    move(0, 24);
    scanw("%lf %lf %lf", &x, &y, &z);
    move(1, 21);
    scanw("%lf", &a);

    curs_set(0);

    mvprintw(3, 0, "a = (x, y, z)");
    refresh();
    usleep(900*1000);

    mvprintw(3, 0, "%.6lf = (%.6lf, %.6lf, %.6lf)", a, x, y, z);
    refresh();
    usleep(900*1000);

    printw(" =");
    mvprintw(4, 0, "%.6lf . %.6lf + %.6lf . %.6lf + %.6lf . %.6lf =", a, x, a, y, a, z);
    refresh();
    usleep(900*1000);

    clrtoeol();
    mvprintw(4, 0, "%.6lf + %.6lf . %.6lf + %.6lf . %.6lf =             ", a*x, a, y, a, z);
    refresh();
    usleep(500*1000);
    //
    clrtoeol();
    mvprintw(4, 0, "%.6lf + %.6lf + %.6lf . %.6lf =           ", a*x, a*y, a, z);
    refresh();
    usleep(500*1000);
    //
    clrtoeol();
    mvprintw(4, 0, "%.6lf + %.6lf + %.6lf =             ", a*x, a*y, a*z);
    refresh();
    usleep(900*1000);

    clrtoeol();
    mvprintw(4, 0, "%.6lf + %.6lf + %.6lf = %.6lf              ", a*x, a*y, a*z, (a*x + a*y + a*z));
    refresh();
    usleep(900*1000);

    mvprintw(6, 0, "O resultado deu %.6lf", (a*x + a*y + a*z));
    mvprintw(8, 0, "Qualquer tecla para finalizar...");
    refresh();
    getch();
    
    // Voltando a configuração padrão
    noecho();
}

int at_prod_esc() {
    curs_set(1);
    echo();
    float vetor1[tamanho_vetor];
    float vetor2[tamanho_vetor];

    printw("Vetor 1:\n");
    refresh();
    ler_vetor(vetor1, tamanho_vetor);

    printw("Vetor 2:\n");
    refresh();
    ler_vetor(vetor2, tamanho_vetor);
    //produto escalar
    float produto = calculo_produto_escalar(vetor1, vetor2, tamanho_vetor);
    printw("produto escalar: %.6f\n", produto);
    refresh();

    getch();
    curs_set(0);
    noecho();
}

int at_prod_vet() {
    curs_set(1);
    echo();

    float vetor1[tamanho_vetor];
    float vetor2[tamanho_vetor];
    float resultadoprodutovetorial[tamanho_vetor];

    printw("Vetor 1:\n");
    refresh();
    ler_vetor(vetor1, tamanho_vetor);

    printw("Vetor 2:\n");
    refresh();
    ler_vetor(vetor2, tamanho_vetor);
    //produto vetorial
    calculo_produto_vetorial(vetor1, vetor2, resultadoprodutovetorial);
    printw("produto vetorial:\n [%.6f\n, %.6f\n, %.6f]\n", resultadoprodutovetorial[0], resultadoprodutovetorial[1], resultadoprodutovetorial[2]);
    refresh();

    curs_set(0);
    noecho();

    getch();
}

int at_prod_misto() {
    curs_set(1);
    echo();
    //Vetor A
    double ax, ay, az;

    //Vetor B
    double bx, by, bz;

    //Vetor C
    double cx, cy, cz;

    double produtoMisto;

    //Leitura do Vetor A
    printw("--- Vetor A ---\n");
    printw("Digite o valor X de A: ");
    refresh();
    scanw("%lf", &ax);
    printw("Digite o valor Y de A: ");
    refresh();
    scanw("%lf", &ay);
    printw("Digite o valor Z de A: ");
    refresh();
    scanw("%lf", &az);

    //Leitura do Vetor B 
    printw("\n--- Vetor B ---\n");
    printw("Digite o valor X de B: ");
    refresh();
    scanw("%lf", &bx);
    printw("Digite o valor Y de B: ");
    refresh();
    scanw("%lf", &by);
    printw("Digite o valor Z de B: ");
    refresh();
    scanw("%lf", &bz);

    //Leitura do Vetor C
    printw("\n--- Vetor C ---\n");
    printw("Digite o valor X de C: ");
    refresh();
    scanw("%lf", &cx);
    printw("Digite o valor Y de C: ");
    refresh();
    scanw("%lf", &cy);
    printw("Digite o valor Z de C: ");
    refresh();
    scanw("%lf", &cz);

    // Formula: ax(bycz - bzcy) - ay(bxcz - bzcx) + az(bxcy - bycx)

    produtoMisto = ax * (by * cz - bz * cy) - ay * (bx * cz - bz * cx) + az * (bx * cy - by * cx);
  if(produtoMisto =! 0) {
      printw("O produto misto [A, B, C] e: %.6f\n", produtoMisto);}else {
      printw("O produto misto [A, B, C] e: %.6f (são coplanares)\n", produtoMisto);}
      refresh();

    

    curs_set(0);
    noecho();
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
                            at_multiplicacao_escalar();
                            break;
                        case 2:
                            at_prod_esc();
                            break;
                        case 3:
                            at_prod_vet();
                            break;
                        case 4:
                            at_prod_misto();
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