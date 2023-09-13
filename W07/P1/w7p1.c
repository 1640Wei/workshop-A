/*
*****************************************************************************
                          Workshop - #7 (P1)
Full Name  : Ching Wei Lai
Student ID#: 136893211
Email      : cwlai6@myseneca.ca
Section    : NHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX_LIVES 10
#define MIN_LIVES 1
#define MAX_PATH 70
#define MIN_PATH 10
#define PATH_WIDTH 5

struct PlayerInfo 
    {
        char name;
        int lives;
        int numTrea;
	    int positionHistory[MAX_PATH];        
    };

struct GameInfo 
    {
        int pathLen;
        int moveNum; 
        int bombs[MAX_PATH];
        int treasure[MAX_PATH];
    };

int main(void)
{
    struct PlayerInfo player;
    struct GameInfo game; 
    int moveMAX;
    int i;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %s", &player.name);
    printf("Set the number of lives: ");
    scanf("%d", &player.lives);
    while (player.lives < MIN_LIVES || player.lives > MAX_LIVES) 
    {
           printf("     Must be between 1 and 10!\n");
           printf("Set the number of lives: ");
           scanf("%d", &player.lives);
    }
    printf("Player configuration set-up is complete\n");
    printf("\n");

    printf("GAME Configuration\n");
    printf("------------------\n");
    printf("Set the path length (a multiple of 5 between 10-70): ");
    scanf("%d", &game.pathLen);
    while (game.pathLen < MIN_PATH || game.pathLen > MAX_PATH || game.pathLen % PATH_WIDTH != 0) 
    {
           printf("     Must be a multiple of 5 and between 10-70!!!\n");
           printf("Set the path length (a multiple of 5 between 10-70): ");
           scanf("%d", &game.pathLen);
    }
    printf("Set the limit for number of moves allowed: ");
    scanf("%d", &game.moveNum);

    moveMAX = game.pathLen * 0.75;
    while (game.moveNum < player.lives || game.moveNum > moveMAX)
    {
        printf("    Value must be between %d and %d\n", player.lives, moveMAX);
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.moveNum);
    }
    
    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLen);
    for (i = 0; i < game.pathLen / 5; i++) 
    {
        printf("   Positions [%2d-%2d]: ", 5 * i + 1, 5 * (i + 1));
        scanf("%d %d %d %d %d",
              &game.bombs[i * 5],
              &game.bombs[i * 5 + 1],
              &game.bombs[i * 5 + 2],
              &game.bombs[i * 5 + 3],
              &game.bombs[i * 5 + 4]);
    }
    printf("BOMB placement set\n");
    printf("\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLen);
    for (i = 0; i < game.pathLen / 5; i++) 
    {
        printf("   Positions [%2d-%2d]: ", 5 * i + 1, 5 * (i + 1));
        scanf("%d %d %d %d %d",
              &game.treasure[i * 5],
              &game.treasure[i * 5 + 1],
              &game.treasure[i * 5 + 2],
              &game.treasure[i * 5 + 3],
              &game.treasure[i * 5 + 4]);
    }
    printf("TREASURE placement set\n");
    printf("\n");

    printf("GAME configuration set-up is complete...\n");
    printf("\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.name);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLen);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathLen; i++)
    {
        printf("%d", game.bombs[i]);
	}
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < game.pathLen; i++)
    {
        printf("%d", game.treasure[i]);
	}
    printf("\n\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    return 0;
}
