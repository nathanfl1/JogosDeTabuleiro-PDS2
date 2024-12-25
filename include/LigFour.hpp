#ifndef LIGFOUR_H
#define LIGFOUR_H

#include "BoardGame.hpp"

using namespace std;
class LigFour : public BoardGame
{
    private:
        /* data */
    public:
        LigFour();
        ~LigFour();
        bool didPlayerWin();
        void readRound(pair<int,int>) override;
        bool roundIsValid(pair<int,int>) override;
        bool didPlayerWin() override;
};

#endif