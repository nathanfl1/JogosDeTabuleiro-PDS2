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
    const static int SUCCESS = 1;
    const static int NOT_SUCCESS = 0;
    const static int CAPTURE_AGAIN = 2;

    bool didPlayerWin(Player*);
    Checkers(/* args */);
    void readRound(pair<int, int>, Player *);
    void readRound(pair<int, int>, pair<int, int>, Player *);
    int roundIsValid(pair<int, int>, pair<int, int>, int);
    int roundIsValidQueen(pair<int, int>, pair<int, int>, int);
    bool didPlayerWin(int player);
    bool canCaptureQueen(pair<int, int>, pair<int, int>, int);
    bool roundIsValid(pair<int, int>);
    bool canCapture(pair<int, int>, pair<int, int>, int);
    void setBoard();
    void startGame(Player *, Player *);
    ~Checkers();
};

#endif