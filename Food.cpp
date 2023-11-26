#include "Food.h"


// Constructor 
Food::Food() 
{
    foodPos.x = 0;
    foodPos.y = 0;
    foodPos.symbol = '0';
} 

//Destructor
Food::~Food()
{

} 

//Generates a Food Item to be printed on the board 
void Food::generateFood(objPosArrayList* blockOff)
{
    
    int rand_x,rand_y,reset;
    reset = 1;
    while(reset==1)
    {

        rand_x = rand() % (30 -2) + 1;
        rand_y = rand() % (15-2) + 1;
        for(int i=0; i<(*blockOff).getSize(); i++)
        {
            objPos temp;
            (*blockOff).getElement(temp,i);
            if(rand_x != temp.x && rand_y != temp.y)
            {
                reset=0;
            }

        }
       
        if(rand_x !=0 && rand_y !=0)
        {
            reset=0;
        }
        // for(int h=0; h < listSize; h++)
        // {
        //     if(rand_x != list[h].x && rand_y != list[h].y)
        //     {
        //         reset=0;
        //     }
        // }
    }
    foodPos.x = rand_x;
    foodPos.y = rand_y;
} 


//Getter to get the Food items position
void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
} 

