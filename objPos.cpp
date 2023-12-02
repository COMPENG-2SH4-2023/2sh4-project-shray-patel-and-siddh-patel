#include "objPos.h"

// Constructor to Initialize coordiantes and symbol to 0
// if no parameter has been given
objPos::objPos() 
{
    x = 0;
    y = 0;
    symbol = 0; //NULL
}

// Constructor to Initialize coordiantes and symbol
// to be same as the given parameter.
objPos::objPos(objPos &o)
{
    x = o.x;
    y = o.y;
    symbol = o.symbol;
}

// Constructor to Initialize object position and symbol
// to the given x, y and symbol as the parameter of the function.
objPos::objPos(int xPos, int yPos, char sym)
{
    x = xPos;
    y = yPos;
    symbol = sym;
}

// Setter method to set an objects position to be same as the given parameter
// which is also an object
void objPos::setObjPos(objPos o)
{
    x = o.x;
    y = o.y;
    symbol = o.symbol;
}

// Setter method to set an objects position based on given parameters
// which are x,y coordinat and symbol.
void objPos::setObjPos(int xPos, int yPos, char sym)
{
    x = xPos;
    y = yPos;
    symbol = sym;
}

// Getter method to get the x,y positon and symbol of an object.
void objPos::getObjPos(objPos &returnPos)
{
    returnPos.setObjPos(x, y, symbol);
}

// Getter method to get the symbol of the object
char objPos::getSymbol()
{
    return symbol;
}

// Function to check if the given object parameter has the same x and y coordinates
// returns true if they match and false if they don't match.
bool objPos::isPosEqual(const objPos* refPos)
{
    return (refPos->x == x && refPos->y == y);
}