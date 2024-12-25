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
        LigFour(Player *, Player *);
        ~LigFour();
        bool didPlayerWin();
        void readRound(pair<int,int>, Player *player) override;
        bool roundIsValid(pair<int,int>) override;
        bool didPlayerWin() override;
};

#endif