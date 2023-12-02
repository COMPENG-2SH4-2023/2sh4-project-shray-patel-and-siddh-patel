#ifndef OBJPOS_H
#define OBJPOS_H

class objPos
{
    public:
        int x; // X position of Object
        int y; // Y Position of Object
        char symbol; // Symbol of the object

        objPos(); // Constructor
        objPos(objPos &o); // copy constructor
        objPos(int xPos, int yPos, char sym); // Specialized constructor

        //Setter Methods
        void setObjPos(objPos o);    // Sets the x and y position and the symbol of the object based on the (object passed through)     
        void setObjPos(int xPos, int yPos, char sym);  // Sets the x, y and the symbol of the object based on the 3 parameters passed through

        //Getter Methods
        void getObjPos(objPos &returnPos); // Gets the objects (x,y) position and the symbol based on the object passed through by reference
        char getSymbol(); // Gets the symbol of the object

        //Other Methods
        bool isPosEqual(const objPos* refPos); // This method checks if 2 objects have the same (x,y) coordinates and returns either true or false 
};

#endif