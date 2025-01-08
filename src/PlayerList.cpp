#include "../include/PlayerList.hpp"

int PlayerList::getCount()
{
    return count;
}
void PlayerList::setCount(int c)
{
    count = c;
}

int PlayerList::addPlayer(Player *p)
{
    for(auto player : players)
    {
        if(player->getNickname() == p->getNickname())
            return ERR_REPEATED_PLAYER;
    }
    players.push_back(p);
    count++;
    saveData();
    return SUCCESS;
}

int compareName(Player *a, Player *b)
{
    return a->getName() < b->getName();
}
int compareNickname(Player*a, Player *b)
{
    return a->getNickname() < b->getNickname();
}

void PlayerList::sortByName()
{
    players.sort(compareName);
}

void PlayerList::sortByNickname()
{
    players.sort(compareNickname);
}

bool compararStringComNickname(Player *p, string s)
{
    return p->getNickname() == s;
}

int PlayerList::removePlayer(string s)
{   
    for(auto player : players)
    {
        if(player->getNickname() == s)
        {
            players.remove(player);
            saveData();
            return SUCCESS;
        }
    }

    return ERR_PLAYER_NOT_FOUND;
}
void PlayerList::display()
{
    for(auto p : players)
    {
        int* wins = p->getWins();        
        cout << p->getNickname() << " " << p->getName() << endl;
        cout << "REVERSI - " << wins[0] << endl;
        cout << "LIG4 - " << wins[1] << endl;
        cout << "VELHA - " << wins[2] << endl;
        cout << "DAMAS - " << wins[3] << endl;
        cout << "------------------" << endl;


    }
}

//int PlayerList::searchPlayer(string s)
//{
//    int index = 0;
//    for(auto player : players)
//    {
//        if(player->getNickname() == s)
//            return index;
//        index++;
//    }
//    return ERR_PLAYER_NOT_FOUND;
//}
Player* PlayerList::searchPlayer(string s)
{
    for(auto player : players)
        if(player->getNickname() == s)
            return player;
    
    return nullptr;
}

void PlayerList::saveData() {
    ofstream file("data/data.txt");

    for (auto player : players) {
        file << player->getName() << '\n';
        file << player->getNickname() << '\n';
    }

    
}


PlayerList::~PlayerList()
{

}