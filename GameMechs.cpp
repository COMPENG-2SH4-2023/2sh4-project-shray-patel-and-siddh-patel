#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    // Initialize standard game variables if board size is not specified.
    input = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = 30; 
    boardSizeY = 15;
    score = 0;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    // Initialize game variables based on the input x and y size of the board.
    input = 0;
    exitFlag = false;
    loseFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
    score = 0;
}

bool GameMechs::getExitFlagStatus() // Getter method to return exitflag status
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() // Getter method to return loseflag status
{
    return loseFlag;
}

char GameMechs::getInput() // Getter method to return input
{
    if(MacUILib_hasChar()) // Check if a key has been pressed
    {
        setInput(MacUILib_getChar()) ; // Call setinput to save the key pressed as input.
    }
    return input; // return Input value
}

int GameMechs::getBoardSizeX() // Getter method to get board size of x direction
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() // Getter method to get board size of y direction
{
    return boardSizeY;
}

int GameMechs::getScore() // Getter Method to get score of the game
{
    return score;
}

void GameMechs::setExitTrue() // Setter method to set exitflag to true
{
    exitFlag = true;
}

void GameMechs::setLoseTrue() // Setter method to set loseflag to true
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input) // game mechanics to set the input based on the parameter passed in
{
    input = this_input; // set input to the passed in parameter
    
    // check if the input is "Escape"
    // if it is then set exitflag to true.
    if(input == 27) // 27 = "Esc"
    {
        setExitTrue();
    }

}

void GameMechs::incrementScore() // Function to increment the score.
{
    score++;

}

void GameMechs::clearInput() // Function to clear the input.
{
    input = 0;
}


