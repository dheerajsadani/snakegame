#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int width=20,height=20;
int x,y,fruitX,fruitY,score,gameover,flag;
int tailX[150], tailY[150];
int countail=0;


void setup()
{
    score=0;
    gameover=0;
    x=height/2;
    y=width/2;

    label1:
    fruitX=rand()%20;
    if(fruitX==0)
        goto label1;

    label2:
    fruitY=rand()%20;
    if(fruitY==0)
        goto label2;

}
void draw()
{
    system("cls");
    int i,j,k;

    for(i=0;i<width;i++)
    {
        for(j=0;j<height;j++)
        {
           if(i==0 || i==width-1 ||j==0 ||j==height-1)
              {
                  printf("*");
              }
           else
              {

                  if(i==x && j==y)
                    printf("O");
                  else if(i==fruitX && j==fruitY)
                    printf("F");
                  else
                     {
                           int p=0;
                           for(k=0;k<countail;k++)
                            {
                               if(i==tailX[k] && j==tailY[k])
                                {
                                   printf("o");
                                   p=1;
                                }
                             }
                             if(p==0)
                               printf(" ");
                       }

               }
         }
      printf("\n");
      }
  printf("SCORE: %d",score);
}

void input()
{
    if(kbhit())
    {
        switch(getch())
        {
             case 'a' :  // adws
                flag=1;
                break;
             case 'd':
                flag=2;
                break;
             case 'w':
                flag=3;
                break;
             case 's':
                flag=4;
                break;
             case 'q':
                gameover=1;
                break;
        }
    }
}

void Mainlogic()
{
    int i;
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X,prev2Y;
    tailX[0]=x;
    tailY[0]=y;

    for(i=1;i<countail;i++)
    {
        prev2X=tailX[i];
        prev2Y=tailY[i];

        tailX[i]=prevX;
        tailY[i]=prevY;

        prevX=prev2X;
        prevY=prev2Y;

    }

    switch(flag)
    {
        case 1:
            y--;
            break;
        case 2:
            y++;
            break;
        case 3:
            x--;
            break;
        case 4:
            x++;
            break;

        default:
            break;

    }
    if(x<0 ||x>height || y<0 || y>width)
        gameover=1;
    for(i=0;i<countail;i++)
    {
        if(x==tailX[i] && y==tailY[i])
            gameover=1;
    }
    if(x==fruitX && y==fruitY)
    {
        score+=5;
        countail++;

        label3:
          fruitX=rand()%20;
          if(fruitX==0)
            goto label3;

        label4:
        fruitY=rand()%20;
        if(fruitY==0)
            goto label4;
    }

}
int main()
{
    int m,n;
    char c;
    label5:
    setup();
    while(!gameover)
    {
        draw();
        input();
        Mainlogic();
        usleep(50000);
     }
     countail=0;
     flag=0;
     printf("\nPress Y to Play Again: ");
     scanf("%c",&c);
     if(c=='y' || c=='Y')
        goto label5 ;
    return 0;
}
