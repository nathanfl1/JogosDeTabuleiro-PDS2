#ifndef CHECKERS_H
#define CHECKERS_H

#include "BoardGame.hpp"
#include <iostream>
using namespace std;
class Checkers : public BoardGame
{
private:
    /* data */
public:
    bool didPlayerWin(Player*);
    Checkers(/* args */);
    void readRound(pair<int, int>, Player *);
    void readRound(pair<int, int>, pair<int, int>, Player *);
    bool roundIsValid(pair<int, int>, pair<int, int>, int);
    bool didPlayerWin(int player);
    bool roundIsValid(pair<int, int>);
    //bool hasAdjacentOpponentPieces(pair<int, int>);
    void setBoard();
    void startGame(Player *, Player *);
    ~Checkers();
};

#endif