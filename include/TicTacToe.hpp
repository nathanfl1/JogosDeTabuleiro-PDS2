#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "BoardGame.hpp"

class TicTacToe : public BoardGame {
    
private:
    Player *localPlayer1; // Variáveis locais para os jogadores
    Player *localPlayer2;

public:
    TicTacToe(); // Construtor
    void setBoard(); // Inicializa o tabuleiro
    void printBoard(); // Imprime o tabuleiro
    bool roundIsValid(std::pair<int, int> move); // Verifica se a jogada é válida
    void readRound(std::pair<int, int> move, Player *player); // Realiza a jogada
    bool didPlayerWin(Player *player); // Verifica se o jogador venceu
    void startGame(Player *p1, Player *p2); // Inicia o jogo
    ~TicTacToe(); // Destrutor
};

#endif
