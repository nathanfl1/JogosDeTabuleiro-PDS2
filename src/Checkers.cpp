#include "../include/Checkers.hpp"

using namespace std;

Checkers::Checkers() : BoardGame(8, 8)
{
}

bool isEven(int a)
{
    return a % 2 == 0;
}

bool isOdd(int a)
{
    return !isEven(a);
}

void Checkers::setBoard()
{
    for (int l = 0; l < getSize().first; l++)
    {
        for (int c = 0; c < getSize().second; c++)
        {
            if (isEven(l + c))
            {
                if (l < 3)
                    board[l][c] = 'O';
                else if (l >= 5)
                    board[l][c] = 'X';
                else
                    board[l][c] = ' ';
            }
            else
            {
                board[l][c] = '-';
            }
        }
    }
}

bool Checkers::didPlayerWin(int player)
{
    char opponentPiece;

    if (player == 1) 
        opponentPiece = 'X';
    
    else opponentPiece = 'O';

    for (int l = 0; l < getSize().first; l++)
        for (int c = 0; c < getSize().second; c++) 
            if (board[l][c] == opponentPiece)
                return false;
    
    return true;
}

void Checkers::readRound(pair<int, int> coordinate, Player *player)
{
}
void Checkers::readRound(pair<int, int> coordinate, pair<int, int> destination, Player *player)
{
    board[destination.first][destination.second] = board[coordinate.first][coordinate.second];
    board[coordinate.first][coordinate.second] = ' ';
    if (abs(destination.first - coordinate.first) == 2)
    {
        pair<int, int> middle;
        middle.first = (coordinate.first + destination.first) / 2;
        middle.second = (coordinate.second + destination.second) / 2;
        board[middle.first][middle.second] = ' ';
    }
}

bool Checkers::roundIsValid(pair<int, int>)
{
    return true;
}

bool Checkers::roundIsValid(pair<int, int> coordinate, pair<int, int> destination, int player)
{
    pair<int, int> middle;
    char piece = board[coordinate.first][coordinate.second];
    char destinationPiece = board[destination.first][destination.second];
    if ((player == 1 && piece == 'X') || (player == 2 && piece == 'O'))
        return false;
    if (coordinate.first < 0 || coordinate.first >= getSize().first || coordinate.second < 0 || coordinate.second >= getSize().second)
        return false;

    if (destination.second < 0 || destination.second >= getSize().second || destination.first < 0 || destination.first >= getSize().first)
        return false;

    if (destinationPiece != ' ')
        return false;

    if (board[destination.first][destination.second] == '-')
        return false;

    if (piece == 'X')
    {
        if (destination.first == coordinate.first - 1 && (destination.second - coordinate.second == -1 || destination.second - coordinate.second == 1))
            return true;

        if (destination.first == coordinate.first - 2)
        {
            middle.first = (coordinate.first + destination.first) / 2;
            middle.second = (coordinate.second + destination.second) / 2;

            if (board[middle.first][middle.second] == 'O')
                return true;
        }
    }

    if (piece == 'O')
    {
        if (destination.first == coordinate.first + 1 && (destination.second - coordinate.second == -1 || destination.second - coordinate.second == 1))
            return true;

        if (destination.first == coordinate.first + 2)
        {
            middle.first = (coordinate.first + destination.first) / 2;
            middle.second = (coordinate.second + destination.second) / 2;

            if (board[middle.first][middle.second] == 'X')
                return true;
        }
    }

    return false;
}
bool Checkers::didPlayerWin(Player* p)
{
    return false;
}
void Checkers::startGame(Player *player1, Player *player2)
{
    cout << player1->getNickname() << " versus " << player2->getNickname() << endl;
    setBoard();
    printBoard();
    int playerNumber = 1;
    pair<int, int> currentCoordinate;
    pair<int, int> movedCoordinate;
    // Turno de jogador <Apelido>:

    while (true)
    {
        if (playerNumber == 1)
        {
            cout << "Turno de jogador <" << player1->getNickname() << ">" << endl;
            cout << "Você é o O" << endl;
            cout << "Selecione uma peça para mexer" << endl;

            cin >> currentCoordinate.first >> currentCoordinate.second;

            cout << "Selecione a coordenada de destino da peça" << endl;

            cin >> movedCoordinate.first >> movedCoordinate.second;

            if (roundIsValid(currentCoordinate, movedCoordinate, playerNumber))
                readRound(currentCoordinate, movedCoordinate, player1);
            else
                cout << "Jogada invalida" << endl;
            
            playerNumber = 2;
        }
        else
        {
            cout << "Turno de jogador <" << player2->getNickname() << ">" << endl;
            cout << "Você é o X" << endl;
            cout << "Selecione uma peça para mexer" << endl;

            cin >> currentCoordinate.first >> currentCoordinate.second;

            cout << "Selecione a coordenada de destino da peça" << endl;

            cin >> movedCoordinate.first >> movedCoordinate.second;

            if (roundIsValid(currentCoordinate, movedCoordinate, playerNumber))
                readRound(currentCoordinate, movedCoordinate, player2);
            else
                cout << "Jogada invalida" << endl;

            playerNumber = 1;
        }
        printBoard();

        if (didPlayerWin(1)) {
            cout << player1->getNickname() << " ganhou!!!!!" << endl;
            player1->addWin(Player::CHECKERS);
            player2->addLoss(Player::CHECKERS);
            break;
        }

        else if (didPlayerWin(2)) {
            cout << player2->getNickname() << " ganhou!!!!!" << endl;
            player2->addWin(Player::CHECKERS);
            player1->addLoss(Player::CHECKERS);
            break;
        }
    }
}


Checkers::~Checkers()
{
}