#include "Food.h"



// Food Constructor (Has argument of reference to game mechanics class) 
Food::Food(GameMechs* gameRef) 
{
    gmRef = gameRef;// sets the private member gmRef to the game mechanics class reference
    
    //Initializes the food objects initial position and symbol
    foodPos.x =0;
    foodPos.y =0;
    foodPos.symbol = 'O';
} 

//Generates a Random Food Item to be printed on the board 
//(accepts a object array list to compare the positions)
void Food::generateFood(objPosArrayList* blockOff)
{
    
    int rand_x,rand_y,reset; //Int Variables for Random x and y positions and the reset condition for while loop 
    reset = 1; // set reset to 1 so that the loop keeps generating random (x,y) positions until it is a viable position
    
    //This while loop keeps generating random (x,y) positions until it does not interfere with the snake or the border positions
    while(reset==1)
    {

        rand_x = rand() % (gmRef->getBoardSizeX() -2) + 1; //Generates a Random Int Value between 1 and 28 or 1 index less than the X board size value
        rand_y = rand() % (gmRef->getBoardSizeY()-2) + 1; //Generates a Random Int Value between 1 and 13 or 1 index less than the X board size value
        
        //This for loop checks if the random position generated conincides with any of the position of the snake elements 
        for(int i=0; i<(*blockOff).getSize(); i++)
        {
            //This section of code gets the element at the index i (from the for loop) 
            //It then assigns the contents of the object at that index using the .getElement func
            objPos temp;
            (*blockOff).getElement(temp,i);

            //This condition checks whether the random (x,y) 
            if(rand_x != temp.x && rand_y != temp.y)
            {
                reset=0; // exits Loop
            }

        }
       
       //Checks if the position is not printed on the first element of the border(which is included in the random generation of coordinates)
        if(rand_x !=0 && rand_y !=0)
        {
            reset=0;//exits Loop
        }
        
    }

    //Random (x,y) assigned here to the food Obj
    foodPos.x = rand_x;
    foodPos.y = rand_y;
} 


//Getter to get the Food items position
void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos);
} 

