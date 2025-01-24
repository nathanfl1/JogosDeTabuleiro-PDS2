/**
 * @file TicTacToe.hpp
 * @brief Declaração da classe TicTacToe, que implementa o jogo da velha.
 * 
 * Este arquivo contém a definição da classe `TicTacToe`, que herda de `BoardGame` e é responsável pela lógica do jogo da velha.
 * Ele gerencia os jogadores, o tabuleiro, as jogadas e a verificação de vitória.
 * 
 * @see TicTacToe.cpp
 */

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "BoardGame.hpp"

/**
 * @class TicTacToe
 * @brief Classe que representa o jogo da velha (TicTacToe).
 * 
 * A classe `TicTacToe` herda da classe `BoardGame` e é responsável por gerenciar a lógica do jogo,
 * como realizar jogadas, verificar a vitória de um jogador e controlar os turnos dos jogadores.
 */
class TicTacToe : public BoardGame {
    
private:
    Player *localPlayer1; ///< Ponteiro para o jogador 1
    Player *localPlayer2; ///< Ponteiro para o jogador 2

public:
    /**
     * @brief Construtor da classe TicTacToe.
     * 
     * Inicializa o tabuleiro 3x3 e define os jogadores como nulos.
     */
    TicTacToe();

    /**
     * @brief Inicializa o tabuleiro com espaços vazios.
     * 
     * Preenche o tabuleiro com espaços em branco, indicando que todas as células estão vazias.
     */
    void setBoard();

    /**
     * @brief Verifica se uma jogada é válida.
     * 
     * Uma jogada é válida se ela está dentro dos limites do tabuleiro e a posição escolhida está vazia.
     * 
     * @param move A jogada a ser validada, representada por um par de coordenadas (linha, coluna).
     * @return True se a jogada for válida, caso contrário, false.
     */
    bool roundIsValid(std::pair<int, int> move);

    /**
     * @brief Realiza a jogada de um jogador no tabuleiro.
     * 
     * A jogada é feita apenas se a posição for válida.
     * 
     * @param move A jogada do jogador, representada por um par de coordenadas (linha, coluna).
     * @param player O jogador que está fazendo a jogada.
     */
    void readRound(std::pair<int, int> move, Player *player);

    /**
     * @brief Verifica se o jogador venceu.
     * 
     * Verifica se o jogador alcançou uma linha, coluna ou diagonal com três símbolos iguais.
     * 
     * @param player O jogador a ser verificado.
     * @return True se o jogador venceu, caso contrário, false.
     */
    bool didPlayerWin(Player *player);

    /**
     * @brief Inicia o jogo.
     * 
     * Configura os jogadores e o tabuleiro, e inicia o loop de turnos, verificando as jogadas, a vitória ou empate.
     * 
     * @param p1 O jogador 1.
     * @param p2 O jogador 2.
     */
    void startGame(Player *p1, Player *p2);

    /**
     * @brief Destrutor da classe TicTacToe.
     * 
     * Destrói o objeto TicTacToe. Neste caso, não há alocação dinâmica a ser limpa.
     */
    ~TicTacToe();
};

#endif
