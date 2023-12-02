#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        char input; // Stores User Input
        bool exitFlag; // Exit flag is used to end the game 
        bool loseFlag; // Lose flag is used to indicate whether the user lost or quit
        
        int boardSizeX; // Stores the X size of the board 
        int boardSizeY; // Stores the Y size of the board 
        int score; // Stores the score 

    public:
        GameMechs(); // Constructor
        GameMechs(int boardX, int boardY); // Specialized Constructor
        
        //Getter Methods
        bool getExitFlagStatus(); // Gets the status of the Exit Flag
        bool getLoseFlagStatus(); // Gets the status of the Lose Flag
        int getBoardSizeX(); // Gets the X size of the board 
        int getBoardSizeY(); // Gets the Y size of the board
        int getScore(); // Gets the current score

        //Setter Methods
        void setExitTrue(); // This method sets the value of the Exit Flag to true
        void setLoseTrue(); // This method sets the value of the Lose Flag to true


        //Other Methods
        char getInput(); // This method will take input from the user 
        void setInput(char this_input); // This method will set the private input memeber to the char that is passed in as the parameter
        void clearInput(); // This method clears the IO buffer 
        void incrementScore(); // This method increments the score

      

};

#endif