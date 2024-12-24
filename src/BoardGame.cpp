#include <iostream>
#include <string>
#include "../include/BoardGame.hpp"

using namespace std;

void BoardGame::printBoard(){
    for(int l=0; l<getSize().first; l++){
        for(int c=0; c<getSize().second; c++){
            cout << "| " << board[l][c] << " "; 
        }
        cout << "|" << endl;
    }
}

void BoardGame::setBoard()
{
    for(int l=0; l<getSize().first; l++){
        for(int c=0; c<getSize().second; c++){
            board[l][c] = ' '; 
        }
    }
}

BoardGame::BoardGame(int x, int y)
{
    
    setSize(x, y);

    board = new char*[x]; 
    for (int i = 0; i < x; i++) {
        board[i] = new char[y];
    }
    setBoard();

}
pair<int, int> BoardGame::getSize(){
    return size;
}

void BoardGame::setSize(int x, int y) {
    this->size.first = x;
    this->size.second = y;
}

int BoardGame::getX() {
    return getSize().first;
}

int BoardGame::getY() {
    return getSize().second;
}
BoardGame::~BoardGame(){
    for(int i=0; i<getX(); i++) {
        delete[] board[i];
        board[i] = nullptr;
    }
    
    delete[] board;
    

}


