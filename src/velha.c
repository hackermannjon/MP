#include <stdio.h> // Inclua a biblioteca stdio.h para funções de entrada e saída padrão


// Função para verificar se o jogo terminou em empate

static int verificarEmpate(int tabuleiro[3][3]) {
    // O jogo termina em empate se todas as posições estiverem preenchidas
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == 0) {
                return 0; // Ainda há posições vazias, não é empate
            }
        }
    }
    return 1; // Todas as posições estão preenchidas, é um empate
}

// Função para verificar o vencedor do jogo da velha
int verificarVencedor(int tabuleiro[3][3]) {
    if (verificarImpossibilidade(tabuleiro)) {
        return -2;
    }
    int contagemX = 0;
    int contagemO = 0;

    // Verificar linhas e colunas
    for (int i = 0; i < 3; i++) {
        contagemX = 0;
        contagemO = 0;
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == 1) {
                contagemX++;
            } else if (tabuleiro[i][j] == 2) {
                contagemO++;
            }
        }
        if (contagemX == 3) {
            return 1; // O vencedor é X
        } else if (contagemO == 3) {
            return 2; // O vencedor é O
        }

        contagemX = 0;
        contagemO = 0;
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[j][i] == 1) {
                contagemX++;
            } else if (tabuleiro[j][i] == 2) {
                contagemO++;
            }
        }
        if (contagemX == 3) {
            return 1; // O vencedor é X
        } else if (contagemO == 3) {
            return 2; // O vencedor é O
        }
    }

    // Verificar diagonais
    contagemX = 0;
    contagemO = 0;
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][i] == 1) {
            contagemX++;
        } else if (tabuleiro[i][i] == 2) {
            contagemO++;
        }
    }
    if (contagemX == 3) {
        return 1; // O vencedor é X
    } else if (contagemO == 3) {
        return 2; // O vencedor é O
    }

    contagemX = 0;
    contagemO = 0;
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][2 - i] == 1) {
            contagemX++;
        } else if (tabuleiro[i][2 - i] == 2) {
            contagemO++;
        }
    }
    if (contagemX == 3) {
        return 1; // O vencedor é X
    } else if (contagemO == 3) {
        return 2; // O vencedor é O
    }

    // Verificar empate
    if (verificarEmpate(tabuleiro)) {
        return 0; // O jogo terminou em empate
    }

    return -1; // O jogo está indefinido
}



int verificarImpossibilidade(int tabuleiro[3][3]) {
    int contagemX = 0;
    int contagemO = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == 1) {
                contagemX++;
            } else if (tabuleiro[i][j] == 2) {
                contagemO++;
            }
        }
    }

    if (contagemX > contagemO + 1 || contagemO > contagemX + 1) {
        return 1; // O jogo é impossível pelas regras
    }

    return 0; // O jogo não é impossível
}
