#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "../include/Reversi.hpp"


TEST_CASE("Setando tabuleiro") {
    Reversi reversi;

    reversi.setBoard();

    CHECK(reversi.getBoard()[3][3] == 'X');

}

TEST_CASE("Verificando se round é válido") {
    Reversi reversi;

    reversi.setBoard();

    for(int i = -10; i < 0; i++)
        for(int j = -10; j < 0; j++)
            CHECK(reversi.roundIsValid({i, j}, 1) == false);
    
}

TEST_CASE("Teste do DidPlayerWin") {
    Reversi reversi;

    reversi.setBoard();

    reversi.getBoard()[3][3] = ' ';
    reversi.getBoard()[4][4] = ' ';
    reversi.getBoard()[3][4] = ' ';
    reversi.getBoard()[4][3] = ' ';

    CHECK_FALSE(reversi.didPlayerWin(1));
    CHECK_FALSE(reversi.didPlayerWin(2));

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            reversi.getBoard()[i][j] = 'X';

    CHECK(reversi.didPlayerWin(2));
    CHECK_FALSE(reversi.didPlayerWin(1));


    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 4; j++)
            reversi.getBoard()[i][j] = 'X';
    
    for (int i = 0; i < 8; i++)
        for (int j = 4; j < 8; j++)
            reversi.getBoard()[i][j] = 'O';

    CHECK_FALSE(reversi.didPlayerWin(1));
    CHECK_FALSE(reversi.didPlayerWin(2));

}
