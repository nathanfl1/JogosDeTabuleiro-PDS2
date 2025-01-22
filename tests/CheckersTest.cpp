#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/Checkers.hpp"
#include "../include/Player.hpp"

TEST_CASE("Verificando caso de jogadas inválidas")
{
    Checkers c;
    c.setBoard();
    Player p = Player("teste", "teste");

    // fora do tabuleiro
    CHECK_FALSE(c.roundIsValid({-1, -1}, {1, 1}, 1));
    CHECK_FALSE(c.roundIsValid({7, 7}, {8, 8}, 2));

    // tentando pular duas casas
    CHECK_FALSE(c.roundIsValid({0, 5}, {2, 3}, 1));

    // tentando mexer uma peça do outro jogador
    CHECK_FALSE(c.roundIsValid({2, 0}, {3, 1}, 2));

    // tentando mexer uma peça para trás
    c.readRound({2, 0}, {3, 1}, &p);
    CHECK_FALSE(c.roundIsValid({3, 1}, {2, 0}, 1));

    // tentando mexer uma peça para uma casa ocupada
    CHECK_FALSE(c.roundIsValid({7, 7}, {6, 6}, 2));
}

TEST_CASE("Verificando caso de jogadas válidas")
{
    Checkers c;
    c.setBoard();
    Player p = Player("teste", "teste");
    Player p2 = Player("teste2", "teste2");

    // movimento normal
    CHECK(c.roundIsValid({2, 0}, {3, 1}, 1));
    CHECK(c.roundIsValid({5, 1}, {4, 0}, 2));
    c.readRound({2, 0}, {3, 1}, &p);
    c.readRound({5, 1}, {4, 0}, &p2);
    c.readRound({3, 1}, {4, 2}, &p);

    // comendo uma peça
    CHECK(c.roundIsValid({5, 3}, {3, 1}, 2));

    // comendo mais de uma peça
    c.readRound({5, 3}, {3, 1}, &p2);
    c.readRound({1, 1}, {2, 0}, &p);
    c.readRound({6, 0}, {5, 1}, &p2);
    CHECK(c.roundIsValid({2, 0}, {4, 2}, 1));
    c.readRound({2, 0}, {4, 2}, &p);
    CHECK(c.roundIsValid({4, 2}, {6, 0}, 1));
}

TEST_CASE("Damas")
{
    Checkers c;
    c.setBoard();
    Player p = Player("teste", "teste");

    c.getBoard()[0][0] = 'Q';

    // movimento normal

    for (int i = 1; i < 8; i++)
        c.getBoard()[i][i] = ' ';

    // movimento simples
    CHECK(c.roundIsValidQueen({0, 0}, {1, 1}, 2));

    // movimento pulando todas as casas da diagonal
    CHECK(c.roundIsValidQueen({0, 0}, {7, 7}, 2));

    // supondo que tenha uma peça do mesmo time na diagonal, então a dama não pode fazer o movimento
    c.getBoard()[4][4] = 'X';
    
    
    CHECK_FALSE(c.roundIsValidQueen({0, 0}, {7, 7}, 2));

    // se a peça for do outro time, então é possível fazer o movimento
    c.getBoard()[4][4] = 'O';
    CHECK(c.roundIsValidQueen({0, 0}, {7, 7}, 2));

    // com duas peças em sequência, a dama não pode fazer o movimento
    c.getBoard()[5][5] = 'O';
    CHECK_FALSE(c.roundIsValidQueen({0, 0}, {7, 7}, 2));

    // com duas peças do time adversário, com um espaço entre elas, a dama pode fazer o movimento
    c.getBoard()[5][5] = ' ';
    c.getBoard()[6][6] = 'O';

    CHECK(c.roundIsValidQueen({0, 0}, {7, 7}, 2));
}

TEST_CASE("Teste de didPlayerWin")
{
    Checkers c;
    c.setBoard();

    //teste com o tabuleiro no estado inicial
    CHECK_FALSE(c.didPlayerWin(1));
    CHECK_FALSE(c.didPlayerWin(2));

    //esvaziando o tabuleiro.
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            c.getBoard()[i][j] = ' ';

    //adicionando uma peça para o jogador 1
    c.getBoard()[0][0] = 'O';
    CHECK(c.didPlayerWin(1));

    //adicionando uma dama para o jogador 1

    c.getBoard()[0][0] = 'K';
    CHECK(c.didPlayerWin(1));

    //limpando o tabuleiro de novo
    c.getBoard()[0][0] = ' ';


    //adicionando uma peça para o jogador 2
    c.getBoard()[7][7] = 'X';
    CHECK(c.didPlayerWin(2));
    
    //adicionando uma dama para o jogador 2
    c.getBoard()[7][7] = 'Q';
    CHECK(c.didPlayerWin(2));
}