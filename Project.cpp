#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* game;
Player* myplayer;

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
    myplayer = new Player(game);

}

void GetInput(void)
{
    //game->getInput();
}

void RunLogic(void)
{
    myplayer->updatePlayerDir();
    myplayer->movePlayer();

    game->clearInput();
    
}

void DrawScreen(void)
{
    
    objPos pObj;
    myplayer->getPlayerPos(pObj);
    MacUILib_clearScreen();
    for(int i = 0; i<game->getBoardSizeY(); i++)
    {
        for(int j = 0; j<game->getBoardSizeX(); j++)
        {
            if( i==0 || i==game->getBoardSizeY()-1 || j==0 || j==game->getBoardSizeX()-1)
            {
                MacUILib_printf("#");
            }
            else if (i == pObj.y && j == pObj.x)
            {
                MacUILib_printf("%c", pObj.symbol);
            }
            else 
            { 
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("Score %d, Player Pos: <%d, %d>\n",
                    game->getScore(), pObj.x, pObj.y);
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    //detele game
    //delete myplayer
}
