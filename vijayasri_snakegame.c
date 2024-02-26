#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<unistd.h>

int i,j,H=16,W=16,game_over,score;
int x,y,point_x,point_y,flag;
int gameover,score,c=0;

// Function to draw the outer wall
void draw_outer_wall()
{
    system("cls");
    printf("Press Left, Right, Up or Down Arrow to Start...\n\n");
    for(i=0;i<H;i++)
    {
        printf(" ");
        for(j=0;j<W;j++)
        {
            if(i==0 || i==H-1 || j==0 || j==W-1)
                printf("[]");
            else
            {
                if(i==x && j==y)
                    printf("0 ");
                else if(i==point_x && j==point_y)
                    printf("$ ");
                else
                    printf("  ");
            }
        }
        printf("\n");
    }
    printf("\nScore : %d\n",score);
    printf("press q for Quit the Game\n");
}

// Function to generate points within the outer wall
void set_random_ball()
{
    game_over=0;
    x=H/2;
    y=W/2;
x_label:
    point_x=rand()%16;
    if(point_x == 0)
        goto x_label;
y_label:
    point_y=rand()%16;
    if(point_y == 0)
        goto y_label;
    score=0;
}

// Function to take user input
void user_input()
{
    if(kbhit())
    {
        switch(getch())
        {
            case 75: flag=1;
                break;
            case 77: flag=2;
                break;
            case 72: flag=3;
                break;
            case 80: flag=4;
                break;
            case 'q': gameover=2;
                break;
        }
    }
}

// Function for movement
void move_logic()
{
    usleep(100000); // Sleep for 100,000 microseconds (0.1 seconds) to slow down the game.
    switch(flag)
    {
        case 1: y--;
            break;
        case 2: y++;
            break;
        case 3: x--;
            break;
        case 4: x++;
            break;
    }
    if(x<1 || x>H-2 || y<1 || y>W-2)
        gameover=1;
    if(x==point_x && y==point_y)
    {
x_label:
        point_x=rand()%16;
        if(point_x == 0)
            goto x_label;
y_label:
        point_y=rand()%16;
        if(point_y == 0)
            goto y_label;
        score=score+1;
    }
}

int main()
{
start:
    gameover=0;
    flag=0;
    c=0;
    set_random_ball();
    while(gameover!=1 && gameover!=2)
    {
        draw_outer_wall();
        user_input();
        move_logic();
    }
    if (gameover==2)
        printf("You Quit the Game\n");
    else
    {
        char ch;
        printf("You Hit the wall want to play again(y/n): ");
        scanf(" %c",&ch);
        if(ch=='y' || ch=='Y')
            goto start;
        else
            printf("Program Ended\n");
    }
    return 0;
}
