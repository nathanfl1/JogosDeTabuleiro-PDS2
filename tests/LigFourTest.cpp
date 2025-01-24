#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/Checkers.hpp"
#include "../include/Player.hpp"
#include "../include/LigFour.hpp"

TEST_CASE("Verificando uma diagonal")
{
    
    Player* p1 = new Player("player1", "p1");
    Player* p2 = new Player("player2", "p2");
    LigFour l = LigFour(p1, p2);
    l.setBoard();
    l.getBoard()[4][0] = 'X';
    l.getBoard()[4][1] = 'X';
    l.getBoard()[4][2] = 'X';
    //CHECK(l.didPlayerWin(p2, {4, 3}));

    CHECK(l.didPlayerWin(p1, {4, 3}));

    //CHECK_FALSE(l.roundIsValid({-1, -1}));
}
TEST_CASE("Verificando outra diagonal")
{
    
    Player* p1 = new Player("player1", "p1");
    Player* p2 = new Player("player2", "p2");
    LigFour l = LigFour(p1, p2);
    l.setBoard();
    l.getBoard()[4][0] = 'X';
    l.getBoard()[3][1] = 'X';
    l.getBoard()[2][2] = 'X';
    //CHECK(l.didPlayerWin(p2, {4, 3}));
    CHECK(l.didPlayerWin(p1, {1, 3}));

    //CHECK_FALSE(l.roundIsValid({-1, -1}));
}

TEST_CASE("Verificando caso de jogadas inválidas")
{
    
    Player* p1 = new Player("player1", "p1");
    Player* p2 = new Player("player2", "p2");
    LigFour l = LigFour(p1, p2);
    l.setBoard();

    CHECK_FALSE(l.roundIsValid({-1, -1}));
    CHECK_FALSE(l.roundIsValid({9, 9}));
}

TEST_CASE("Verificando caso de jogadas válidas")
{
    Player* p1 = new Player("player1", "p1");
    Player* p2 = new Player("player2", "p2");
    LigFour l = LigFour(p1, p2);
    l.setBoard();

    CHECK_FALSE(l.roundIsValid({0, 0}));
    CHECK_FALSE(l.roundIsValid({1, 1}));
}