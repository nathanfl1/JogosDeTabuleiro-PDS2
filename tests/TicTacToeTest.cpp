#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/TicTacToe.hpp"


TEST_CASE("Verificando casos fora do tabuleiro") {
    TicTacToe t;

    t.setBoard();
    
    CHECK_FALSE(t.roundIsValid({-1, -1}));
    CHECK_FALSE(t.roundIsValid({9, 9}));

}

TEST_CASE("Verificando se round é válido") {
    TicTacToe t;

    t.setBoard();
    
    CHECK(t.roundIsValid({0, 0}));
    CHECK(t.roundIsValid({1, 1}));
    
}

TEST_CASE("Teste do DidPlayerWin") {
    TicTacToe t;
    Player* p1 = new Player("player1", "P1");

    t.setBoard();
    t.readRound({0, 0}, p1);
    t.readRound({1, 1}, p1);
    t.readRound({2, 2}, p1);
    CHECK(t.didPlayerWin(p1));

}
