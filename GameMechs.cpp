#include "GameMechs.h"

GameMechs::GameMechs()
{

}

GameMechs::GameMechs(int boardX, int boardY)
{

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
    return input;
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
    exitFlag = 1;
}

void GameMechs::setLoseTrue()
{
    loseFlag = 1;
}

void GameMechs::setInput(char this_input)
{
    if (MacUILib_hasChar() == 1)
        {
            input = MacUILib_getChar();
        }
}

void GameMechs::incrementScore()
{
    
}
void GameMechs::clearInput()
{
    input = 0;
}


