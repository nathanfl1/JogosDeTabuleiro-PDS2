#include "../include/PlayerList.hpp"
#include <vector>
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

int PlayerList::removePlayer(string s)
{   
    for (auto player : players)
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


void PlayerList::display()
{
    for(auto p : players)
    {
        int* wins = p->getWins(); 
        int* losses = p->getLosses();

        cout << "<" << p->getNickname() << "> <" << p->getName() << ">" << endl;
        cout << "REVERSI - V: <" << wins[Player::REVERSI] << "> D: <" << losses[Player::REVERSI] <<  ">" << endl;
        cout << "LIG4 - V: <" << wins[Player::LIGFOUR]  << "> D: <" << losses[Player::LIGFOUR] << ">" << endl;
        cout << "VELHA - V: <" << wins[Player::TIKTAKTOE] << "> D: <" << losses[Player::TIKTAKTOE] << ">" << endl;
        cout << "DAMAS - V: <" << wins[Player::CHECKERS] << "> D: <" << losses[Player::CHECKERS] << ">" << endl;;
        cout << "---------------------------" << endl;
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

    // for (auto player : players) {
    //     file << player->getName() << '\n';
    //     file << player->getNickname() << '\n';
    // }


    for (auto player : players) {
        file << player->getNickname() << '\n';
        file << player->getName() << '\n';
        
        int* wins = player->getWins();
        int* losses = player->getLosses();

        for (int i = 0; i < 3; i++) 
            file << wins[i] << ' ';
            
        file << wins[3];
        file << '\n';

        for (int i = 0; i < 3; i++) 
            file << losses[i] << ' '; 
            
        file << wins[3];
        file << '\n'; 
    }

    file.close();
}

vector<string> split(string& s, string& delimiter) {
    vector<string> tokens;
    size_t pos = 0;
    string token;

    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(token);
        
        s.erase(0, (pos + delimiter.length()));
    }

    tokens.push_back(s);

    return tokens;
}

void PlayerList::loadData() {
    ifstream file("data/data.txt");

    string nickname, name;
    nickname.erase();
    string line;
    int wins[4], losses[4];
    string winsString, lossesString;
    
    while (getline(file, nickname)) {
        //cout << "nickname: " << nickname << endl;
        getline(file, name);
        //cout << "name: " << name << endl;
        getline(file, winsString);
        //cout << "wins: " << WinsString << endl;
        getline(file, lossesString);
        //cout << "losses: " << stringLosses << endl;
        string space = " ";

        
        vector<string> parsedWinsString = split(winsString, space);
        for (int i = 0; i < 4; i++)
            wins[i] = stoi(parsedWinsString[i]);
        
        vector<string> parsedLossesString = split(lossesString, space);
        for (int i = 0; i < 4; i++)
            losses[i] = stoi(parsedLossesString[i]);
        
        Player* a = new Player(nickname, name);

        a->setWins(wins);
        a->setLosses(losses);

        players.push_back(a);
    }

    file.close();
}



PlayerList::~PlayerList() {
    for (auto player : players)
        delete player;
}