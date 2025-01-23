#include "Manager.hpp"

using namespace std;

Manager::Manager()
{
    playerList = new PlayerList();
    lig = new LigFour();
    check = new Checkers();
    rev = new Reversi();
    tic = new TicTacToe();

    playerList->loadData();
}

void Manager::setParam1(string param1) {
    this->param1 = param1;
}

void Manager::setParam2(string param2) {
    this->param2 = param2;
}

string Manager::getParam1() {
    return param1;
}

string Manager::getParam2() {
    return param2;
}

void Manager::showPrincipalMenu()
{
    cout << "JOGOS DE TABULEIROS" << endl;
    cout << "Escolha uma opção:" << endl;
    cout << "CJ - Cadastrar jogador" << endl;
    cout << "RJ - Remover jogador" << endl;
    cout << "LJ - Listar jogadores" << endl;
    cout << "EP - Jogar" << endl;
    cout << "FS - Sair" << endl;
    
    selectOption();
}

void Manager::selectOption()
{
    Player *player1 = nullptr;
    Player *player2 = nullptr;

    string option;

    while (true)
    {
        cin >> option;

        if (option == "CJ")
        {
            cin >> param1 >> param2;
            showRegisterMenu();
        }

        else if (option == "RJ")
        {
            cin >> param1;
            showRemoveMenu();
        }

        if (option == "EP")
            showGameMenu();

        else if (option == "LJ")
            showListMenu();

        else if (option == "FS")
            break;
    }
}

void Manager::showRegisterMenu()
{
    int result = playerList->addPlayer(new Player(param1, param2));

    if (result == PlayerList::ERR_REPEATED_PLAYER)
        cout << "ERRO: jogador repetido" << endl;

    else if (result == PlayerList::SUCCESS)
        cout << "Jogador <" << param1 << "> adicionado com sucesso" << endl;
}

void Manager::showRemoveMenu()
{

    int result = playerList->removePlayer(param1);

    if (result == PlayerList::SUCCESS)
        cout << "Jogador <" << param1 << "> removido com sucesso" << endl;

    else if (result == PlayerList::ERR_PLAYER_NOT_FOUND)
        cout << "ERRO: jogador inexistente" << endl;
}

void Manager::showListMenu()
{
    cout << "Escolha um critério de ordenação: " << endl;
    cout << "A. Ordenar por apelido" << endl;
    cout << "N. Ordenar por nome" << endl;
    cout << "VT. Ordenar por vitórias totais" << endl;
    cout << "VL. Ordenar por vitórias no LigFour" << endl;
    cout << "VD. Ordenar por vitórias no Dama" << endl;
    cout << "VR. Ordenar por vitórias no Reversi" << endl;
    cout << "VV. Ordenar por vitórias no Velha" << endl;

    cin >> param1;

    if (param1 == "A")
        playerList->sortByNickname();

    else if (param1 == "N")
        playerList->sortByName();

    else if (param1 == "VT")
        playerList->sortVictoriesTotal();

    else if (param1 == "VL")
        playerList->sortByWinsGame(Player::LIGFOUR);

    else if (param1 == "VD")
        playerList->sortByWinsGame(Player::CHECKERS);

    else if (param1 == "VR")
        playerList->sortByWinsGame(Player::REVERSI);

    else if (param1 == "VV")
        playerList->sortByWinsGame(Player::TIKTAKTOE);

    playerList->display();
}

void Manager::showGameMenu()
{
    cout << "Escolha um jogo: " << endl;
    cout << "R. Reversi" << endl;
    cout << "L. LigFour" << endl;
    cout << "V. TicTacToe" << endl;
    cout << "D. Checkers" << endl;

    Player *player1 = nullptr;
    Player *player2 = nullptr;

    char option;

    cin >> option;

    switch (option) {
    case 'R':
        cin >> param1 >> param2;
        
        player1 = playerList->searchPlayer(param1);
        player2 = playerList->searchPlayer(param2);

        if (player1 == nullptr)
            cout << "o jogador <" << param1 << "> não existe!" << endl;
        
        else if (player2 == nullptr)
            cout << "o jogador <" << param2 << "> não existe!" << endl;
           
        else {
            rev->startGame(player1, player2);
            playerList->saveData();
        }

        break;

    case 'L':
        cin >> param1 >> param2;
        player1 = playerList->searchPlayer(param1);
        player2 = playerList->searchPlayer(param2);

        if (player1 == nullptr)
            cout << "o jogador <" << param1 << "> não existe!" << endl;

        else if (player2 == nullptr)
            cout << "o jogador <" << param2 << "> não existe!" << endl;

        else {
            delete lig;
            lig = new LigFour(player1, player2);
            lig->startGame(player1, player2);
            playerList->saveData();
        }

        break;

    case 'V':
        cin >> param1 >> param2;
        player1 = playerList->searchPlayer(param1);
        player2 = playerList->searchPlayer(param2);

        if (player1 == nullptr)
            cout << "o jogador <" << param1 << "> não existe!" << endl;
        
        else if (player2 == nullptr)
            cout << "o jogador <" << param2 << "> não existe!" << endl;
           
        else {
            tic->startGame(player1, player2);
            playerList->saveData();
        }

        break;

    case 'D':
        cin >> param1 >> param2;
        player1 = playerList->searchPlayer(param1);
        player2 = playerList->searchPlayer(param2);

        if (player1 == nullptr)
            cout << "o jogador <" << param1 << "> não existe!" << endl;
        
        else if (player2 == nullptr)
            cout << "o jogador <" << param2 << "> não existe!" << endl;
           
        else {
            check->startGame(player1, player2);
            playerList->saveData();
        }

        break;
    
    default:
        break;
    }
}
