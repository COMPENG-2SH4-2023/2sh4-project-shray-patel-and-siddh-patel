#include "Player.h"


Player::Player(GameMechs* thisGMRef, Food* foodRef)
{
    mainGameMechsRef = thisGMRef;
    foodObj = foodRef;
    myDir = STOP;
    objPos temp;
    temp.setObjPos(mainGameMechsRef->getBoardSizeX() /2, mainGameMechsRef->getBoardSizeY() /2, '*');
    

    // more actions to be included
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(temp);
    
}

Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

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
    playerPosList->getHeadElement(curHead);
    // PPA3 Finite State Machine logic
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

    //The Current head will be updated to be the new head of the snake 
    
    
    //Removes the Tail so that the movement is complete
    //playerPosList->removeTail();

    

    //Collision with Food
    //If there is no Collision with the food then remove the tail
    

    if (!checkSelfCollision())
    {
        if (checkFoodConsumption())
        {
            playerPosList->insertHead(curHead);
        }
        else
        {
            playerPosList->insertHead(curHead);
            playerPosList->removeTail();
        }
    }
    else
    {
        mainGameMechsRef->setLoseTrue();
        mainGameMechsRef->setExitTrue();
    }
    
}

bool Player::checkFoodConsumption()
{
    objPos head;
    objPos ftemp;
    playerPosList->getHeadElement(head);
    foodObj->getFoodPos(ftemp);

    if (head.isPosEqual(&ftemp))
    {
        mainGameMechsRef->incrementScore();
        foodObj->generateFood(playerPosList);
        return true;
    }
    
    return false;

}

void Player::increasePlayerLength()
{
    objPos current;
    playerPosList->insertHead(current);
}

bool Player::checkSelfCollision()
{
    objPos head;
    objPos tempCmp;
    bool flag = false;
    
    playerPosList->getHeadElement(head);

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