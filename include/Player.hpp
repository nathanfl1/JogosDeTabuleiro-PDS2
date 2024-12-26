#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player{
    private:
        string nickname, name;
        int wins, losses;

    public:
        static bool compararPlayerComPlayer(Player*);
        Player(string nickname, string name);
        void addWin();
        void addLoss();
        int getWins();
        int getLosses();
        string getName();
        string getNickname();
        bool operator==(const Player &a)
        {
            return nickname == a.nickname;
        }
};



#endif
