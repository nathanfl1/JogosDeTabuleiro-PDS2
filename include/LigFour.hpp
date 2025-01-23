#ifndef LIGFOUR_H
#define LIGFOUR_H

#include "BoardGame.hpp"
#include "Player.hpp"
#include <map>

using namespace std;

/**
 * @brief Classe que implementa o jogo Lig Four (Conecta 4).
 * 
 * Essa classe herda de BoardGame e gerencia a lógica do jogo, incluindo turnos,
 * validação de jogadas, verificação de vitória e controle de jogadores.
 */
class LigFour : public BoardGame {
private:
    Player *player1; ///< Ponteiro para o primeiro jogador.
    Player *player2; ///< Ponteiro para o segundo jogador.
    map<string, char> playerSymbols; ///< Mapeia os apelidos dos jogadores para seus símbolos no tabuleiro.

public:
    /**
     * @brief Construtor da classe LigFour.
     * 
     * Inicializa o jogo com os dois jogadores fornecidos, configurando o tabuleiro
     * com 6 linhas e 7 colunas, e associa os símbolos 'X' e 'O' aos jogadores.
     * 
     * @param player1 Ponteiro para o primeiro jogador.
     * @param player2 Ponteiro para o segundo jogador.
     */
    LigFour(Player *player1, Player *player2);

    /**
     * @brief Construtor padrão da classe LigFour.
     * 
     * Inicializa o tabuleiro com 6 linhas e 7 colunas sem associar jogadores.
     */
    LigFour();

    /**
     * @brief Destrutor da classe LigFour.
     * 
     * Libera recursos utilizados pela classe, se necessário.
     */
    ~LigFour();

    /**
     * @brief Inicia uma partida de Lig Four.
     * 
     * Gerencia o fluxo do jogo, alternando turnos entre os jogadores até que
     * haja um vencedor ou o tabuleiro esteja cheio. Atualiza estatísticas dos jogadores
     * ao final da partida.
     * 
     * @param player1 Ponteiro para o primeiro jogador.
     * @param player2 Ponteiro para o segundo jogador.
     */
    void startGame(Player *player1, Player *player2) override;

    /**
     * @brief Lê a jogada de um jogador.
     * 
     * Verifica se a jogada é válida e atualiza o tabuleiro com o símbolo do jogador,
     * caso seja.
     * 
     * @param input Coordenadas da jogada no tabuleiro.
     * @param player Ponteiro para o jogador atual.
     */
    void readRound(pair<int, int> input, Player *player) override;

    /**
     * @brief Lê a jogada de um jogador (versão com dois inputs).
     * 
     * Este método é uma sobrecarga, mas não está implementado na lógica atual.
     * 
     * @param input Coordenadas da jogada.
     * @param input2 Coordenadas adicionais (não utilizadas).
     * @param player Ponteiro para o jogador atual.
     */
    void readRound(pair<int, int> input, pair<int, int> input2, Player *player);

    /**
     * @brief Verifica se uma jogada é válida.
     * 
     * Checa se a jogada está dentro dos limites do tabuleiro e se a célula
     * correspondente está vazia.
     * 
     * @param place Coordenadas da jogada no tabuleiro.
     * @return true se a jogada for válida, false caso contrário.
     */
    bool roundIsValid(pair<int, int> place) override;

    /**
     * @brief Verifica se um jogador venceu a partida.
     * 
     * Checa combinações de 4 símbolos consecutivos do jogador nas direções:
     * horizontal, vertical, diagonal principal e diagonal secundária.
     * 
     * @param player Ponteiro para o jogador.
     * @param move Jogada feita pelo jogador.
     * @return true se o jogador venceu, false caso contrário.
     */
    bool didPlayerWin(Player *player, pair<int, int> move);


    /**
     * @brief Verifica se um jogador venceu a partida.
     * 
     * Checa combinações de 4 símbolos consecutivos do jogador nas direções:
     * horizontal, vertical, diagonal principal e diagonal secundária.
     * 
     * @param player Ponteiro para o jogador.
     * @return true se o jogador venceu, false caso contrário.
     */
    bool didPlayerWin(Player *player);


    /**
     * @brief Verifica se o tabuleiro está completamente cheio.
     * 
     * Itera sobre todas as células do tabuleiro e verifica se há alguma vazia.
     * 
     * @return true se o tabuleiro estiver cheio, false caso contrário.
     */
    bool isBoardFull();

    /**
     * @brief Verifica se o tabuleiro está completamente vazio.
     * 
     * Itera sobre todas as células do tabuleiro e verifica se todas estão vazias.
     * 
     * @return true se o tabuleiro estiver vazio, false caso contrário.
     */
    bool isBoardEmpty();
};

#endif
