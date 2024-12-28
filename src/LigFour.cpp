#include "../include/LigFour.hpp"

#include <iostream>

using namespace std;

LigFour::LigFour(Player *player1, Player *player2): BoardGame(6, 7), player1(player1), player2(player2) {
    playerSymbols[player1->getNickname()] = 'X';
    playerSymbols[player2->getNickname()] = 'O';
};

LigFour::~LigFour(){

}

void LigFour::readRound(pair<int, int> input, Player *player){
    if (roundIsValid(input)){
        cout << "|*|*| ROUND VALIDO" << endl;
        board[input.first][input.second] = playerSymbols[player->getNickname()];
    }
};

bool LigFour::roundIsValid(pair<int,int> place) {
    if(place.first <= 5 && place.first >= 0 && place.second >= 0 && place.second <=6)
        if(isBoardEmpty())
            return true;
        else if(board[place.first][place.second]==' ')
            return true;
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
    char symbol = playerSymbols[player->getNickname()];

    // runningh through all the board (except last 3 columns and lines, as they are not needed)
    for (int l = 0; l < getSize().first; l++){
        for (int c = 0; c < getSize().second; c++){

            if(board[l][c] == symbol){

                // vertical test
                for(int i=1; i<=3 && l+i < getSize().first; i++){
                    if(board[l+i][c] != symbol)
                        break;
                    else if(i==3)
                        return true;
                }

                // horizontal test
                for(int i=1; i<=3 && c+i < getSize().second; i++){
                    if(board[l][c+i] != symbol)
                        break;
                    else if(i==3)
                        return true;
                }

                // primary diagonal test
                for(int i=1; i<=3 && l+i < getSize().first && c+i < getSize().second; i++){
                    if(board[l+i][c+i] != symbol)
                        break;
                    else if(i==3)
                        return true;
                }

                // secondary diagonal test
                for(int i=1; i<=3 && l+i < getSize().first && c-i >= 0; i++){
                    if(board[l+i][c-i] != symbol)
                        break;
                    else if(i==3)
                        return true;
                }
            }
        }
    }
    return false;
};

// bool LigFour::didPlayerWin(Player *player){
//     char symbol = playerSymbols[player->getNickname()];

//     // runningh through all the board (except last 3 columns and lines, as they are not needed)
//     for (int l = 0; l < (getSize().first - 3); l++){
//         for (int c = 0; c < (getSize().second - 3); c++){

//             if(board[l][c] == symbol){

//                 // vertical test
//                 for(int i=1; i<=3; i++){
//                     if(board[l+i][c] != symbol)
//                         break;
//                     else if(i==3)
//                         return true;
//                 }

//                 // horizontal test
//                 for(int i=1; i<=3; i++){
//                     if(board[l][c+i] != symbol)
//                         break;
//                     else if(i==3)
//                         return true;
//                 }

//                 // primary diagonal test
//                 for(int i=1; i<=3; i++){
//                     if(board[l+i][c+i] != symbol)
//                         break;
//                     else if(i==3)
//                         return true;
//                 }
//             }
//             // secondary diagonal test
//             if(board[l][(getSize().second-1)-c] == symbol)
//                 for(int i=1; i<=3; i++){
//                     if(board[l+i][(getSize().second-1)-c-i] != symbol)
//                         break;
//                     else if(i==3)
//                         return true;
//                 }
//         }
//     }
//     return false;
// };


void LigFour::startGame(Player *player1, Player *player2){
    Player *currentPlayer = player2;
    pair<int, int> input(-1, -1);
    cout << "Iniciando partida de Lig 4: " << player1->getNickname() << " vs " << player2->getNickname() << endl;
    

    do{
        //reseting and changing important variables
        input.first = -1;
        currentPlayer = (currentPlayer == player1) ? player2 : player1;

        printBoard();
        cout << "Vez do jogador " << currentPlayer->getNickname() << "!" << endl << "Escolha uma coluna para inserir a peça: ";

        // loop while the column chosen is invalid (first run is default)
        while (input.first == -1){
            cin >> input.second; //reading the column
            input.second--;

            if (input.second < 0 || input.second >= getSize().second) {
                cout << "Coluna inválida!" << endl;
                cout << "Escolha uma nova coluna: ";
                continue;
            }

            // checking if is there any place empty in the column (from bottom to top)
            for (int i = (getSize().first-1); i >= 0; i--){
                if(board[i][input.second] == ' '){
                    input.first = i;
                    break;
                }
            }
            // if there isn't any empty place in  this column: don't let roun happen
            if(input.first == -1){
                cout << "A coluna informada está cheia!" << endl;
                printBoard();
                cout << "Escolha uma nova coluna: ";
                continue;
            }
        }
        cout << "|*|*| coluna valida, par: (" << input.first << " ," << input.second << ")" << endl;

        readRound(input, currentPlayer);
        cout << "**** FIM DA JOGADA ****" << endl << endl;
        

    } while (!didPlayerWin(currentPlayer) && !isBoardFull());
    
    if(didPlayerWin(currentPlayer)){
        printBoard();
        cout << currentPlayer->getNickname() << " venceu a partida, parabéns!!!";
        currentPlayer->addWin();
        currentPlayer == player1? player1->addLoss() : player2->addLoss();
    }
    else
        cout << "A partida terminou em empate! Ninguém venceu desta vez." << endl;

    

};