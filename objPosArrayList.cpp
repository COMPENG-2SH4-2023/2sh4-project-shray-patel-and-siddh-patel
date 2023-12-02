#include "objPosArrayList.h"


//Constructor
objPosArrayList::objPosArrayList()
{
    sizeArray = ARRAY_MAX_CAP; // initializes the array size to the value of the pre-processor constant, 200 in this case 
    sizeList =0; // initializes the list size or the number of elements in the list(at the start its 0)
    aList = new objPos[sizeArray] ;  // allocating memory for the list of objPos objects with size of the variable sizeArray, which is previously defined
}

//Destructor
objPosArrayList::~objPosArrayList()
{
    delete[] aList; //Deallocates the memory for the list of objPos objects
}

//Getter Method
int objPosArrayList::getSize()
{
    return sizeList; //returns the amount of elements currently in the list 
}


//This method inserts a head in the list 
void objPosArrayList::insertHead(objPos thisPos)
{

    //This if condition checks if the array List is full.
    if(sizeList != sizeArray) 
    {
        //If the array List is not then this for loop shifts all the elements 1 space back in the list creating space for the new head
        for(int i = sizeList; i>0; i--)
        {
            aList[i].setObjPos(aList[i-1]);
        }

        //We assign the new head obj to the start of the array list so we have successfully inserted a head.
        aList[0].setObjPos(thisPos);
        sizeList++; //Updates number of elements in the array list
    }
}


//This method inserts a tail after the last element in the list
void objPosArrayList::insertTail(objPos thisPos)
{
    //This If condition checks whether the array list if full or not 
    if( sizeList >= 0 && sizeList < sizeArray)
    {
        //The sizeList member, is the index for the first empty space after the last element
        //Therefore we add an "tail" / new object at that index, thus inserting a tail
        aList[sizeList].setObjPos(thisPos);

        sizeList++;//Updates the number of elements in the list
    }

}


//This method removes the head of the player snake and shifts all the elements to fill the space
void objPosArrayList::removeHead()
{

    //Condition to check if array list is full
    if(sizeList >= 0 && sizeList < sizeArray)
    {

        //For Loop to shift all the objects back in index to fill the space of the removed head
        for(int i=0; i<sizeList+1; i++)
        {
            aList[i].setObjPos(aList[i+1]);
        }

        sizeList--; //Updates the number of elements in the list
    }
    
}


//This method removes the tail of the player snake
void objPosArrayList::removeTail()
{
    //Condition to check if array list is full
    if(sizeList > 0 && sizeList < sizeArray)
    {
        //This is as simple as removing the last object by setting it to the empty space  in the index above it. (no need to shift anything)
        aList[sizeList - 1].setObjPos(aList[sizeList]);
        sizeList--; //Updates number of elements in the list
    }
}

//Getter Method to get the head object at index 0
void objPosArrayList::getHeadElement(objPos &returnPos)
{
    //Simply using the setObjPos function to get the object at index 0 
    //assigns the head object to the address passed through this method
    returnPos.setObjPos(aList[0]);
}

//Getter Method to get the tail element of the snake player
void objPosArrayList::getTailElement(objPos &returnPos)
{
    //Condition to make sure acessing sizeList will not cause seg fault
    //Just a precaution
    if(sizeList >0 && sizeList<=sizeArray)
    {
        //Simply using the setObjPos function to get the last object 
        //assigns the tail object to the address passed through this method
        returnPos.setObjPos(aList[sizeList -1]);
    }
}

//Getter Method to get the snake body element at a specified index
void objPosArrayList::getElement(objPos &returnPos, int index)
{
    //Condition to ensure that index is within the bounds of the array list 
    // This is to avoid seg fault
    if(index >=0 && index<sizeArray)
    {
        //Simply using the setObjPos function to get the object at the index passed through the method 
        //assigns the object at that index to the object address passed through this method
        returnPos.setObjPos(aList[index]);
    }
} 