#include "../include/Player.hpp"

Player::Player(string name, string nickname): name(name), nickname(nickname){
    wins = 0;
    losses = 0;
}

void Player::addWin(){
    wins++;
}
void Player::addLoss(){
    losses++;
}
int Player::getWins(){
    return wins;
}
int Player::getLosses(){
    return losses;
}
string Player::getName(){
    return name;
};
string Player::getNickname(){
    return nickname;
};