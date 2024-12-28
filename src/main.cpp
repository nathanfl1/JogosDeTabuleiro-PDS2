#include "../include/BoardGame.hpp"
#include "../include/LigFour.hpp"
#include "../include/PlayerList.hpp"
#include <iostream>
using namespace std;
int main()
{
    string option = "s";
    string param1, param2;
    PlayerList list;
    while (true)
    {
        cin >> option;
        if (option == "CJ")
        {
            cin >> param1 >> param2;
            list.addPlayer(new Player(param1, param2));
        }
        else if (option == "RJ")
        {
            cin >> param1;
            list.removePlayer(param1);
        }
        else if (option == "LJ")
        {
            cin >> param1;
            if (param1 == "A")
                list.sortByNickname();
            else if (param1 == "N")
                list.sortByName();
            list.display();
        }
        else if(option == "FS")
            break; 
    }
}