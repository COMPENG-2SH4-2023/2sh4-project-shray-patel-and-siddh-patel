#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state enum

        Player(GameMechs* thisGMRef,Food* foodRef); //Constructor with references to gameMechs and food class as parameters
        ~Player(); //Destructor 

        objPosArrayList* getPlayerPos(); // Upgrade this in iteration 3.
        void updatePlayerDir(); // This method updates the players position 
        void movePlayer(); // This method is called to increment the position of the player in order to move it 
        bool checkFoodConsumption(); // This method will be called to check if the player ate the food 
        bool checkSelfCollision(); // This method checks whether the player as tried to eat itself ( overlapped itself)

    private:
        objPosArrayList *playerPosList;   // This is the reference to the objPosArrayList class, basically the    
        enum Dir myDir; //enum that holds the states for the direction of the player

        GameMechs* mainGameMechsRef; //Reference to game mechanics class
        Food* foodObj; //Reference to Food Class 
};

#endif