#ifndef LIGFOUR_H
#define LIGFOUR_H

#include "BoardGame.hpp"
#include "Player.hpp"
#include <map>

using namespace std;
class LigFour : public BoardGame
{
    private:
        Player *player1;
        Player *player2;
        map<string, char> playerSymbols;

    public:
        LigFour(Player*, Player*);
        LigFour();
        ~LigFour();
        void startGame(Player *player1, Player *player2) override;
        void readRound(pair<int,int>, Player *player) override;
        void readRound(pair<int, int>, pair<int,int>, Player*);
        bool didPlayerWin();
        bool roundIsValid(pair<int,int>) override;
        
        bool didPlayerWin(Player *player) override;
        bool isBoardFull();
        bool isBoardEmpty();
};

#endif