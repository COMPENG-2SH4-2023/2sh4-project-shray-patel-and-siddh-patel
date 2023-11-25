#include "objPosArrayList.h"


// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    sizeArray = ARRAY_MAX_CAP; // initializes the array size to the value of the pre-processor constant, 200 in this case 
    sizeList =0; // initializes the list size or the number of elements in the list(at the start its 0)
    aList = new objPos[sizeArray] ;  // allocating memory for the list of objPos objects with size of the variable sizeArray, which is previously defined
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList; //Deallocates the memory for the list of objPos objects
}

int objPosArrayList::getSize()
{
    return sizeList; //returns the amount of elements currently in the list 
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(sizeList != sizeArray) //checks if the number of elements is 
    {
        for(int i = sizeList; i>0; i--)
        {
            aList[i].setObjPos(aList[i-1]);
        }
        aList[0].setObjPos(thisPos);
        sizeList++;
    }
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if( sizeList >= 0 && sizeList < sizeArray)
    {
        aList[sizeList].setObjPos(thisPos);
        sizeList++;
    }
}

void objPosArrayList::removeHead()
{
    if(sizeList >= 0 && sizeList < sizeArray)
    {
        for(int i=0; i<sizeList+1; i++)
        {
            aList[i].setObjPos(aList[i+1]);
        }
        sizeList--;
    }
}

void objPosArrayList::removeTail()
{
    if(sizeList >0 && sizeList<sizeArray)
    {
        aList[sizeList -1].setObjPos(aList[sizeList]);
        sizeList--;
    }
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    if(sizeList >0 && sizeList<=sizeArray)
    {
        returnPos.setObjPos(aList[sizeList -1]);
    }
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    if(index < sizeArray)
    {
        returnPos.setObjPos(aList[index]);
    }
}