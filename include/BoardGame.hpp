#ifndef BOARDGAME_H
#define BOARDGAME_H

// #include <iostream>
#include <vector>

using namespace std;

class BoardGame {
    private:
        pair<int, int> size;
    protected:
        char **board = nullptr;
    public:
        BoardGame(int, int);
        virtual void readRound(pair<int, int>, Player *player) = 0;
        virtual bool roundIsValid(pair<int, int>) = 0;
        virtual bool didPlayerWin() = 0;
        void printBoard();
        void setBoard();
        void setSize(int, int);
        pair<int, int> getSize();
        int getX();
        int getY();
        ~BoardGame();
    };


#endif