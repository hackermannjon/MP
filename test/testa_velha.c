#include <stdio.h>
#include "velha.h"
#include "gtest/gtest.h"

// Teste para verificar se o jogo está empatado
TEST(VelhaTest, Empate) {
    int tabuleiro[3][3] = {{1, 2, 1},
                           {1, 2, 2},
                           {2, 1, 1}};
    EXPECT_EQ(0, verificarVencedor(tabuleiro));
}

// Teste para verificar se o X venceu
TEST(VelhaTest, VitoriaX) {
    int tabuleiro[3][3] = {{1, 2, 0},
                           {2, 1, 0},
                           {1, 0, 0}};
    EXPECT_EQ(1, verificarVencedor(tabuleiro));
}

// Teste para verificar se o O venceu
TEST(VelhaTest, VitoriaO) {
    int tabuleiro[3][3] = {{2, 1, 0},
                           {1, 2, 0},
                           {2, 0, 0}};
    EXPECT_EQ(2, verificarVencedor(tabuleiro));
}

// Teste para verificar jogo indefinido
TEST(VelhaTest, Indefinido) {
    int tabuleiro[3][3] = {{0, 1, 0},
                           {0, 0, 0},
                           {0, 0, 0}};
    EXPECT_EQ(-1, verificarVencedor(tabuleiro));
}

// Teste para verificar jogo impossível
TEST(VelhaTest, Impossivel) {
    int tabuleiro[3][3] = {{1, 1, 1},
                           {2, 2, 2},
                           {0, 0, 0}};
    EXPECT_EQ(-2, verificarVencedor(tabuleiro));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
