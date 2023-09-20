#ifndef VELHA_H
#define VELHA_H
#include <stdio.h> // Inclua a biblioteca stdio.h para funções de entrada e saída padrão


// Declaração da função para verificar o vencedor do jogo da velha
int verificarVencedor(int tabuleiro[3][3]);

// Declaração da função para verificar se o jogo é impossível pelas regras
int verificarImpossibilidade(int tabuleiro[3][3]);

// Declaração da função para verificar se o jogo terminou em empate
static int verificarEmpate(int tabuleiro[3][3]);

#endif  // VELHA_H
