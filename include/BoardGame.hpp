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
        void printBoard();
        virtual void readRound() = 0;
        virtual bool roundIsValid() = 0;
        virtual bool didPlayerWin() = 0;
        void setBoard();
        pair<int, int> getSize();
        void setSize(int, int);
        int getX();
        int getY();
        ~BoardGame();
    };


#endif