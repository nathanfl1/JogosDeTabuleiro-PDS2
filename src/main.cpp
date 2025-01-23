#include "../include/BoardGame.hpp"
#include "../include/LigFour.hpp"
#include "../include/PlayerList.hpp"
#include "../include/Checkers.hpp"
#include "../include/Reversi.hpp"
#include "../include/Tictactoe.hpp"
#include <iostream>

using namespace std;

int main(void) {
    string option = "s";
    char option2 = '0';
    
    int result;

    string param1, param2;

    Player* player1 = nullptr;
    Player* player2 = nullptr;

    LigFour* l = new LigFour();
    Checkers* c = new Checkers();
    Reversi* r = new Reversi();
    TicTacToe* t = new TicTacToe(); 

    PlayerList* list = new PlayerList();
    list->loadData();

    while (true)
    {
        cin >> option;

        if (option == "CJ" || option == "cj")
        {
            cin >> param1 >> param2;
            result = list->addPlayer(new Player(param1, param2));

            if (result == PlayerList::ERR_REPEATED_PLAYER)
                cout << "ERRO: jogador repetido" << endl;

            else if (result == PlayerList::SUCCESS)
                cout << "Jogador <" << param1 << "> adicionado com sucesso" << endl;
        }

        else if (option == "RJ" || option == "rj")
        {
            cin >> param1;
            result = list->removePlayer(param1);

            if (result == PlayerList::SUCCESS)
                cout << "Jogador <" << param1 << "> removido com sucesso" << endl;

            else if (result == PlayerList::ERR_PLAYER_NOT_FOUND)
                cout << "ERRO: jogador inexistente" << endl;
        }

        else if (option == "LJ")
        {
            cin >> param1;

            if (param1 == "A")
                list->sortByNickname();

            else if (param1 == "N")
                list->sortByName();

            list->display();
        }

        else if (option == "EP")
        {
            cin >> option2;

            switch (option2)
            {
            case 'R'://Reversi
                cin >> param1 >> param2;
                player1 = list->searchPlayer(param1);
                player2 = list->searchPlayer(param2);

                if (player1 == nullptr)
                    cout << "o jogador <" << param1 << "> não existe!" << endl;
                else if (player2 == nullptr)
                    cout << "o jogador <" << param2 << "> não existe!" << endl;
                    
                else {
                    r->startGame(player1, player2);
                    list->saveData();
                }

                break;

            case 'L'://LigFour
                cin >> param1 >> param2;
                player1 = list->searchPlayer(param1);
                player2 = list->searchPlayer(param2);
                if (player1 == nullptr)
                    cout << "o jogador <" << param1 << "> não existe!" << endl;

                else if (player2 == nullptr)
                    cout << "o jogador <" << param2 << "> não existe!" << endl;

                else {
                    delete l;

                    l = new LigFour(player1, player2);
                    l->startGame(player1, player2);
                    list->saveData();
                }
                break;

            case 'V': //Tictactoe
                cin >> param1 >> param2;
                player1 = list->searchPlayer(param1);
                player2 = list->searchPlayer(param2);

                if (player1 == nullptr)
                    cout << "o jogador <" << param1 << "> não existe!" << endl;
                else if (player2 == nullptr)
                    cout << "o jogador <" << param2 << "> não existe!" << endl;
                    
                else {
                    t->startGame(player1, player2); // Inicia o jogo da velha
                    list->saveData();
                }
                break;

            case 'D'://Checkers
                cin >> param1 >> param2;
                player1 = list->searchPlayer(param1);
                player2 = list->searchPlayer(param2);

                if (player1 == nullptr)
                    cout << "o jogador <" << param1 << "> não existe!" << endl;
                else if (player2 == nullptr)
                    cout << "o jogador <" << param2 << "> não existe!" << endl;
                    
                else {
                    c->startGame(player1, player2);
                    list->saveData();
                }

                break;

            default:
                break;
            }
        }
        else if (option == "FS")
            break;
    }

    return 0;
}
