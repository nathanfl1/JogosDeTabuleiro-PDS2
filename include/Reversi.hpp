#ifndef REVERSI_HPP
#define REVERSI_HPP


#include "BoardGame.hpp"
#include <iostream>
#include <vector>



using namespace std;

class Reversi : public BoardGame {
public:
    Reversi();

    void setBoard(); 
    bool didPlayerWin(Player* player) override; 
    bool didPlayerWin(int player);
    void startGame(Player* player1, Player* player2) override; 
    bool roundIsValid(pair<int, int> destination, int player);
    bool roundIsValid(pair<int, int> destination) override;
    void readRound(pair<int, int> destination, int player);
    void readRound(pair<int, int> destination, Player *player) override;
    vector<pair<int, int>> allPiecesToFlip(pair<int, int> destination, int player);
    bool validMove(int player);
    ~Reversi();
};

#endif 
