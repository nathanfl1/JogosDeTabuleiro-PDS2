#include "../include/LigFour.hpp"

#include <iostream>

using namespace std;

LigFour::LigFour(Player *player1, Player *player2): BoardGame(6, 7), player1(player1), player2(player2) {
    playerSymbols[player1->getNickname()] = 'X';
    playerSymbols[player2->getNickname()] = 'O';
};

LigFour::~LigFour(){
    delete player1;
    delete player2;
}

void LigFour::readRound(pair<int, int> input, Player *player){
    if (roundIsValid(input)){
        board[input.first][input.second] = playerSymbols[player->getNickname()];
    }
};

bool LigFour::roundIsValid(pair<int,int> place) {
    if(place.first <= 5 && place.first >= 0 && place.second >= 0 && place.second <=6)
        if(board[place.first][place.second]==' ' && board[place.first-1][place.second]!=' ')
            return true;
    return false;
};

bool LigFour::didPlayerWin(){

};