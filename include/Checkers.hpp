#ifndef CHECKERS_H
#define CHECKERS_H

#include "BoardGame.hpp"

using namespace std;
class Checkers : public BoardGame
{
private:
    /* data */
public:
    bool didPlayerWin();
    Checkers(/* args */);
    ~Checkers();
};

#endif