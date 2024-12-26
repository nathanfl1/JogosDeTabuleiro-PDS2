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

bool LigFour::didPlayerWin(Player *player){
    char symbol = playerSymbols[player->getNickname()];

    // runningh through all the board (except last 3 collumns and lines, as they are not needed)
    for (int l = 0; l < (getSize().first - 3); l++){
        for (int c = 0; c < (getSize().second - 3); c++){

            if(board[l][c] == symbol){

                // vertical test
                for(int i=1; i<=3; i++){
                    if(board[l+i][c] != symbol)
                        break;
                    else if(i==3)
                        return true;
                }

                // horizontal test
                for(int i=1; i<=3; i++){
                    if(board[l][c+i] != symbol)
                        break;
                    else if(i==3)
                        return true;
                }

                // primary diagonal test
                for(int i=1; i<=3; i++){
                    if(board[l+i][c+i] != symbol)
                        break;
                    else if(i==3)
                        return true;
                }
            }
            // secondary diagonal test
            if(board[l][(getSize().second-1)-c] == symbol)
                for(int i=1; i<=3; i++){
                    if(board[l+i][(getSize().second-1)-c-i] != symbol)
                        break;
                    else if(i==3)
                        return true;
                }
        }
    }
    return false;
};