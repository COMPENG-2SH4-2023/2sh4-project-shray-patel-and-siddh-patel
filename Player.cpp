#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPos.x = 9;
    playerPos.y = 4;
    playerPos.symbol = '*';

    // more actions to be included
}

Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos = playerPos;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    if(mainGameMechsRef->getInput() != 0)  // if not null character
    {
        switch(mainGameMechsRef->getInput())
        {                      
            case 27:  // exit
                mainGameMechsRef->setExitTrue();
                break;
            
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
        mainGameMechsRef->clearInput();
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
            playerPos.x = 18;
        }
    else if (playerPos.x > 18)
        {
            playerPos.x = 1;
        }
    else if (playerPos.y < 1)
        {
            playerPos.y = 8;
        }
    else if (playerPos.y > 8)
        {
            playerPos.y = 1;
        }


}