#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
void drawBoundary(int,int,int *,int *,int *);
void changeUserLocationOnButtonClick(int * , int *, char , int *, int *);
void drawBoundary(int x, int y, int * posX, int * posY, int * gameOver)
{
    int i,j,k;
    for ( i = -1; i <= 10; i++)
    {
        for ( j = -1; j <= 50; j++)
        {
            if (i == -1 || i == 10 || j == -1 || j == 50)
            {
                printf("#");
            }
            else
            {
                if (i == y && j == x)
                {
                    printf("P");
                    for ( k = 0; k < 4; k++)
                    {
                        if (posX[k] == x && posY[k] == y)
                        {
                            posX[k] = -1;
                            posY[k] = -1;
                            (*gameOver)++;
                        }
                        
                    }
                    
                }
                else
                {
                    if (posX[0] == j && posY[0] == i)
                    {
                        printf("a");
                    }
                    else if (posX[1] == j && posY[1] == i)
                    {
                        printf("b");
                    }
                    else if (posX[2] == j && posY[2] == i)
                    {
                        printf("c");
                    }
                    else if (posX[3] == j && posY[3] == i)
                    {
                        printf("d");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
    
}
void changeUserLocationOnButtonClick(int *x, int * y, char keyPressed, int * noOfMoves, int * gameQuit)
{
    switch (keyPressed)
    {
    case 'w':
        if (*y!=0)
        {
            (*noOfMoves)++;
            (*y)--;
        }
        
        break;
    case 'a':
        if (*x!=0)
        {
            (*noOfMoves)++;
            (*x)--;
        }
        
        break;
    case 's':
        if (*x!=49)
        {
            (*noOfMoves)++;
            (*x)++;
        }
        
        break;
    case 'z':
        if (*y!=9)
        {
            (*noOfMoves)++;
            (*y)++;
        }
        
        break;
    case 'q':
        *gameQuit = 1;
        break;
    default:
        break;
    }
}
int main()
{
    int x = 0, y = 0;
    char ch;
    int positionX[4] = {0};
    int positionY[4] = {0};
    int randomNum , i = 0;
    int gameOver = 0, noOfMoves = 0, gameQuit = 0;
    srand(time(0));
    while (i<4)
    {
        randomNum = rand()%50;
        positionX[i] = randomNum;
        i++;
    }
    i = 0;
    while (i<4)
    {
        randomNum = rand()%10;
        positionY[i] = randomNum;
        i++;
    }
    drawBoundary(x,y,positionX,positionY,&gameOver);
    while (1)
    {
        if (kbhit())
        {
            ch = getch();
            system("cls");
            changeUserLocationOnButtonClick(&x,&y,ch,&noOfMoves,&gameQuit);
            if (gameQuit == 0)
            {
                drawBoundary(x,y,positionX,positionY,&gameOver);
                if(gameOver == 4)
                {
                    system("cls");
                    printf("\n[][][][] Well Done [][][][]\n");
					printf("\nYou Collected All The Jwels!\n");
					printf("\nIt Took You %d Moves!\n",noOfMoves);
					printf("\n[][][][] Game Over [][][][]\n");
					break;
                }
            }
            else
            {
               system("cls");
               printf("\nOh No! You Quit!!\n");
				printf("\nYou Collected %d Jwels!\n",gameOver); 
				printf("\nAfter %d Moves You Quit!\n",noOfMoves); 
				printf("\n[][][][] Game Over [][][][]\n");
				break; 
            }
        }
        
    }
    getch();
    return 0;
}