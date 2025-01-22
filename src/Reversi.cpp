#include "../include/Reversi.hpp"

using namespace std;

Reversi::Reversi() : BoardGame(8, 8)
{
}

void Reversi::setBoard()
{
    for (int l = 0; l < getSize().first; l++)
    {
        for (int c = 0; c < getSize().second; c++)
            board[l][c] = ' ';
    }

    board[3][3] = 'X';
    board[4][4] = 'X';
    board[3][4] = 'O';
    board[4][3] = 'O';

    // for (int i = 0; i < 4; i++)
    //     for (int j = 0; j < 4; j++)
    //         board[i][j] = 'X';
    
    // for (int i = 4; i < 8; i++)
    //     for (int j = 4; j < 8; j++)
    //         board[i][j] = 'O';

    // board[3][2] = 'O';
    // board[4][3] = 'O';
    // board[3][3] = 'X';
}

bool Reversi::roundIsValid(pair<int, int> destination, int player)
{
    if (!isInsideBoard(destination) || board[destination.first][destination.second] != ' ')
    {
        return false;
    }
    // cout << .empty() << endl;

    return !allPiecesToFlip(destination, player).empty();
}

bool Reversi::roundIsValid(pair<int, int>)
{
    return false;
}

void Reversi::readRound(pair<int, int> destination, int player)
{
    char piece = player == 1 ? 'O' : 'X';

    vector<pair<int, int>> piecesToFlip = allPiecesToFlip(destination, player);

    board[destination.first][destination.second] = piece;

    for (auto p : piecesToFlip)
        board[p.first][p.second] = piece;
}

vector<pair<int, int>> Reversi::allPiecesToFlip(pair<int, int> destination, int player)
{
    char piece = player == 1 ? 'O' : 'X';
    char opponentPiece = player == 1 ? 'X' : 'O';

    vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    vector<pair<int, int>> piecesToFlip;

    for (auto direction : directions)
    {
        pair<int, int> current = destination;

        current.first += direction.first;
        current.second += direction.second;

        while (isInsideBoard(current) && board[current.first][current.second] == opponentPiece)
        {
            current.first += direction.first;
            current.second += direction.second;
        }

        if (isInsideBoard(current) && board[current.first][current.second] == piece)
        {
            while (current != destination)
            {
                current.first -= direction.first;
                current.second -= direction.second;
                if (current != destination)
                    piecesToFlip.push_back(current);
            }
        }
    }

    return piecesToFlip;
}

bool Reversi::validMove(int player)
{
    // char opponentPiece = player == 1 ? 'X' : 'O';

    for (int l = 0; l < getSize().first; l++)
    {
        for (int c = 0; c < getSize().second; c++)
        {
            if (board[l][c] == ' ')
            {
                pair<int, int> current = {l, c};

                if (!allPiecesToFlip(current, player).empty())
                {
                    // cout << "asjdjdldasj" << endl;
                    vector<pair<int, int>> a = allPiecesToFlip(current, player);
                    // for (int i = 0; i < a.size(); i++)
                    // {
                    //     cout << a[i].first << " " << a[i].second << endl;
                    // }
                    return true;
                }
            }
        }
    }

    return false;
}

bool Reversi::didPlayerWin(int player)
{
    char piece = player == 1 ? 'O' : 'X';
    int otherPlayer = player == 1 ? 2 : 1;
    char opponentPiece = player == 1 ? 'X' : 'O';
    int countOpponent = 0, count = 0;

    for (int l = 0; l < getSize().first; l++)
    {
        for (int c = 0; c < getSize().second; c++)
        {
            if (board[l][c] == opponentPiece)
                countOpponent++;

            else if (board[l][c] == piece)
                count++;
        }
    }
    //cout << "count: " << count << " count opponent: " << countOpponent;

    if (count == 0 || countOpponent == 0)
        return count > countOpponent;
    
    else if (countOpponent + count == getSize().first * getSize().second)
        return count > countOpponent;
    
    // movimentos validos if
    else if (!validMove(player) && !validMove(otherPlayer))
        return count > countOpponent;
    
    return false;
}

void Reversi::startGame(Player *player1, Player *player2)
{
    cout << player1->getNickname() << " versus " << player2->getNickname() << endl;

    setBoard();
    printBoard();

    int playerNumber = 1;
    // int result;

    Player *actualPlayer;

    while (true)
    {
        actualPlayer = playerNumber == 1 ? player1 : player2;

        cout << "Turno de jogador <" << actualPlayer->getNickname() << ">" << endl;

        if (playerNumber == 1)
            cout << "Você é o O" << endl;
        else
            cout << "Você é o X" << endl;

        pair<int, int> moved;

        cout << "Escolha uma coordenada para colocar a peça" << endl;
        cin >> moved.first >> moved.second;
        if (roundIsValid(moved, playerNumber))
        {
            readRound(moved, playerNumber);
            printBoard();
        }

        else
            cout << "Jogada inválida" << endl;

        if (didPlayerWin(1))
        {
            cout << player1->getNickname() << " ganhou!!!!!" << endl;
            player1->addWin(Player::REVERSI);
            player2->addLoss(Player::REVERSI);
            break;
        }

        else if (didPlayerWin(2))
        {
            cout << player2->getNickname() << " ganhou!!!!!" << endl;
            player2->addWin(Player::REVERSI);
            player1->addLoss(Player::REVERSI);
            break;
        }

        playerNumber = playerNumber == 1 ? 2 : 1;

        actualPlayer = playerNumber == 1 ? player1 : player2;
    }
}
void Reversi::readRound(pair<int, int> coord, Player *player)
{
}

Reversi::~Reversi()
{
}

bool Reversi::didPlayerWin(Player *p)
{
    return false;
}
