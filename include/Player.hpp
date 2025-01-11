#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player{

    private:
        
        
        string nickname, name;
        int wins[4], losses[4];

    public:
        static const int CHECKERS = 0;
        static const int TIKTAKTOE = 1;
        static const int LIGFOUR = 2;
        static const int REVERSI = 3;
        static bool compararPlayerComPlayer(Player*);
        
        Player(string nickname, string name);
        Player(string, string, int[], int[]);
        void addWin(int game);
        void addLoss(int game);
        int* getWins();
        int* getLosses();
        void setWins(int *);
        void setLosses(int *);
        string getName();
        string getNickname();
};



#endif
