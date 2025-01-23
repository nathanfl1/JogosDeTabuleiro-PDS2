#include "../include/LigFour.hpp"

#include <iostream>

using namespace std;

LigFour::LigFour(Player *player1, Player *player2): BoardGame(6, 7), player1(player1), player2(player2) {
    playerSymbols[player1->getNickname()] = 'X';
    playerSymbols[player2->getNickname()] = 'O';
};
LigFour::LigFour(): BoardGame(6, 7)
{

};
LigFour::~LigFour(){

}


void LigFour::readRound(pair<int, int> input, pair<int, int> input2, Player *player){
}

void LigFour::readRound(pair<int, int> input, Player *player){
    if (roundIsValid(input)){
        board[input.first][input.second] = playerSymbols[player->getNickname()];
        incrementTurn();
    }
};

bool LigFour::roundIsValid(pair<int,int> place) {
    if(place.first <= 5 && place.first >= 0 && place.second >= 0 && place.second <=6){
        if(isBoardEmpty())
            return true;
        else if(board[place.first][place.second]==' ')
            return true;
    }
    return false;
};

bool LigFour::isBoardFull(){
    for(int l=0; l<getSize().first; l++)
        for(int c=0; c<getSize().second; c++)
            if(board[l][c] == ' ')
                return false;
    return true;
}

bool LigFour::isBoardEmpty(){
    for(int l=0; l<getSize().first; l++)
        for(int c=0; c<getSize().second; c++)
            if(board[l][c] != ' ')
                return false;
    return true;
}

bool LigFour::didPlayerWin(Player *player){
    return false;
}

bool LigFour::didPlayerWin(Player *player, pair<int,int> move){
    char symbol = playerSymbols[player->getNickname()];
    int l = move.first;
    int c = move.second;
    // runningh through all the board (except last 3 columns and lines, as they are not needed)
   
    // vertical test
    for(int i=1; i<=3 && l+i < getSize().first; i++){
        if(board[l+i][c] != symbol){
            break;
        }
        else if(i==3){
            return true;
        }
    }

    // horizontal test
    for(int i=1; i<=3 && c+i < getSize().second; i++){
        if(board[l][c+i] != symbol)
            break;
        else if(i==3){
            return true;
        }
    }

    // primary diagonal test
    for(int i=1; i<=3 && l+i < getSize().first && c+i < getSize().second; i++){
        if(board[l+i][c+i] != symbol)
            break;
        else if(i==3){
            return true;
        }
    }

    // secondary diagonal test
    for(int i=1; i<=3 && l+i < getSize().first && c-i >= 0; i++){
        if(board[l+i][c-i] != symbol)
            break;
        else if(i==3){
            return true;
        }
    }

    return false;
};

void LigFour::startGame(Player *player1, Player *player2){
    Player *currentPlayer = player2;
    pair<int, int> input(-1, -1);
    cout << "Iniciando partida de Lig 4: " << player1->getNickname() << " vs " << player2->getNickname() << endl;
    

    do{
        //reseting and changing important variables
        input.first = -1;
        currentPlayer = (currentPlayer == player1) ? player2 : player1;

        printBoard();

        cout << "Turno <" << getTurn() + 1 << ">"<< endl;

        cout << "Turno de jogador " << currentPlayer->getNickname() << ":" << endl;

        // loop while the column chosen is invalid (first run is default)
        while (input.first == -1){
            cin >> input.second; //reading the column

            // treating wrong inputs
             if (cin.fail()) { 
                cin.clear();  // Limpa o estado de erro
                cin.ignore(1000, '\n'); // Descarta até 1000 caracteres ou até encontrar uma nova linha
                cout << " ERRO: formato incorreto" << endl;
                continue;
            }

            if (input.second < 0 || input.second >= getSize().second) {
                cout << " ERRO: jogada invalida" << endl;
                continue;
            }

            // checking if there is any place empty in the column (from bottom to top)
            for (int i = (getSize().first-1); i >= 0; i--){
                if(board[i][input.second] == ' '){
                    input.first = i;
                    break;
                }
            }
            // checking if the column is avaliable 
            if(input.first == -1){
                cout << " ERRO: jogada invalida" << endl;
                // printBoard();
                continue;
            }
        }
        // cout << "|*|*| coluna valida, par: (" << input.first << " ," << input.second << ")" << endl;

        readRound(input, currentPlayer);
        cout << "**** FIM DA JOGADA ****" << endl << endl;
        

    } while (!didPlayerWin(currentPlayer, input) && !isBoardFull());
    
    cout << endl << "**** FIM DE JOGO ****"  << endl;

    if(didPlayerWin(currentPlayer, input)){
        printBoard();
        cout << currentPlayer->getNickname() << " venceu a partida, parabens!!!";
        currentPlayer->addWin(Player::LIGFOUR);
        (currentPlayer == player1)? (player2->addLoss(Player::LIGFOUR)) : (player1->addLoss(Player::LIGFOUR));
    }
    else
        cout << "A partida terminou em empate! Ninguem venceu desta vez." << endl;    

};