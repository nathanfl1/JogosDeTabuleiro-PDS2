#include "../include/Checkers.hpp"

// #define df destination.first
// #define ds destina
// #define cf coordinate.first
// #define cs coordinate.sec

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
    char opponentPiece, piece;
    char opponentQueen, queen;
    int cont = 0;
    if (player == 1)
    {
        queen = 'K';
        opponentQueen = 'Q';
        opponentPiece = 'X';
        piece = 'O';
    }

    else
    {  
        queen = 'Q';
        opponentQueen = 'K';
        opponentPiece = 'O';
        piece = 'X';
    }

    for (int l = 0; l < getSize().first; l++)
    {
        for (int c = 0; c < getSize().second; c++)
        {
            if (board[l][c] == opponentPiece || board[l][c] == opponentQueen)
                return false;
            else if(board[l][c] == piece || board[l][c] == queen)
                cont++;
        }
    }

    return cont > 0;
}

bool Checkers::canCaptureQueen(pair<int, int> coordinate, pair<int, int> destination, int player)
{
    int directions[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    for (int i = 0; i < 4; i++)
    {
        int direction1 = directions[i][0];
        int direction2 = directions[i][1];
        int j = 1;
        while (board[coordinate.first + j * direction1][coordinate.second + j * direction2] == ' ')
        {
            if (coordinate.first + j * direction1 == destination.first && coordinate.second + j * direction2 == destination.second)
                return true;
            j++;
        }
    }
    return false;
}

void Checkers::readRound(pair<int, int> coordinate, Player *player)
{
}

void Checkers::readRound(pair<int, int> coordinate, pair<int, int> destination, Player *player)
{

    //int cf = coordinate.first, cs = coordinate.second;
    // int df = destination.first, ds = destination.second;
    char piece = board[coordinate.first][coordinate.second];
    char opponentPiece, opponentQueen, queen;
    if (piece == 'O' || piece == 'K')
    {
        opponentPiece = 'X';
        opponentQueen = 'Q';
        queen = 'K';
    }
    else
    {
        opponentPiece = 'O';
        opponentQueen = 'K';
        queen = 'Q';
    }

    board[destination.first][destination.second] = piece;
    board[coordinate.first][coordinate.second] = ' ';

    if (abs(destination.first - coordinate.first) == 2)
    {
        pair<int, int> middle;
        middle.first = (coordinate.first + destination.first) / 2;
        middle.second = (coordinate.second + destination.second) / 2;
        board[middle.first][middle.second] = ' ';
    }

    if (piece == 'X' && destination.first == 0)
    {
        board[destination.first][destination.second] = 'Q';
        cout << "<" << player->getNickname() << "> teve um peça promovida para DAMA" << endl;
    }
    else if (piece == 'O' && destination.first == 7)
    {
        board[destination.first][destination.second] = 'K';
        cout << "<" << player->getNickname() << "> teve um peça promovida para DAMA" << endl;
    }
    else if (piece == 'K' || piece == 'Q')
    {
        if (abs(destination.first - coordinate.first) == abs(coordinate.second - destination.second))
        {
            int direction = destination.first - coordinate.first > 0 ? 1 : -1;
            int direction2 = destination.second - coordinate.second > 0 ? 1 : -1;

            pair<int, int> current = coordinate;
            while (isInsideBoard(current) && current != destination)
            {
                current.first += direction;
                current.second += direction2;
                if (board[current.first][current.second] == opponentPiece || board[current.first][current.second] == opponentQueen)
                    board[current.first][current.second] = ' ';
                if (current == destination)
                    board[destination.first][destination.second] = queen;
            }
        }
    }
}

bool Checkers::roundIsValid(pair<int, int>)
{
    return true;
}

int Checkers::roundIsValidQueen(pair<int, int> coordinate, pair<int, int> destination, int player)
{
    char piece = board[coordinate.first][coordinate.second];
    char friendPiece, friendQueen;
    // char destinationPiece = board[destination.first][destination.second];
    int countOpponentsInARow = 0;

    if ((player == 1 && piece == 'Q') || (player == 2 && piece == 'K'))
        return Checkers::NOT_SUCCESS;

    if (abs(destination.first - coordinate.first) != abs(coordinate.second - destination.second))
        return Checkers::NOT_SUCCESS;

    int direction = destination.first - coordinate.first > 0 ? 1 : -1;
    int direction2 = destination.second - coordinate.second > 0 ? 1 : -1;

    char opponentPiece, opponentQueen;
    if (player == 1)
    {
        opponentPiece = 'X';
        opponentQueen = 'Q';
        friendPiece = 'O';
        friendQueen = 'K';
    }
    else
    {
        opponentPiece = 'O';
        opponentQueen = 'K';
        friendPiece = 'X';
        friendQueen = 'Q';
    }

    pair<int, int> current = coordinate;
    while (isInsideBoard(current) && current != destination)
    {
        current.first += direction;
        current.second += direction2;
        if (board[current.first][current.second] == friendPiece || board[current.first][current.second] == friendQueen)
            return Checkers::NOT_SUCCESS;

        if (board[current.first][current.second] == opponentPiece || board[current.first][current.second] == opponentQueen)
            countOpponentsInARow++;
        
        else
            countOpponentsInARow = 0;

        if (countOpponentsInARow > 1)
            return Checkers::NOT_SUCCESS;
        
        if(current == destination)
        {
            return Checkers::SUCCESS;
        }
    }

    return Checkers::NOT_SUCCESS;
}

int Checkers::roundIsValid(pair<int, int> coordinate, pair<int, int> destination, int player)
{
    if (!isInsideBoard(coordinate) || !isInsideBoard(destination))
        return Checkers::NOT_SUCCESS;

    pair<int, int> middle;
    char piece = board[coordinate.first][coordinate.second];
    char destinationPiece = board[destination.first][destination.second];

    if (destinationPiece != ' ')
        return Checkers::NOT_SUCCESS;

    if (piece == 'K' || piece == 'Q')
        return roundIsValidQueen(coordinate, destination, player);

    if ((player == 1 && piece == 'X') || (player == 2 && piece == 'O'))
        return Checkers::NOT_SUCCESS;

    if (board[destination.first][destination.second] == '-')
        return Checkers::NOT_SUCCESS;

    if (piece == 'X')
    {
        if (destination.first == coordinate.first - 1 && (destination.second - coordinate.second == -1 || destination.second - coordinate.second == 1))
            return Checkers::SUCCESS;

        if (canCapture(coordinate, destination, 2))
            return Checkers::CAPTURE_AGAIN;
    }

    if (piece == 'O')
    {
        if (destination.first == coordinate.first + 1 && (destination.second - coordinate.second == -1 || destination.second - coordinate.second == 1))
            return Checkers::SUCCESS;

        if (canCapture(coordinate, destination, 1))
            return Checkers::CAPTURE_AGAIN;
    }

    return false;
}

bool Checkers::didPlayerWin(Player *p)
{
    return false;
}

bool Checkers::canCapture(pair<int, int> coordinate, pair<int, int> destination, int player)
{
    if (!isInsideBoard(coordinate) || !isInsideBoard(destination))
        return false;
    char opponentPiece, opponentQueen;
    // int direction = 0;

    if (player == 1)
    {
        opponentPiece = 'X';
        opponentQueen = 'Q';
    }

    else
    {
        opponentPiece = 'O';
        opponentQueen = 'K';
    }

    pair<int, int> middle;

    if (abs(destination.first - coordinate.first) == 2)
    {
        middle.first = (coordinate.first + destination.first) / 2;
        middle.second = (coordinate.second + destination.second) / 2;

        if (board[middle.first][middle.second] == opponentPiece || board[middle.first][middle.second] == opponentQueen)
            if (board[destination.first][destination.second] == ' ')
                return true;
    }
    return false;
}

void Checkers::captureAllAvaliablePieces(pair<int, int> currentCoordinate, int playerNumber, Player *player)
{
    vector<pair<int, int>> coordinates = {{-2, -2}, {2, 2}, {2, -2}, {-2, 2}};
    int result;
    pair<int, int> testCoordinate;
    for (auto coordinate : coordinates)
    {
        testCoordinate.first = currentCoordinate.first + coordinate.first;
        testCoordinate.second = currentCoordinate.second + coordinate.second;

        if (canCapture(currentCoordinate, testCoordinate, playerNumber))
            result = roundIsValid(currentCoordinate, testCoordinate, playerNumber);

        if (result == Checkers::CAPTURE_AGAIN)
        {
            cout << "digite as coordenadas de destino da peça" << endl;
            cin >> testCoordinate.first >> testCoordinate.second;
            if (roundIsValid(testCoordinate) != Checkers::NOT_SUCCESS)
            {
                readRound(currentCoordinate, testCoordinate, player);
                printBoard();
                captureAllAvaliablePieces(testCoordinate, playerNumber, player);
            }
            else
                cout << "Jogada inválida" << endl;
            break;
        }
    }
}

void Checkers::startGame(Player *player1, Player *player2)
{
    cout << player1->getNickname() << " versus " << player2->getNickname() << endl;
    setBoard();
    printBoard();
    int playerNumber = 1;
    int result;
    pair<int, int> currentCoordinate;
    pair<int, int> movedCoordinate;
    pair<int, int> testCoordinate;

    // Turno de jogador <Apelido>:
    Player *actualPlayer;

    while (true)
    {
        actualPlayer = playerNumber == 1 ? player1 : player2;

        cout << "Turno <" << getTurn() + 1 << ">"<< endl;

        cout << "Turno de jogador <" << actualPlayer->getNickname() << ">" << endl;

        if (playerNumber == 1)
            cout << "Você é o O (ou dama K)" << endl;
        else
            cout << "Você é o X (ou dama Q)" << endl;

        cout << "Selecione uma peça para mexer" << endl;

        cin >> currentCoordinate.first >> currentCoordinate.second;

        cout << "Selecione a coordenada de destino da peça" << endl;

        cin >> movedCoordinate.first >> movedCoordinate.second;

        if (board[currentCoordinate.first][currentCoordinate.second] == 'K' || board[currentCoordinate.first][currentCoordinate.second] == 'Q')
            result = roundIsValidQueen(currentCoordinate, movedCoordinate, playerNumber);
        else
            result = roundIsValid(currentCoordinate, movedCoordinate, playerNumber);

        switch (result)
        {
        case Checkers::SUCCESS:
            readRound(currentCoordinate, movedCoordinate, actualPlayer);
            printBoard();
            incrementTurn();
            break;

        case Checkers::NOT_SUCCESS:
            cout << "Jogada invalida" << endl;
            printBoard();
            break;

        case Checkers::CAPTURE_AGAIN:
            readRound(currentCoordinate, movedCoordinate, actualPlayer);
            printBoard();
            captureAllAvaliablePieces(movedCoordinate, playerNumber, actualPlayer);
            incrementTurn();
            break;
        }

        if (didPlayerWin(1))
        {
            cout << player1->getNickname() << " ganhou!!!!!" << endl;
            player1->addWin(Player::CHECKERS);
            player2->addLoss(Player::CHECKERS);
            break;
        }

        else if (didPlayerWin(2))
        {
            cout << player2->getNickname() << " ganhou!!!!!" << endl;
            player2->addWin(Player::CHECKERS);
            player1->addLoss(Player::CHECKERS);
            break;
        }

        playerNumber = playerNumber == 1 ? 2 : 1;
    }
}

Checkers::~Checkers()
{
}