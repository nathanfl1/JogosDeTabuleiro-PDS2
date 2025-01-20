#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "BoardGame.hpp"

class TicTacToe : public BoardGame {
public:
    TicTacToe();
    void setBoard();  // Inicializa o tabuleiro
    void printBoard() const;  // Exibe o tabuleiro
    bool roundIsValid(pair<int, int>) override; 
    void readRound(pair<int, int>, Player *) override;  // Executa o round
    bool didPlayerWin(Player *) override; 
    void startGame(Player *player1, Player *player2) override;  // Inicia o game
    ~TicTacToe(); 
};

#endif
