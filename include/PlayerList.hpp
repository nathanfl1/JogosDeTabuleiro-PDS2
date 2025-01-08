#ifndef PLAYERLIST_H
#define PLAYLERLIST_H

#include "Player.hpp"
#include <iostream>
#include <algorithm>
#include <list>
#include <fstream>


using namespace std;
class PlayerList
{
private:
    int count;
    list<Player*> players;
public:
    static const int SUCCESS = 0;
    static const int ERR_REPEATED_PLAYER = -1;
    static const int ERR_PLAYER_NOT_FOUND = -2;
    static const int ERR_INCORRECT_DATA = -3;
    list<Player*> getPlayers();
    void setPlayers(list<Player*>);
    int getCount();
    void setCount(int);
    int addPlayer(Player*);
    void sortByName();
    void sortByNickname();
    int removePlayer(string);
    void display();
    //int searchPlayer(string);
    Player* searchPlayer(string);
    void saveData();
    void loadData();
    ~PlayerList();
};

#endif