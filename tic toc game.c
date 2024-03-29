#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
char square[10] = {'0','1','2','3','4','5','6','7','8','9'};
int choice,player;

int checkforwin();
void displayboard();
void markboard(char mark);

int main()
{
    displayboard();
    int gamestatus;
    char mark;
    player = 1;

    do
    {
        displayboard();
        player = (player % 2) ? 1 : 2;

        printf("player %d,enter a number: ",player);
        scanf("%d", &choice);

        mark = (player == 1 )  ? 'X' : 'O';

        markboard(mark);
        gamestatus = checkforwin();
        player++;

    }while (gamestatus == -1);
     if (gamestatus == 1)
        printf("==>\aplayer %d win ",--player);
     else
        printf("==>\agame draw");
    return 0;
}
/*********************************
FUNTION TO RETURN GAME STATUS
1 FOR THE GAME IS OVER WITH RESULT
-1 FOR THE GAME IS IN PROGRESS
0 GAME IS OVER AND NO RESUILT
**********************************/
int checkforwin()
{
    int returnvalue = 0;
    if (square[1] == square[2] && square[2] == square[3])
    {
       returnvalue = 1;
    }
    else if (square[4] == square[5] && square[5] == square[6])
        returnvalue = 1;
    else if (square[7] == square[8] && square[8] == square[9])
        returnvalue = 1;
    else if (square[1] == square[4] && square[4] == square[7])
        returnvalue = 1;
    else if (square[2] == square[5] && square[5] == square[8])
        returnvalue = 1;
    else if (square[3] == square[6] && square[6] == square[9])
        returnvalue = 1;
    else if (square[1] == square[5] && square[5] == square[9])
        returnvalue = 1;
    else if (square[3] == square[5] && square[5] == square[7])
        returnvalue = 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
         returnvalue = 0;
    else
        returnvalue = -1;
    return returnvalue;
}
/***************************************************************
FUNTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
***************************************************************/
void displayboard()
{
    system("cls");
    printf("\n\n\tTIC TAC TOE \n\n");
    printf("player 1 (X)  -  player 2 (0)\n\n\n");

    printf("    |    |   \n");
    printf("  %c |  %c |  %c \n",square[1],square[2],square[3]);
    printf("____|____|____\n");
    printf("    |    |    \n");
    printf("  %c |  %c |  %c \n",square[4],square[5],square[6]);
    printf("____|____|____\n");
    printf("    |    |    \n");
    printf("  %c |  %c |  %c \n",square[7],square[8],square[9]);
    printf("    |    |    \n\n");
}
/*************************************
SET TEH BOARD WITH THE CORRECT CHARACTER,
X OR O IN THE CORRECT SPOT IN THE ARRAY
**************************************/
void markboard(char mark)
{
    if (choice == 1 && square[1] == '1' )
        square[1] = mark;
    else if (choice == 2 && square[2]=='2')
        square[2] = mark;
    else if (choice == 3 && square[3]=='3')
        square[3] = mark;
    else if (choice == 4 && square[4]=='4')
        square[4] = mark;
    else if (choice == 5 && square[5]=='5')
        square[5] = mark;
    else if (choice == 6 && square[6]=='6')
        square[6] = mark;
    else if (choice == 7 && square[7]=='7')
        square[7] = mark;
    else if (choice == 8 && square[8]=='8')
        square[8] = mark;
    else if (choice == 9 && square[9]=='9')
        square[9] = mark;
    else
    {
        printf("Invalid move");

        player--;
        getch();

    }
}
