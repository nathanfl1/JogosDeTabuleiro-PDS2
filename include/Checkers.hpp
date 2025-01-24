#ifndef CHECKERS_H
#define CHECKERS_H

#include "BoardGame.hpp"
#include <iostream>
using namespace std;

class Checkers : public BoardGame
{
private:
    // Nenhum dado adicional privado específico foi adicionado até o momento.

public:
    // Definições de status para as jogadas
    const static int SUCCESS = 1;         ///< Jogada bem-sucedida
    const static int NOT_SUCCESS = 0;     ///< Jogada não válida
    const static int CAPTURE_AGAIN = 2;   ///< Captura disponível, o jogador deve capturar novamente

    /**
     * @brief Construtor da classe Checkers.
     * Inicia o jogo de damas, criando um tabuleiro de 8x8.
     */
    Checkers();

    /**
     * @brief Verifica se o jogador venceu o jogo.
     * @param p O jogador a ser verificado.
     * @return Retorna true se o jogador venceu, caso contrário false.
     */
    bool didPlayerWin(Player* p);

    /**
     * @brief Lê e executa uma jogada simples, movendo uma peça do jogador para uma nova posição.
     * @param coordinate Posição inicial da peça.
     * @param player O jogador que está fazendo a jogada.
     */
    void readRound(pair<int, int> coordinate, Player* player);

    /**
     * @brief Lê e executa uma jogada onde uma peça se move para uma nova posição, podendo capturar uma peça adversária.
     * @param coordinate Posição inicial da peça.
     * @param destination Posição de destino da peça.
     * @param player O jogador que está fazendo a jogada.
     */
    void readRound(pair<int, int> coordinate, pair<int, int> destination, Player* player);

    /**
     * @brief Verifica se a jogada é válida para uma peça comum (não dama).
     * @param coordinate Posição inicial da peça.
     * @param destination Posição de destino da peça.
     * @param player Número do jogador (1 ou 2).
     * @return Retorna o status da jogada (SUCCESS, NOT_SUCCESS ou CAPTURE_AGAIN).
     */
    int roundIsValid(pair<int, int> coordinate, pair<int, int> destination, int player);

    /**
     * @brief Verifica se a jogada é válida para uma dama.
     * @param coordinate Posição inicial da dama.
     * @param destination Posição de destino da dama.
     * @param player Número do jogador (1 ou 2).
     * @return Retorna o status da jogada (SUCCESS ou NOT_SUCCESS).
     */
    int roundIsValidQueen(pair<int, int> coordinate, pair<int, int> destination, int player);

    /**
     * @brief Verifica se o jogador venceu com base na peça dele.
     * @param player O número do jogador (1 ou 2).
     * @return Retorna true se o jogador venceu, caso contrário false.
     */
    bool didPlayerWin(int player);

    /**
     * @brief Verifica se a peça pode capturar uma dama adversária.
     * @param coordinate Posição inicial da peça.
     * @param destination Posição de destino da peça.
     * @param player Número do jogador (1 ou 2).
     * @return Retorna true se a peça pode capturar a dama, caso contrário false.
     */
    bool canCaptureQueen(pair<int, int> coordinate, pair<int, int> destination, int player);

    /**
     * @brief Verifica se a jogada é válida para uma peça comum (não dama).
     * @param coordinate Posição inicial da peça.
     * @return Retorna true se a jogada for válida, caso contrário false.
     */
    bool roundIsValid(pair<int, int> coordinate);

    /**
     * @brief Verifica se a peça pode capturar outra peça adversária.
     * @param coordinate Posição inicial da peça.
     * @param destination Posição de destino da peça.
     * @param player Número do jogador (1 ou 2).
     * @return Retorna true se a peça pode capturar, caso contrário false.
     */
    bool canCapture(pair<int, int> coordinate, pair<int, int> destination, int player);

    /**
     * @brief Realiza a captura de todas as peças adversárias disponíveis no tabuleiro.
     * @param currentCoordinate Posição inicial da peça.
     * @param playerNumber Número do jogador (1 ou 2).
     * @param player O jogador atual que está fazendo a captura.
     */
    void captureAllAvaliablePieces(pair<int, int> currentCoordinate, int playerNumber, Player* player);

    /**
     * @brief Inicializa o tabuleiro de damas.
     * A posição das peças é configurada para o início de um jogo de damas padrão.
     */
    void setBoard();

    /**
     * @brief Inicia o jogo entre dois jogadores.
     * Controla os turnos e executa as jogadas de ambos os jogadores até que haja um vencedor.
     * @param player1 O primeiro jogador.
     * @param player2 O segundo jogador.
     */
    void startGame(Player* player1, Player* player2);

    /**
     * @brief Destruidor da classe Checkers.
     * Libera qualquer recurso alocado durante a execução do jogo.
     */
    ~Checkers();
};

#endif