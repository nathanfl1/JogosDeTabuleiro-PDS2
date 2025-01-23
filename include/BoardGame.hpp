#ifndef BOARDGAME_H
#define BOARDGAME_H

#include <vector>
#include <algorithm>
#include "Player.hpp"

using namespace std;

class BoardGame {
    private:
        Player *player1;
        Player *player2;
        pair<int, int> size;
        int turnCounter = 0;
    protected:
        char **board = nullptr;
    public:
        BoardGame(int, int);
        virtual void readRound(pair<int, int>, Player *player) = 0;
        virtual bool roundIsValid(pair<int, int>) = 0;
        virtual bool didPlayerWin(Player *player) = 0;
        virtual void startGame(Player *player1, Player *player2) = 0;
        void printBoard();
        void setBoard();
        void setSize(int, int);
        bool isInsideBoard(pair<int, int>);
        pair<int, int> getSize();
        int getX();
        int getY();
        char** getBoard();


        void incrementTurn();
        int getTurn();


        ~BoardGame();
    };


#endif