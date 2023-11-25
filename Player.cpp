#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX() /2, mainGameMechsRef->getBoardSizeY() /2, '*');
    

    // more actions to be included
}

Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
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
    // PPA3 Finite State Machine logic
    switch(myDir)
    {
        case LEFT:
            playerPos.x--;
            
            break; 
        
        case RIGHT:
            playerPos.x++;
            
            break; 

        case UP:
            playerPos.y--;
            
            break; 

        case DOWN:
            playerPos.y++;
            
            break;

        default:
            break;
    }

    if (playerPos.x < 1)
        {
            playerPos.x = mainGameMechsRef->getBoardSizeX()-2;
        }
    else if (playerPos.x > mainGameMechsRef->getBoardSizeX()-2)
        {
            playerPos.x = 1;
        }
    else if (playerPos.y < 1)
        {
            playerPos.y = mainGameMechsRef->getBoardSizeY()-2;
        }
    else if (playerPos.y > mainGameMechsRef->getBoardSizeY()-2)
        {
            playerPos.y = 1;
        }


}