#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000
#define X 30
#define Y 15
GameMechs* GameMechsRef;
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

    while(GameMechsRef->getExitFlagStatus() == false)  
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

    Player *player = new Player(GameMechsRef);
    GameMechs *game = new GameMechs();

}

void GetInput(void)
{
    if(MacUILib_hasChar()==1)
    {
        input = MacUILib_getChar();
    }
}

void RunLogic(void)
{
    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case ' ':  // exit
                exitFlag = 1;
                break;

            case 'w':
                if(play_dir != DOWN)
                {
                    play_dir = UP;
                }
                break;
            case 's':
                if(play_dir != UP)
                {
                    play_dir = DOWN;
                }
                break;
            case 'a':
                if(play_dir != RIGHT)
                {
                    play_dir = LEFT;
                }
                break;
            case 'd': 
                if(play_dir != LEFT)
                {
                    play_dir = RIGHT;
                }
                break;
            default:
                break;

        }
        input = 0;
    }
    
}

void DrawScreen(void)
{
    
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
