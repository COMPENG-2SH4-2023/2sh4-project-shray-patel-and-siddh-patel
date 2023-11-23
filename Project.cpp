#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000
#define X 15
#define Y 30
char border[X][Y];
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

    game = new GameMechs(X,Y);
    myplayer = new Player(game);

}

void GetInput(void)
{
    
}

void RunLogic(void)
{
    myplayer->updatePlayerDir();
    myplayer->movePlayer();
    
    
}

void DrawScreen(void)
{
    
    int i,j;
    objPos pObj;
    myplayer->getPlayerPos(pObj);
    MacUILib_clearScreen();
    for(i = 0; i<game->getBoardSizeX(); i++)
    {
        for(j = 0; j<game->getBoardSizeY(); j++)
        {
            if( i==0 || i==game->getBoardSizeX()-1 || j==0 || j==game->getBoardSizeY()-1)
            {
                border[i][j] = '#';
            }
            else if(pObj.x == i && pObj.y== j)
            {
                border[i][j] = pObj.symbol;
            }
            // else if(itmBin[0].x == i && itmBin[0].y == j)
            // {
            //     border[i][j] = itmBin[0].symbol;
            // }
            // else if(itmBin[1].x == i && itmBin[1].y == j)
            // {
            //     border[i][j] = itmBin[1].symbol;
            // }
            // else if(itmBin[2].x == i && itmBin[2].y == j)
            // {
            //     border[i][j] = itmBin[2].symbol;
            // }
            // else if(itmBin[3].x == i && itmBin[3].y == j)
            // {
            //     border[i][j] = itmBin[3].symbol;
            // }
            // else if(itmBin[4].x == i && itmBin[4].y == j)
            // {
            //     border[i][j] = itmBin[4].symbol;
            // }
            else 
            { 
                border[i][j] = ' ' ;
            }
            MacUILib_printf("%c", border[i][j]);
            if(j==29)
            {
                MacUILib_printf("\n");
            }
        }
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
