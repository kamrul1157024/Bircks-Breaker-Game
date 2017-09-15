
# include "iGraphics.h"
#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;

int r=255,g=0,b=150;
int dbx, dby;
int plateL=120,plateB=15;
int plateX=400,plateY=10;
int ball_r=7;
int ball_x=500, ball_y=10+ball_r+plateY;
int score=0;
int screen=1;
int highScore=0;
void createEight(int num,int x,int y,int dx)
{
   switch(num)
   {
        case 9:
  //  iFilledRectangle(x,y,15,150);//0
    iFilledRectangle(x,y,120/dx,15/dx);//1
    iFilledRectangle(x+120/dx,y,15/dx,165/dx);//2
    iFilledRectangle(x,y+150/dx,120/dx,15/dx);//3
    iFilledRectangle(x,y+150/dx,15/dx,165/dx);//4
    iFilledRectangle(x,y+300/dx,120/dx,15/dx);//5
    iFilledRectangle(x+120/dx,y+150/dx,15/dx,165/dx);//6
    break;
   case 8:
    iFilledRectangle(x,y,15/dx,150/dx);//0
    iFilledRectangle(x,y,120/dx,15/dx);//1
    iFilledRectangle(x+120/dx,y,15/dx,165/dx);//2
    iFilledRectangle(x,y+150/dx,120/dx,15/dx);//3
    iFilledRectangle(x,y+150/dx,15/dx,165/dx);//4
    iFilledRectangle(x,y+300/dx,120/dx,15/dx);//5
    iFilledRectangle(x+120/dx,y+150/dx,15/dx,165/dx);//6
    break;
    case 7:
    iFilledRectangle(x+120/dx,y,15/dx,165/dx);//2
    iFilledRectangle(x,y+300/dx,120/dx,15/dx);//5
    iFilledRectangle(x+120/dx,y+150/dx,15/dx,165/dx);//6
    break;
    case 6:
    iFilledRectangle(x,y,15/dx,150/dx);//0
    iFilledRectangle(x,y,120/dx,15/dx);//1
    iFilledRectangle(x+120/dx,y,15/dx,165/dx);//2
    iFilledRectangle(x,y+150/dx,120/dx,15/dx);//3
    iFilledRectangle(x,y+150/dx,15/dx,165/dx);//4
    iFilledRectangle(x,y+300/dx,120/dx,15/dx);//5
    break;
     case 5:
    iFilledRectangle(x,y,120/dx,15/dx);//1
    iFilledRectangle(x+120/dx,y,15/dx,165/dx);//2
    iFilledRectangle(x,y+150/dx,120/dx,15/dx);//3
    iFilledRectangle(x,y+150/dx,15/dx,165/dx);//4
    iFilledRectangle(x,y+300/dx,120/dx,15/dx);//5
    break;
     case 4:
    iFilledRectangle(x+120/dx,y,15/dx,165/dx);//2
    iFilledRectangle(x,y+150/dx,120/dx,15/dx);//3
    iFilledRectangle(x,y+150/dx,15/dx,165/dx);//4
    iFilledRectangle(x+120/dx,y+150/dx,15/dx,165/dx);//6
    break;
     case 3:
    iFilledRectangle(x,y,120/dx,15/dx);//1
    iFilledRectangle(x+120/dx,y,15/dx,165/dx);//2
    iFilledRectangle(x,y+150/dx,120/dx,15/dx);//3
    iFilledRectangle(x,y+300/dx,120/dx,15/dx);//5
    iFilledRectangle(x+120/dx,y+150/dx,15/dx,165/dx);//6
    break;


     case 2:
    iFilledRectangle(x,y,15/dx,150/dx);//0
    iFilledRectangle(x,y,120/dx,15/dx);//1
    iFilledRectangle(x,y+150/dx,120/dx,15/dx);//3
    iFilledRectangle(x,y+300/dx,120/dx,15/dx);//5
    iFilledRectangle(x+120/dx,y+150/dx,15/dx,165/dx);//6
    break;

     case 1:
    iFilledRectangle(x+120/dx,y,15/dx,165/dx);//2
    iFilledRectangle(x+120/dx,y+150/dx,15/dx,165/dx);//6
    break;
     case 0:
     iFilledRectangle(x,y,15/dx,150/dx);//0
    iFilledRectangle(x,y,120/dx,15/dx);//1
    iFilledRectangle(x+120/dx,y,15/dx,165/dx);//2
    iFilledRectangle(x,y+150/dx,15/dx,165/dx);//4
    iFilledRectangle(x,y+300/dx,120/dx,15/dx);//5
    iFilledRectangle(x+120/dx,y+150/dx,15/dx,165/dx);//6
    break;

   }
}



int brick[4][18]={
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
int x=-1,y=-1;


void reset()
{
int i,j;
for(i=0;i<4;i++)
{
    for(j=0;j<18;j++)
        brick[i][j]=1;
}
x=-1,y=-1;
 r=255,g=0,b=150;
 plateL=120,plateB=15;
 plateX=400,plateY=10;
 ball_r=7;
 ball_x=500, ball_y=10+ball_r+plateY;
 score=0;

}


void text(char str,int x,int y,int dx)
{
    switch(str)
    {
    case 's':
        iFilledRectangle(x,y,dx+dx*.25,dx*.25);
        iFilledRectangle(x+dx,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+dx,dx+dx*.25,dx*.25);
        iFilledRectangle(x,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+2*dx,dx+dx*.25,dx*.25);


  break;
    case 'c':
        iFilledRectangle(x,y,dx+dx*.25,dx*.25);
        iFilledRectangle(x,y,dx*.25,dx+dx*.25);
    //    iFilledRectangle(x,y+dx,dx+dx*.25,dx*.25);
        iFilledRectangle(x,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+2*dx,dx+dx*.25,dx*.25);

  break;
    case 'r':
        iFilledRectangle(x+dx*.7,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x+dx,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+dx,dx+dx*.25,dx*.25);
        iFilledRectangle(x,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+2*dx,dx+dx*.25,dx*.25);

  break;
      case 'e':
        iFilledRectangle(x,y,dx+dx*.25,dx*.25);
        iFilledRectangle(x,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+dx,dx+dx*.25,dx*.25);
        iFilledRectangle(x,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+2*dx,dx+dx*.25,dx*.25);

  break;

      case 'y':
        iFilledRectangle(x+dx*.5,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x+dx,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+dx,dx+dx*.25,dx*.25);
        iFilledRectangle(x,y+dx,dx*.25,dx+dx*.25);
   //  iFilledRectangle(x,y+2*dx,dx+dx*.25,dx*.25);

  break;

      case 'o':
        iFilledRectangle(x,y,dx+dx*.25,dx*.25);
        iFilledRectangle(x+dx,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x+dx,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+2*dx,dx+dx*.25,dx*.25);

  break;
      case 'u':
        iFilledRectangle(x,y,dx+dx*.25,dx*.25);
        iFilledRectangle(x+dx,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x+dx,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+dx,dx*.25,dx+dx*.25);

  break;
      case 'w':
        iFilledRectangle(x,y,dx+dx*.5,dx*.25);
        iFilledRectangle(x+dx*1.5,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x+dx*1.5,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x+dx*.75,y,dx*.25,dx+dx*.25);

         break;

           case 'm':
        iFilledRectangle(x,y+2*dx,dx+dx*.5,dx*.25);
        iFilledRectangle(x+dx*1.5,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x+dx*1.5,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x+dx*.75,y,dx*.25,dx+dx*.25);

         break;
          case 'i':
        iFilledRectangle(x,y+dx,dx*.25,dx*.25);
        iFilledRectangle(x,y,dx*.25,dx-dx*.15);

         break;
        case 'n':
       // iFilledRectangle(x,y,dx+dx*.25,dx*.25);
        iLine(x+dx*.25,y+2*dx,x+dx*1.1,y);
        iLine(x+dx*.1,y+2*dx,x+dx,y);
        iFilledRectangle(x+dx,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x+dx,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+dx,dx*.25,dx+dx*.25);
     //   iFilledRectangle(x,y+2*dx,dx+dx*.25,dx*.25);

        break;
        case 'x':
            iLine(x+dx*.25,y+2*dx,x+dx*1.1,y);
            iLine(x+dx*.1,y+2*dx,x+dx,y);
            iLine(x+2*dx,y+2*dx,x,y);
            iLine(x+dx*.1,y+2*dx,x+dx,y);
        break;
        case 't':
      //  iFilledRectangle(x,y,dx+dx*.25,dx*.25);
       // iFilledRectangle(x+dx,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x+dx*.5,y,dx*.25,dx+dx*.25);
       // iFilledRectangle(x+dx,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x+dx*.5,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+2*dx,dx+dx*.25,dx*.25);

  break;

   case 'l':
        iFilledRectangle(x,y,dx+dx*.25,dx*.25);
        iFilledRectangle(x,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y,dx*.25,dx+dx*.25);
break;

      case 'p':
        iFilledRectangle(x,y+dx,dx+dx*.25,dx*.25);
      //  iFilledRectangle(x+dx,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x+dx,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+2*dx,dx+dx*.25,dx*.25);

  break;

        case 'a':
        iFilledRectangle(x,y+dx,dx+dx*.25,dx*.25);
        iFilledRectangle(x+dx,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x+dx,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+2*dx,dx+dx*.25,dx*.25);

  break;
        case 'b':
        iFilledRectangle(x,y,dx+dx*.25,dx*.25);
        iFilledRectangle(x,y+dx,dx+dx*.25,dx*.25);
        iFilledRectangle(x+dx,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x+dx,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+2*dx,dx+dx*.25,dx*.25);

  break;

          case 'k':
         iFilledRectangle(x,y,dx*.25,2*dx+2*dx*.25);
         iLine(x,y+dx,x+dx,y+2*dx);
         iLine(x,y+dx,x+dx,y);
         break;
        case 'h':
        iFilledRectangle(x,y+dx,dx+dx*.25,dx*.25);
        iFilledRectangle(x+dx,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y,dx*.25,dx+dx*.25);
      //  iFilledRectangle(x+dx,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+dx,dx*.25,dx+dx*.25);
       // iFilledRectangle(x,y+2*dx,dx+dx*.25,dx*.25);
       break;
        case 'd':
        iFilledRectangle(x,y,dx+dx*.25,dx*.25);
        iFilledRectangle(x+dx,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x+dx,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+dx,dx+dx*.25,dx*.25);
      //  iFilledRectangle(x,y+2*dx,dx+dx*.25,dx*.25);
        break;
         case 'q':
        iFilledRectangle(x+dx*.5,y,dx*.25,dx+dx*.3);
        iFilledRectangle(x+dx,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+dx,dx+dx*.25,dx*.25);
        iFilledRectangle(x,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+2*dx,dx+dx*.25,dx*.25);
        break;

        case 'g':
        iFilledRectangle(x,y,dx+dx*.25,dx*.25);
        iFilledRectangle(x+dx,y,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+dx,dx+dx*.25,dx*.25);
        iFilledRectangle(x+dx,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+dx,dx*.25,dx+dx*.25);
        iFilledRectangle(x,y+2*dx,dx+dx*.25,dx*.25);

  break;
    }



}


void writeHighScore()
{

    int data;
    ofstream outfile;
    outfile.open("data.dat");
    data=highScore;
    outfile<<data<<endl;
    outfile.close();


}
void readHighscore()
{
    int data;
    ifstream infile;
    infile.open("data.dat");
    infile>>data;
    infile.close();

    highScore=data;
}

int brickCheck()
{int l=0;
    int i,j;
    for(i=1;i<4;i++)
    {
        for(j=0;j<15;j++)
        {
            if(brick[i][j]!=0)
            {
                l=1;
                break;
            }
        }
    }
    return l;
}

void brickDraw()
{
    time_t t=clock();

int i=0,j=0,lx=7,ly=500-4*25,k=59;

for(i=1;i<4;i++)
{
    for(j=0;j<18;j++)
    {
     //   iSetColor(t%*20,t%200,t%100);

       if(brick[i][j]==1)
         iFilledRectangle(lx,ly,50,20);
       lx+=55;
    }
    lx=7;

    ly+=25;
}
}
void brickPos()
{
    int brick_x=7,brick_y=500-4*20-3;

    int i,j;

    if(ball_y>=500-4*20)
    {
    for(i=1;i<=4;i++)
    {
        for(j=0;j<18;j++)
        {
             if(brick[i][j]==1&&ball_x==brick_x&&ball_x<brick_x+55&&ball_y>=brick_y)
            {
              //iDelay(1);
              dbx=-dbx;
                dby=-dby;

            brick[i][j]=0;
        score+=10;
        cout<<"\a";
     //          iSetColor(25,33,33) ;
                break;
            }
   //     cout<<endl<<" brick[i][j] "<<brick[i][j]<<" brick_x<"<<brick_x<<" < ball_x "<<ball_x<<" < brick_x+50 "<<brick_x+50<< " ball_y<"<<ball_y <<"brick_y"<< brick_y<<endl;
          else  if(brick[i][j]==1&&ball_x>brick_x&&ball_x<brick_x+55&&ball_y>=brick_y)
            {
              //iDelay(1);
                dby=-dby;

            brick[i][j]=0;
        score+=10;
        cout<<"\a";
     //          iSetColor(25,33,33) ;
                break;
            }

            else
            {
                brick_x+=55;
            }



        }
brick_x=7;


        brick_y+=20;

    }
    }

}



//screens are here

void screen1()//1st screen
{

      iSetColor(51,153,255);
      iFilledRectangle(0,0,1100,500);
      iSetColor(51,102,255);
      iFilledRectangle(350,300,150,70);
       iFilledRectangle(350,200,150,70);
      iSetColor(255,255,255);
      readHighscore();
   char s1[]="start";
    int i=0;
int  posX=350;
    while(s1[i]!='\0')
{

   text(s1[i],posX+4,310,20) ;
   posX+=30;
   i++;
}

   char s2[]="help";
    i=0;
 posX=350;
    while(s2[i]!='\0')
{

   text(s2[i],posX+4,220,20) ;
   posX+=30;
   i++;
}

char    s[]="brick breaker";
    i=0;
 posX=300;
    while(s[i]!='\0')
{

   text(s[i],posX,400,15) ;
   posX+=23;
   i++;
}

char    s5[]="high score";
    i=0;
 posX=700;
    while(s5[i]!='\0')
{

   text(s5[i],posX,300,10) ;
   posX+=23;
   i++;
}

i=0;
int num_s=highScore;
posX=750;
int digit;
while(i<3)
{
  digit=num_s%10;
createEight(digit,posX+30,200,5);
num_s/=10;
posX-=30;
i++;
}

 reset();

}


void screen2()//all brick code
{
int digit,num_s=score;
int i,pos,posX,posY;
iSetColor(51,153,255);
iFilledRectangle(0,0,1100,500);
if(brickCheck()==1)
{
char    s[]="score";
 iSetColor(255,255,255);


iFilledCircle(ball_x, ball_y, ball_r);
iFilledRectangle(plateX,plateY,plateL,plateB);
iUnRotate();
brickDraw();
brickPos();
i=0,pos=20,posX=0,posY=500-22;
while(s[i]!='\0')
{
   text(s[i],posX,posY,8) ;
   posX+=pos;
   i++;
}

i=0;
while(i<3)
{
  digit=num_s%10;
createEight(digit,posX+30,posY,15);
num_s/=10;
posX-=10;
i++;
}

	if(ball_y<plateY+plateB-3)
    {
     screen=6;
   // dby=-dby;
    }
}

else if(brickCheck()==0)
{
    screen=8;
    if(score>highScore)
     screen=7;
}
}

void screen3()//game over screen or win
{
    iSetColor(51,153,255);
    iFilledRectangle(0,0,1100,500);
      iSetColor(51,103,255);
iFilledRectangle(200,100,300,70);
iSetColor(255,255,255);
char s[]="play again";
    int i=0;
int posX=200;
   while(s[i]!='\0')
{

 text(s[i],posX+4,110,20) ;
  posX+=30;
   i++;
}

iSetColor(51,103,255);
iFilledRectangle(550,100,300,70);
iSetColor(255,255,255);
char s8[]="quit";
     i=0;
 posX=630;
   while(s8[i]!='\0')
{

 text(s8[i],posX+4,110,20) ;
  posX+=30;
   i++;
}

 char s3[]="high score";
    i=0;
  posX=300;
    while(s3[i]!='\0')
{

   text(s3[i],posX,250,10) ;
   posX+=20;
   i++;
}
i=0;

posX+=3;
iFilledCircle(posX,265,2);
iFilledCircle(posX,257,2);


int num_s=highScore;
posX+=20;
int digit;
while(i<3)
{
  digit=num_s%10;
createEight(digit,posX+30,250,10);
num_s/=10;
posX-=18;
i++;
}


char s4[]="current score";
    i=0;
    posX=300;
    while(s4[i]!='\0')
{

   text(s4[i],posX,300,10) ;
   posX+=20;
   i++;
}
i=0;

posX+=3;
iFilledCircle(posX,304,2);
iFilledCircle(posX,320,2);


 num_s=score;
posX+=20;
while(i<3)
{
  digit=num_s%10;
createEight(digit,posX+30,295,10);
num_s/=10;
posX-=18;
i++;
}
if(score>highScore)
screen=7;
}
void screen4()
{
   iSetColor(51,153,255);
      iFilledRectangle(0,0,1100,500);
            iSetColor(51,102,255);
      iFilledRectangle(350,100,150,70);
   iSetColor(255,255,255);
      iText(300,300,"use w & s to move paddle or press mouse left button and move it");
      iText(300,290,"p for pause ");
      iText(300,280,"r for resume or play again");
      iText(300,270,"q for quit");

         char s1[]="back";
    int i=0;
int  posX=350;
    while(s1[i]!='\0')
{

   text(s1[i],posX+4,110,20) ;
   posX+=30;
   i++;
}
}

void screen5()
{
       screen2();
      iSetColor(51,102,255);
      iFilledRectangle(350,100,150,70);
iSetColor(255,255,255);
char s[]="quit";
    int i=0;
int posX=350;
    while(s[i]!='\0')
{

   text(s[i],posX+4,110,20) ;
   posX+=30;
   i++;
}

   char s1[]="paused";
     i=0;
 posX=350;
    while(s1[i]!='\0')
{

   text(s1[i],posX+4,310,20) ;
   posX+=30;
   i++;
}
iText(350,250,"Press r to resume");
}


void gameOver()//screen=6
{
    screen3();
    char s[]="game ouer";
    int i=0;
int  posX=300;
    while(s[i]!='\0')
{
    if(s[i]=='i')
        text(s[i],posX+20,400,25) ;
    else
   text(s[i],posX,400,30) ;
   posX+=45;
   i++;
}

}

void youWin()//scr 8
{
    screen3();
    char s[]="you win";
    int i=0;
int  posX=300;
    while(s[i]!='\0')
{
    if(s[i]=='i')
        text(s[i],posX+20,400,25) ;
    else
   text(s[i],posX,400,30) ;
   posX+=40;
   i++;
}

}

void nHs() //screen 7
{
if(brickCheck()==1)
    youWin();
else
    gameOver();
 char s3[]="new high score";
int    i=0;

 int posX=300;
    while(s3[i]!='\0')
{

   text(s3[i],posX,350,13) ;
   posX+=20;
   i++;
}

highScore=score;
writeHighScore();

}

/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here
iClear();
if(screen==1)
   screen1();
   if(screen==2)
   screen2();
   if(screen==3)
   screen3();
   if(screen==4)
   screen4();
   if(screen==5)
    screen5();
  if(screen==6)
    gameOver();
  if(screen==7)

    nHs();
   if(screen==8)
     youWin();
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
if(screen==2&&mx<plateX+plateL/2&&mx>0)
    plateX-=25;
if(screen==2&&mx>plateX+plateL/2&&mx<1000-plateL/2)
    plateX+=25;
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    //cout<<mx<<" "<<my<<endl;
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&screen==1&&(mx>=350&&mx<=350+150)&&(my>=300&&my<=350+70))
	{
        screen=2;
	    cout<<"\a";
		//place your codes here
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&screen==4&&(mx>=350&&mx<=350+150)&&(my>=100&&my<=170))
	{
        screen=1;
	    cout<<"\a";
		//place your codes here
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&screen==5&&(mx>=350&&mx<=350+150)&&(my>=100&&my<=170))
	{
        screen=1;
        iResumeTimer(0);
        reset();
	    cout<<"\a";
		//place your codes here
	}
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&(screen==6||screen==7||screen==8)&&(mx>=200&&mx<=200+300)&&(my>=100&&my<=170))
	{
        screen=2;
        iResumeTimer(0);
        reset();
	    cout<<"\a";
		//place your codes here
	}
			if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&(screen==6||screen==7||screen==8)&&(mx>=550&&mx<=550+300)&&(my>=100&&my<=170))
	{
        screen=1;
        iResumeTimer(0);
        reset();
	    cout<<"\a";
		//place your codes here
	}
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&screen==1&&(mx>=350&&mx<=350+150)&&(my>=200&&my<=200+70))
	{
        screen=4;
	    cout<<"\a";
		//place your codes here
	}

	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if((key =='A'||key =='a')&&plateX>0)
	{
		plateX-=25;

	}
	if((key =='D'||key =='d')&&plateX<1000-120)
	{
		plateX+=25;
	}
	if(key=='s')
        iDelay(1000);
    if(key=='p' &&screen==2)
    {   screen=5;
        iPauseTimer(0);
    }
    if(key=='r')
    {
    screen=2;
    iResumeTimer(0);

    }
    if(key=='q'&&screen==2)
    {

        screen=1;
    reset();
    iResumeTimer(0);

    }
}

void iSpecialKeyboard(unsigned char key)
{


	//place your codes for other keys here
}

void ballChange(){
	ball_x += dbx;
	ball_y += dby;
    if((((ball_x>=plateX&&ball_x<=plateX+2)||(ball_x>=plateX+plateL-2&&ball_x<=plateX+plateL))&&ball_y<plateY+plateB)) dbx=-dbx,dby=-dby;
	else if(((ball_x>plateX+2&&ball_x<plateX-2+plateL)&&ball_y<plateY+plateB)) dby=-dby;
	else if(((ball_x>=plateX&&ball_x<=plateX)&&ball_y<plateY+plateB)) dby=-dby;



	if(ball_x>1000||ball_x<0) dbx=-dbx;
	if(ball_y>500)  dby= -dby;

}

int main()
{
	//place your own initialization codes here.
	iSetTimer(0, ballChange);
	dbx =10;
	dby = 3;
	iInitialize(1000,500 , "BRICKS BREAKER");

}

