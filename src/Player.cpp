#include "../include/Player.hpp"

Player::Player(string nickname, string name): nickname(nickname),name(name){
    for (int i = 0; i < 4; i++)
    {
        wins[i] = 0;
        losses[i] = 0;
    }
    
}

void Player::addWin(int game){
    wins[game]++;
}
void Player::addLoss(int game){
    losses[game]++;
}
int* Player::getWins(){
    return wins;
}
int* Player::getLosses(){
    return losses;
}
string Player::getName(){
    return name;
};
string Player::getNickname(){
    return nickname;
};