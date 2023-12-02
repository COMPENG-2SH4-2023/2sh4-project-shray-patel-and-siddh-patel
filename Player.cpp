#include "Player.h"

// Constructor
Player::Player(GameMechs* thisGMRef, Food* foodRef)
{
    mainGameMechsRef = thisGMRef;
    foodObj = foodRef;
    myDir = STOP;
    objPos temp;
    temp.setObjPos(mainGameMechsRef->getBoardSizeX() /2, mainGameMechsRef->getBoardSizeY() /2, '*');
    
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(temp);
    
}

//Destructor
Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

// This method gets the player position by returning a pointer to the playerPosList 
objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}


// This Method updates the direction of the player using a  FSM (finite state machine)
void Player::updatePlayerDir()
{
    // PPA3 input processing logic

    switch(mainGameMechsRef->getInput())
    {                      
        case 'a':  // LEFT (a)
            if (myDir != RIGHT)
            {
                myDir = LEFT;
            }
            break;

        case 'd':  // RIGHT (d)
            if (myDir != LEFT)
            {
                myDir = RIGHT;
            }
            break;

        case 'w':  // UP (w)
            if (myDir != DOWN)
            {
                myDir = UP;
            }
            break;

        case 's':  // DOWN (s)
            if (myDir != UP)
            {
                myDir = DOWN;
            }    
            break;

        default:
            break;
    }
}

void Player::movePlayer()
{
    //Snake Head Implementation
    objPos curHead; //This object holds the information about the current snake head
    playerPosList->getHeadElement(curHead); // This method call gets the head object of the player and assigned it to curHead
    
    
    // PPA3 Finite State Machine logic
    //Updates the X or Y component of the object based on the state
    switch(myDir)
    {
        case LEFT:
            curHead.x--;
            
            break; 
        
        case RIGHT:
            curHead.x++;
            
            break; 

        case UP:
            curHead.y--;
            
            break; 

        case DOWN:
            curHead.y++;
            
            break;

        default:
            break;
    }


    // If statments to check boundry wrap around 
    // Basically, it checks if the player is at the ends of the x board size or the Y size and it updates the coordinates accordingly
    if (curHead.x < 1)
        {
            curHead.x = mainGameMechsRef->getBoardSizeX()-2;
        }
    else if (curHead.x > mainGameMechsRef->getBoardSizeX()-2)
        {
            curHead.x = 1;
        }
    else if (curHead.y < 1)
        {
            curHead.y = mainGameMechsRef->getBoardSizeY()-2;
        }
    else if (curHead.y > mainGameMechsRef->getBoardSizeY()-2)
        {
            curHead.y = 1;
        }

    
    
    
    //Removes the Tail so that the movement is complete
    //playerPosList->removeTail();

    

    
    // If statments to update the player body list implementation so that the player body moves like a snake

    // First it checks if the the self Collision has happened by using the checkSelfCollison Method and if its false it continues
    if (!checkSelfCollision()) 
    {
        //Checks Collision with Food
        if (checkFoodConsumption())
        {
            //If there is Collision with the food then dont remove the tail just add the head
            playerPosList->insertHead(curHead);
        }
        else
        {
            // If there is no collision with food, just complete one movement by adding a head and removing tail
            playerPosList->insertHead(curHead);
            playerPosList->removeTail();
        }
    }

    //If the player body did self collide then it will go into the else
    else
    {
        // If self collision happened, then it sets the exit and lose flags to true
        mainGameMechsRef->setLoseTrue();
        mainGameMechsRef->setExitTrue();
    }
    
}


//This method checks if the player has eaten the food 
bool Player::checkFoodConsumption()
{

    objPos head;
    objPos ftemp;
    playerPosList->getHeadElement(head); // Gets the head element of the snake and assigns it to the temporary head object
    foodObj->getFoodPos(ftemp); // Gets the position of the food by a food object that is stored in the temporary ftemp object

    if (head.isPosEqual(&ftemp)) // This checks if the head of the snake is at the same position as the food ( if it is then continue)
    {
        //If the food is consumed then the score is incremented and new food is generated and returns true
        mainGameMechsRef->incrementScore();
        foodObj->generateFood(playerPosList);
        return true;
    }

    // If food is not consumed it returns false
    
    return false;

}

//This method checks if the player snake collided with it self
bool Player::checkSelfCollision()
{
    objPos head;
    objPos tempCmp;
    bool flag = false; // Temp flag to exit out of the for loop below
    
    playerPosList->getHeadElement(head);// Gets the head element of the snake and assigns it to the temporary head object


    // This for loop checks if any of the elements in the snake body are at the same position as the head, 
    //then it will break out of the loop and return true, other wise it returns false

    for(int i=1; i<playerPosList->getSize();i++)
    {
        playerPosList->getElement(tempCmp,i);
        flag = tempCmp.isPosEqual(&head);
        
        if(flag)
        {
            break;
        }
    }
    return flag;
}