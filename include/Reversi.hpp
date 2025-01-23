#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "BoardGame.hpp"
#include <iostream>
#include <vector>

using namespace std;

/**
 * @class Reversi
 * @brief Representa o jogo de Reversi (ou Othello).
 * 
 * A classe Reversi implementa a lógica do jogo de Reversi, incluindo regras de movimento,
 * validação de jogadas, e verificação de vitória.
 */
class Reversi : public BoardGame {
public:
    /**
     * @brief Construtor da classe Reversi.
     * 
     * Inicializa o jogo configurando o tabuleiro e os parâmetros necessários.
     */
    Reversi();

    /**
     * @brief Configura o tabuleiro do jogo.
     * 
     * Inicializa o tabuleiro com as peças iniciais do jogo Reversi.
     */
    void setBoard(); 

    /**
     * @brief Verifica se o jogador venceu.
     * @param player O número do jogador (1 ou 2).
     * @return Retorna true se o jogador venceu, false caso contrário.
     */
    bool didPlayerWin(int player);

    /**
     * @brief Verifica se o jogador venceu (usando um ponteiro para o jogador).
     * @param player Ponteiro para o objeto jogador.
     * @return Retorna true se o jogador venceu, false caso contrário.
     */
    bool didPlayerWin(Player* player) override; 

    /**
     * @brief Inicia o jogo.
     * @param player1 Ponteiro para o jogador 1.
     * @param player2 Ponteiro para o jogador 2.
     * Inicia a partida, alternando entre os jogadores e realizando as jogadas.
     */
    void startGame(Player* player1, Player* player2) override; 

    /**
     * @brief Verifica se a jogada do jogador é válida.
     * @param destination Coordenada de destino da jogada.
     * @param player Número do jogador (1 ou 2).
     * @return Retorna true se a jogada é válida, false caso contrário.
     */
    bool roundIsValid(pair<int, int> destination, int player);

    /**
     * @brief Verifica se a jogada é válida (overload para usar apenas a coordenada).
     * @param destination Coordenada de destino da jogada.
     * @return Retorna false (não implementado, mas pode ser extendido).
     */
    bool roundIsValid(pair<int, int>) override;

    /**
     * @brief Realiza a jogada de um jogador, colocando a peça no tabuleiro.
     * @param destination Coordenada de destino da jogada.
     * @param player Número do jogador (1 ou 2).
     * Atualiza o tabuleiro e as peças do jogo de acordo com as regras.
     */
    void readRound(pair<int, int> destination, int player);

    /**
     * @brief Realiza a jogada de um jogador, colocando a peça no tabuleiro.
     * @param destination Coordenada de destino da jogada.
     * @param player Ponteiro para o jogador.
     * Atualiza o tabuleiro e as peças do jogo de acordo com as regras.
     */
    void readRound(pair<int, int> destination, Player* player) override;

    /**
     * @brief Encontra todas as peças que devem ser viradas após uma jogada.
     * @param destination Coordenada da jogada.
     * @param player Número do jogador (1 ou 2).
     * @return Retorna um vetor de coordenadas das peças a serem viradas.
     */
    vector<pair<int, int>> allPiecesToFlip(pair<int, int> destination, int player);

    /**
     * @brief verifica se há um movimento válido para o jogador
     * @param player numero do jogador 
     * @return retorna true se houver um movimento válido, false caso contrário
     */
    bool validMove(int player);

    /**
     * @brief Destruidor da classe Reversi.
     * Libera qualquer recurso alocado, caso necessário.
     */
    ~Reversi();
};

#endif
