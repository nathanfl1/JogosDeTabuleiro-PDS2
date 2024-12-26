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
            return SUCCESS;
        }
    }
    return ERR_PLAYER_NOT_FOUND;
}
void PlayerList::display()
{
    for(auto p : players)
    {
        cout << p->getNickname() << " " << p->getName() << endl;
        cout << "REVERSI - em breve" << endl;
        cout << "LIG4 - em breve" << endl;
        cout << "VELHA - em breve" << endl;
        cout << "DAMAS - em breve" << endl;
        cout << "------------------" << endl;


    }
}
PlayerList::~PlayerList()
{

}