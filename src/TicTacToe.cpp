#include "../include/TicTacToe.hpp"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Define o tamanho do tabuleiro para 3x3
TicTacToe::TicTacToe() : BoardGame(3, 3), localPlayer1(nullptr), localPlayer2(nullptr) {}

// Inicializa o tabuleiro com espaços vazios
void TicTacToe::setBoard() {
    for (int i = 0; i < getX(); i++) {
        for (int j = 0; j < getY(); j++) {
            getBoard()[i][j] = ' ';
        }
    }
}

// // Imprime o tabuleiro
// void TicTacToe::printBoard() {
//     cout << "   0   1   2\n"; // Indice das colunas
//     for (int i = 0; i < getX(); i++) {
//         cout << i << " "; //Indice da linha
//         for (int j = 0; j < getY(); j++) {
//             cout << " " << (getBoard()[i][j] == '\0' ? ' ' : getBoard()[i][j]) << " ";
//             if (j < getY() - 1) cout << "|"; // Adiciona separadores verticais
//         }
//         cout << endl;
//         if (i < getX() - 1) cout << " ---|---|---\n";  // Separadores horizontais
//     }
// }


// Verifica se uma jogada é válida
bool TicTacToe::roundIsValid(pair<int, int> move) {
    if (!isInsideBoard(move)) return false;  // Fora do tabuleiro
    if (getBoard()[move.first][move.second] != ' ') return false;  // Posição ocupada

    incrementTurn();

    return true;
}

// Lê e realiza a jogada
void TicTacToe::readRound(pair<int, int> move, Player *player) {
    if (roundIsValid(move)) {
        getBoard()[move.first][move.second] = (player == localPlayer1) ? 'X' : 'O';
    } else {
        cout << "ERRO: Jogada inválida. Tente novamente." << endl;
    }
}

// Verifica se o jogador venceu
bool TicTacToe::didPlayerWin(Player *player) {
    char symbol = (player == localPlayer1) ? 'X' : 'O';

    // Verifica linhas e colunas
    for (int i = 0; i < getX(); i++) {
        if (getBoard()[i][0] == symbol && getBoard()[i][1] == symbol && getBoard()[i][2] == symbol) return true;  // Linha
        if (getBoard()[0][i] == symbol && getBoard()[1][i] == symbol && getBoard()[2][i] == symbol) return true;  // Coluna
    }

    // Verifica diagonais
    if (getBoard()[0][0] == symbol && getBoard()[1][1] == symbol && getBoard()[2][2] == symbol) return true;
    if (getBoard()[0][2] == symbol && getBoard()[1][1] == symbol && getBoard()[2][0] == symbol) return true;

    return false;
}

// Inicia o jogo
void TicTacToe::startGame(Player *p1, Player *p2) {
    localPlayer1 = p1;
    localPlayer2 = p2;
    setBoard();

    Player *currentPlayer = localPlayer1;
    int moves = 0;
    const int maxMoves = getX() * getY();

    while (moves < maxMoves) {
        printBoard();

        cout << "Turno <" << getTurn() + 1 << ">"<< endl;

        cout << "Turno de jogador " << currentPlayer->getNickname() << ": ";

        string input;
        getline(cin, input);

        // Valida a entrada no formato linha coluna
        stringstream ss(input);
        int x, y;

        if (!(ss >> x >> y)) {
            cout << "ERRO: Entrada inválida. Digite dois números inteiros." << endl;
            continue;
        }

        pair<int, int> move = {x, y};

        if (roundIsValid(move)) {
            readRound(move, currentPlayer);
            moves++;

            if (didPlayerWin(currentPlayer)) {
                printBoard();
                cout << "Jogador " << currentPlayer->getNickname() << " venceu!" << endl;
                currentPlayer->addWin(Player::TIKTAKTOE);
                (currentPlayer == localPlayer1 ? localPlayer2 : localPlayer1)->addLoss(Player::TIKTAKTOE);
                return;
            }

            // Troca de turno
            currentPlayer = (currentPlayer == localPlayer1) ? localPlayer2 : localPlayer1;
        } else {
            cout << "Jogada inválida. Tente novamente." << endl;
        }
    }

    // Caso ocorra empate
    printBoard();
    cout << "O jogo terminou empatado!" << endl;
}

// Destrutor
TicTacToe::~TicTacToe() {}
