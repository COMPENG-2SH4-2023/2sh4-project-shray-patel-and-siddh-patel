#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = 30;
    boardSizeY = 15;
    score = 0;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
    score = 0;
}

// do you need a destructor?



bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlatStatus()
{
    return loseFlag;
}

char GameMechs::getInput()
{
    if (MacUILib_hasChar() == 1)
    {
        input = MacUILib_getChar();
        if (input == 27)
        {
            setExitTrue();
        }
        return input;
    }
    return input = 0;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseTrue()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}


void GameMechs::incrementScore()
{
    score++;

}

void GameMechs::clearInput()
{
    input = 0;
}


