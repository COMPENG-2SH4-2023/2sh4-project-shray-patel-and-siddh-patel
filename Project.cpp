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

//Initalization of Global References to classes
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

    //Initializing, allocating memory and using construtors for the appropriate class references
    game = new GameMechs(30,15);// Reference to Game Mechanics Class
    fObj = new Food(game);// Reference to Food Class 
    myplayer = new Player(game,fObj); //Reference to Player Class

    playerBody = myplayer->getPlayerPos();//Pointer used to get the player list(member of the Player class)

    srand(time(NULL)); //Seeding the Random Numbers so Food is generated correctly
    
    //Calling generateFood method in Food class to generate a food item at a random location on the board
    fObj->generateFood(playerBody);

}

void GetInput(void)
{
    //Calling the getInput method in GameMech class to check if user as inputted a key press to move the snake
    game->getInput();
    
}

void RunLogic(void)
{

    myplayer->updatePlayerDir(); //Calling updatePlayerDir method in Player class to update the direction of the player snake
    myplayer->movePlayer(); //Calling movePlayer method in Player class to update the coordinates of the plater snake to implement the movement indicated by the user
    game->clearInput(); //Calling clearInput method in GameMechs class to clear the input buffer

}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    bool drawn; // Boolean Variable used to print out snake body correctly 
    
    playerBody = myplayer->getPlayerPos(); // Updates the playerBody with the current position of the player snake
    objPos tempPlay; //Temporary instance of objPos class to store the snake body element
    
    objPos fPos; // Temporary instance of objPos class to store food element position
    fObj->getFoodPos(fPos); //Calling getFoodPos method in Food class to get the current position of the food element

    
    //For Loop to print out the snakes body
    for(int i = 0; i<game->getBoardSizeY(); i++)
    {
        for(int j = 0; j<game->getBoardSizeX(); j++)
        {
            drawn = false; //Initially sets drawn to false so that it resets every cycle

            //For loop that goes through all the elements in the snake body 
            for(int k=0; k<playerBody->getSize(); k++)
            {

                playerBody->getElement(tempPlay,k); //Calling the getElement method in objPosArrayList class, and assigns the object to tempPlay
                
                //This if statment checks if the player element is the same as the i and j coordinates that is being checked
                if(tempPlay.y == i && tempPlay.x == j)
                {
                    MacUILib_printf("%c", tempPlay.symbol);
                    drawn = true;
                    break;
                }
            }

            if(drawn) continue;
            //If the player body was drawn dont draw anything below

            //Draw Border by checking if the coordinates are correct then print the border 
            if( i==0 || i==game->getBoardSizeY()-1 || j==0 || j==game->getBoardSizeX()-1)
            {
                MacUILib_printf("#");
            }

            // if the coordinates match the food object then it prints out the food object 
            else if(i == fPos.y && j == fPos.x)
            {
                MacUILib_printf("%c", fPos.symbol);
            }

            //else print out the white space for the middle of the board ("Playing field")
            else 
            { 
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }

    //Print Statments to print out below the game board, showing stats
    MacUILib_printf("Score %d\n",game->getScore());
    MacUILib_printf("Food Pos: <%d,%d>\n",fPos.x,fPos.y);


    //This is a if statment to decide which message is supposed to be displayed based on whether the user lost or quit the game
    //This is based on the status of the lose and exit flag
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

    //Freeing Memory for previously allocated memory for the pointers to other classes.
    delete game;
    delete myplayer;
    delete fObj;
}
