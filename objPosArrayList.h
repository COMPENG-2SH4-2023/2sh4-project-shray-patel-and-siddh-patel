#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200

#include "objPos.h"

class objPosArrayList
{
    private:
        objPos* aList; //Array List to hold the snakes body
        int sizeList; // The number of elements currently in the snake
        int sizeArray; //The total size of the array list

    public:
        objPosArrayList(); //Constructor
        ~objPosArrayList(); //Destructor

        //Getter Methods
        int getSize(); 
        void getHeadElement(objPos &returnPos);
        void getTailElement(objPos &returnPos);
        void getElement(objPos &returnPos, int index);

        //Other Functional Methods
        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);
        void removeHead();
        void removeTail();
        
       
};

#endif