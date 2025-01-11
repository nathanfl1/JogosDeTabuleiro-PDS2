#include "../include/BoardGame.hpp"
#include "../include/LigFour.hpp"
#include "../include/PlayerList.hpp"
#include <iostream>
using namespace std;

int main(void)
{
    string option = "s";
    char option2 = '0';
    int result;

    string param1, param2;

    Player *player1 = nullptr;    
    Player *player2 = nullptr;

    LigFour l = LigFour();
    PlayerList list;
    list.loadData();
   // list.saveData();

    while (true)  {
        cin >> option;

        if (option == "CJ" || option == "cj") {
            cin >> param1 >> param2;
            result = list.addPlayer(new Player(param1, param2));
            
            if (result == PlayerList::ERR_REPEATED_PLAYER)
                cout << "ERRO: jogador repetido" << endl;

            else if (result == PlayerList::SUCCESS)
                cout << "Jogador <" << param1  << "> adicionado com sucesso" << endl;
        }

        else if (option == "RJ" || option == "rj") {
            cin >> param1;
            result = list.removePlayer(param1);

            if (result == PlayerList::SUCCESS)
                cout << "Jogador <" << param1  << "> removido com sucesso" << endl;

            else if (result == PlayerList::ERR_PLAYER_NOT_FOUND) 
                cout << "ERRO: jogador inexistente" << endl;
        }

        else if (option == "LJ") {
            cin >> param1;

            if (param1 == "A")
                list.sortByNickname();

            else if (param1 == "N")
                list.sortByName();

            list.display();
        }

        else if (option == "EP") {
            cin >> option2;

            switch (option2) {
            case 'R':
                break;

            case 'L':
                cin >> param1 >> param2;
                player1 = list.searchPlayer(param1);
                player2 = list.searchPlayer(param2);

                l = LigFour(player1, player2);
                l.startGame(player1, player2);
                break;

            case 'V':
                break;

            case 'D':
                break;

            default:
                break;
            }
        }
        else if (option == "FS")
            break;
    }
}