#ifndef FOOD_H
#define FOOD_H


#include <iostream>
#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class Food
{
    private:
        objPos foodPos; 
    
    public:
        Food(); // Constructor 
        ~Food(); //Destructor

        void generateFood(objPosArrayList* blockOff); //Generates a Food Item to be printed on the board 
        void getFoodPos(objPos &returnPos); // Gets the position of the Food Item


};

#endif
