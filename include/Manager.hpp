#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "../include/BoardGame.hpp"
#include "../include/LigFour.hpp"
#include "../include/PlayerList.hpp"
#include "../include/Checkers.hpp"
#include "../include/Reversi.hpp"
#include "../include/TicTacToe.hpp"

class Manager {
    public:
        Manager();
        ~Manager();
        void showPrincipalMenu();

        void setParam1(string);
        void setParam2(string);
        string getParam1();
        string getParam2();


    private:
        void showGameMenu();
        void selectOption();

        void showRegisterMenu();
        void showListMenu();
        void showRemoveMenu();

        string param1, param2;


        PlayerList* playerList;
        LigFour* lig;
        Checkers* check;
        Reversi* rev;
        TicTacToe* tic;
    
};

#endif
