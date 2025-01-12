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


    board[0][0] = 'Q';
    board[6][0] = 'K';
}

bool Checkers::didPlayerWin(int player)
{
    char opponentPiece;

    if (player == 1)
        opponentPiece = 'X';

    else
        opponentPiece = 'O';

    for (int l = 0; l < getSize().first; l++)
        for (int c = 0; c < getSize().second; c++)
            if (board[l][c] == opponentPiece)
                return false;

    return true;
}

bool Checkers::canCaptureQueen(pair<int, int> coordinate, pair<int, int> destination, int player)
{
    int cf = coordinate.first, cs = coordinate.second;
    int df = destination.first, ds = destination.second;

    char opponentLetter = player == 1 ? 'X' : 'O';
    char opponentQueen = player == 1 ? 'Q' : 'K';
    // diagonal principal
    // i, j
    // ir até i = 7 ou j = 7

    // diagonal principal descendo
    for (int i = cf, j = cs; cf < 7 && cs < 7; cf++, cs++)
    {
        if ((board[i][j] == opponentLetter || board[i][j] == opponentQueen) && board[i + 1][j + 1] == ' ')
            return true;
        else if((board[i][j] == opponentLetter || board[i][j] == opponentQueen) && (board[i + 1][j + 1] == opponentLetter || board[i + 1][j + 1] == opponentQueen))
            return false;
    }       

    // diagonal principal subindo
    for (int i = cf, j = cs; i > 0 && j > 0; i--, j--)
    {
        if ((board[i][j] == opponentLetter || board[i][j] == opponentQueen) && board[i - 1][j - 1] == ' ')
            return true;
    }

    // diagonal secundária subindo
    for (int i = cf, j = cs; i > 0 && j < 7; i--, j++)
    {
        if ((board[i][j] == opponentLetter || board[i][j] == opponentQueen) && board[i - 1][j + 1] == ' ')
            return true;
    }

    // diagonal secundária descendo
    for (int i = cf, j = cs; i < 7 && j > 0; i++, j--)
    {
        if ((board[i][j] == opponentLetter || board[i][j] == opponentQueen) && board[i + 1][j - 1] == ' ')
            return true;
    }

    return false;
}

void Checkers::readRound(pair<int, int> coordinate, Player *player)
{
}

void Checkers::readRound(pair<int, int> coordinate, pair<int, int> destination, Player *player)
{

    int cf = coordinate.first, cs = coordinate.second;
    int df = destination.first, ds = destination.second;
    char piece = board[coordinate.first][coordinate.second];
    char opponentPiece = piece == 'O' ? 'X' : 'O';
    char opponentQueen = piece == 'Q' ? 'K' : 'Q';

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
        cout << "<" << player->getNickname() << "> teve um peça promovida para DAMA-TRANSEXUAL" << endl;
    }
    else if (piece == 'K' || piece == 'Q')
    {
        if (cf < df && cs < ds)
        {
            cout << "diagonal principal descendo" << endl;
            // diagonal principal descendo
            for (int i = cf, j = cs; i < 7 && j < 7; i++, j++)
                if (board[i][j] == opponentPiece || board[i][j] == opponentQueen)
                    board[i][j] = ' ';
        }
        else if (cf > df && cs > ds)
        {
            cout << "diagonal principal descendo" << endl;
            // diagonal principal descendo
            for (int i = cf, j = cs; i > 0 && j > 0; i--, j--)
                if (board[i][j] == opponentPiece || board[i][j] == opponentQueen)
                    board[i][j] = ' ';
        }
        else if (ds > cs && df > cf)
        {
            cout << "diagonal secundária subindo" << endl;
            // diagonal secundária subindo
            for (int i = cf, j = cs; i > 0 && j < 7; i--, j++)
                if (board[i][j] == opponentPiece || board[i][j] == opponentQueen)
                    board[i][j] = ' ';
        }
        else if (cf < df && cs > ds)
        {
            cout << "diagonal secundária descendo" << endl;
            // diagonal secundária descendo
            for (int i = cf, j = cs; i < 7 && j > 0; i++, j--)
                if (board[i][j] == opponentPiece || board[i][j] == opponentQueen)
                    board[i][j] = ' ';
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
    char destinationPiece = board[destination.first][destination.second];

    if ((player == 1 && piece == 'Q') || (player == 2 && piece == 'K'))
        return Checkers::NOT_SUCCESS;

    if (abs(destination.first - coordinate.first) == abs(coordinate.second - destination.second))
        return Checkers::SUCCESS;

    return Checkers::NOT_SUCCESS;
}

int Checkers::roundIsValid(pair<int, int> coordinate, pair<int, int> destination, int player)
{
    if (coordinate.first < 0 || coordinate.first >= getSize().first || coordinate.second < 0 || coordinate.second >= getSize().second)
        return Checkers::NOT_SUCCESS;

    if (destination.second < 0 || destination.second >= getSize().second || destination.first < 0 || destination.first >= getSize().first)
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

        /* if (destination.first == coordinate.first - 2)
        {
            middle.first = (coordinate.first + destination.first) / 2;
            middle.second = (coordinate.second + destination.second) / 2;

            if (board[middle.first][middle.second] == 'O')
                return true;
        } */
    }

    if (piece == 'O')
    {
        if (destination.first == coordinate.first + 1 && (destination.second - coordinate.second == -1 || destination.second - coordinate.second == 1))
            return Checkers::SUCCESS;

        if (canCapture(coordinate, destination, 1))
            return Checkers::CAPTURE_AGAIN;

        // if (destination.first == coordinate.first + 2)
        // {
        //     middle.first = (coordinate.first + destination.first) / 2;
        //     middle.second = (coordinate.second + destination.second) / 2;

        //     if (board[middle.first][middle.second] == 'X')
        //         return true;
        // }
    }

    return false;
}

bool Checkers::didPlayerWin(Player *p)
{
    return false;
}

bool Checkers::canCapture(pair<int, int> coordinate, pair<int, int> destination, int player)
{
    // char piece = board[coordinate.first][coordinate.second];
    // char destinationPiece = board[destination.first][destination.second];
    char opponentPiece;
    // int direction = 0;

    if (player == 1)
        opponentPiece = 'X';

    else
        opponentPiece = 'O';

    pair<int, int> middle;

    if (abs(destination.first - coordinate.first) == 2)
    {
        middle.first = (coordinate.first + destination.first) / 2;
        middle.second = (coordinate.second + destination.second) / 2;

        if (board[middle.first][middle.second] == opponentPiece && board[destination.first][destination.second] == ' ')
            return true;
    }
    return false;
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

    vector<pair<int, int>> coordinates = {{-2, -2}, {2, 2}, {2, -2}, {-2, 2}};

    // Turno de jogador <Apelido>:
    Player *actualPlayer;

    while (true)
    {
        actualPlayer = playerNumber == 1 ? player1 : player2;

        cout << "Turno de jogador <" << actualPlayer->getNickname() << ">" << endl;

        if (playerNumber == 1)
            cout << "Você é o O" << endl;
        else
            cout << "Você é o X" << endl;

        cout << "Selecione uma peça para mexer" << endl;

        cin >> currentCoordinate.first >> currentCoordinate.second;

        cout << "Selecione a coordenada de destino da peça" << endl;

        cin >> movedCoordinate.first >> movedCoordinate.second;
        if(board[currentCoordinate.first][currentCoordinate.second] == 'K' ||board[currentCoordinate.first][currentCoordinate.second] == 'Q')
            result = roundIsValidQueen(currentCoordinate, movedCoordinate, playerNumber);
        else
            result = roundIsValid(currentCoordinate, movedCoordinate, playerNumber);
            
        switch (result)
        {
        case Checkers::SUCCESS:
            readRound(currentCoordinate, movedCoordinate, actualPlayer);
            break;

        case Checkers::NOT_SUCCESS:
            cout << "Jogada invalida" << endl;
            break;

        case Checkers::CAPTURE_AGAIN:
            readRound(currentCoordinate, movedCoordinate, actualPlayer);
            printBoard();
            currentCoordinate = movedCoordinate;

            for (auto coordinate : coordinates)
            {
                testCoordinate.first = movedCoordinate.first + coordinate.first;
                testCoordinate.second = movedCoordinate.second + coordinate.second;

                if (canCapture(movedCoordinate, testCoordinate, playerNumber))
                    result = roundIsValid(movedCoordinate, testCoordinate, playerNumber);

                if (result == Checkers::CAPTURE_AGAIN)
                {
                    cout << "Selecione a coordenada de destino da peça" << endl;
                    cin >> testCoordinate.first >> testCoordinate.second;
                    readRound(movedCoordinate, testCoordinate, actualPlayer);
                    break;
                }
            }

            break;
        }

        printBoard();

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