#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    objPos temp;
    temp.setObjPos(mainGameMechsRef->getBoardSizeX() /2, mainGameMechsRef->getBoardSizeY() /2, '*');
    

    // more actions to be included
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(temp);
    playerPosList->insertHead(temp);
    playerPosList->insertHead(temp);
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

    
    playerPosList->insertHead(curHead);
    //The Current head will be updated to be the new head of the snake 
    // objPos ftemp;
    // foodObj->getFoodPos(ftemp);
    
    // for(int i = 1; i<playerPosList->getSize(); i++)
    // {
    //     objPos temp1;
    //     playerPosList->getElement(temp1,i);
    //     if(curHead.x == temp1.x && curHead.y == temp1.y)
    //     {
    //         mainGameMechsRef->setLoseTrue();
    //         mainGameMechsRef->setExitTrue();
    //     }
    // }
    playerPosList->removeTail();




    // if(curHead.x == ftemp.x && curHead.y == ftemp.y )
    // {
    //     playerPosList->insertHead(curHead);
    //     mainGameMechsRef->incrementScore();
    //     mainGameMechsRef->incrementScore();
    //     foodObj->generateFood(playerPosList);
    // }
    // else 
    // {
    //     playerPosList->insertHead(curHead);
    //     playerPosList->removeTail();
    // }

    //Collision with Food
    //If there is no Collision with the food then remove the tail
    
    
    
    
}

// bool Player::checkFoodConsumption()
// {
//     objPos temp;
//     objPos ftemp;
//     playerPosList->getHeadElement(temp);
//     foodObj->getFoodPos(ftemp);

//     if(temp.x == ftemp.x && temp.y == ftemp.y)
//     {
//         mainGameMechsRef->incrementScore();
//         foodObj->generateFood(playerPosList);
//         return true;
//     }
//     else
//     {
//         return false;
//     }

// }

// void Player::increasePlayerLength()
// {
//     objPos current;
//     playerPosList->insertHead(current);
// }

// bool Player::checkSelfCollision()
// {
//     objPos temp;
//     playerPosList->getHeadElement(temp);
//     for(int i=1; i<playerPosList->getSize();i++)
//     {
//         objPos temp1;
//         playerPosList->getElement(temp1,i);
//         if(temp.x == temp1.x && temp.y == temp1.y)
//         {
//             return false;
//         }
//     }

//     return true;
// }