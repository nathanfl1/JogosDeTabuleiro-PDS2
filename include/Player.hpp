#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player{
    private:
        string name, nickname;
        int wins, losses;

    public:
        Player(string name, string nickname);
        void addWin(){};
        void addLoss(){};
        int getWins(){};
        int getLosses(){};
        string getName(){};
        string getNickname(){};
};



#endif
