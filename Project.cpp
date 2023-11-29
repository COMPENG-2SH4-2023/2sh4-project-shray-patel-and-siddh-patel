#include <iostream>
#include <time.h>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "objPosArrayList.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* game;
Player* myplayer;
Food* fObj;
objPosArrayList* playerBody;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(game->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    game = new GameMechs(30,15);
    fObj = new Food();
    myplayer = new Player(game,fObj);
    playerBody = myplayer->getPlayerPos();

    srand(time(NULL));
    fObj->generateFood(playerBody);

}

void GetInput(void)
{
    game->getInput();
    
}

void RunLogic(void)
{
    myplayer->updatePlayerDir();
    myplayer->movePlayer();
    game->clearInput();

}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    bool drawn;
    
    playerBody = myplayer->getPlayerPos();
    objPos tempPlay;
    
    objPos fPos;
    fObj->getFoodPos(fPos);

    
    for(int i = 0; i<game->getBoardSizeY(); i++)
    {
        for(int j = 0; j<game->getBoardSizeX(); j++)
        {
            drawn = false;

            for(int k=0; k<playerBody->getSize(); k++)
            {
                playerBody->getElement(tempPlay,k);
                if(tempPlay.y == i && tempPlay.x == j)
                {
                    MacUILib_printf("%c", tempPlay.symbol);
                    drawn = true;
                    break;
                }
            }

            if(drawn) continue;
            //If the player body was drawn dont draw anything below

            //Draw Border
            if( i==0 || i==game->getBoardSizeY()-1 || j==0 || j==game->getBoardSizeX()-1)
            {
                MacUILib_printf("#");
            }
            else if(i == fPos.y && j == fPos.x)
            {
                MacUILib_printf("%c", fPos.symbol);
            }
            else 
            { 
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("Score %d\n",game->getScore());
    MacUILib_printf("Food Pos: <%d,%d>\n",fPos.x,fPos.y);

    if(game->getLoseFlagStatus() && game->getExitFlagStatus())
    {
        MacUILib_clearScreen(); 
        MacUILib_printf("You ate yourself! \nGame Score: %d\n", game->getScore());
    }
    else if(game->getExitFlagStatus())
    {
        MacUILib_clearScreen(); 
        MacUILib_printf("You Rage Quit! \nGame Score: %d\n", game->getScore());
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
       
  
    MacUILib_uninit();

    delete game;
    delete myplayer;
    delete fObj;
    //delete playerBody;
}
