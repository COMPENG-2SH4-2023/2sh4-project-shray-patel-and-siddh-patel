#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000
#define X 30
#define Y 15
GameMechs* game;
Player* player;

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
    player = new Player(game);

}

void GetInput(void)
{
    if(MacUILib_hasChar()==1)
    {
        game->setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{
    
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    int i; // ROW
    for ( i = 0; i < Y; i++)
    {
        int j; // COLOUM
        for ( j = 0; j < X; j++)
        {       
            // Print Border
            if (i == 0 || i == Y-1 || j == X-1 || j == 0)
            {
                MacUILib_printf("#");
            }
            // Print empty space to make grid
            else 
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
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
