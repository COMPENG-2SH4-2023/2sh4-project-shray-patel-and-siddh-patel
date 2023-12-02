#ifndef FOOD_H
#define FOOD_H


#include <iostream>
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"

using namespace std;


class Food
{
    private:
        objPos foodPos; // Instance of the objPos class to make food object
        GameMechs* gmRef; //reference to game mechanics class 
    
    public:
        Food(GameMechs* gameRef); // Constructor 

        void generateFood(objPosArrayList* blockOff); //Generates a Food Item to be printed on the board 
        void getFoodPos(objPos &returnPos); // Gets the position of the Food Item


};

#endif
