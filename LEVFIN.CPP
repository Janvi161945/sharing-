#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>

class snakenode
{
	public :
		int x1,y1,x2,y2,dir;
		snakenode* next,* prev;
};

class snake
{
       private :
		void snake_up();
		void snake_down();
		void snake_left();
		void snake_right();
		void level_one();
		void level_two();
		void level_three();
		int score;
       public :
		snakenode* head,* tail;
		char *t;
		int obs[10][2];
		int i,j;
		int food_x,food_y,window_x1,window_y1,window_x2,window_y2;

		snake()
		{
			head=tail=NULL;
			window_x1=20;
			window_y1=20;
			window_x2=590;
			window_y2=450;
			score=0;
			for(i=0;i<10;i++)
			{
				for(j=0;j<2;j++)
					obs[i][j]=0;
			}
		}
		void drawsnake();
		void game(int);
		void move(int);
		void insert();
		void display(int);
		void fruit();
		void startmenu();

};

void snake::display(int lno)
{
	int p,q;
	snakenode* curr=head;
	while(curr!=NULL)
	{
		rectangle(curr->x1,curr->y1,curr->x2,curr->y2);
		curr=curr->next;
	}
	rectangle(590,20,633,100);
	settextstyle(0,0,0);
	outtextxy(595,25,"SCORE");
	itoa(score,t,10);
	settextstyle(3,0,3);
	outtextxy(610,40,t);
       if(lno == 0)
	return ;
       if(lno==1)
		level_one();
       if(lno==2)
		level_two();
       if(lno==3)
		level_three();

}
void snake::level_one()
{
	   obs[0][0]=70;
	   obs[0][1]=50;
	   obs[1][0]=170;
	   obs[1][1]=50;
	   obs[2][0]=400;
	   obs[2][1]=100;
	   obs[3][0]=400;
	   obs[3][1]=300;
	   line(obs[0][0],obs[0][1],obs[1][0],obs[1][1]);
	   line(obs[2][0],obs[2][1],obs[3][0],obs[3][1]);
	   outtextxy(100,450,"LEVEL 1");
}
void snake::level_two()
{
	   obs[0][0]=70;
	   obs[0][1]=50;
	   obs[1][0]=170;
	   obs[1][1]=50;
	   obs[2][0]=400;
	   obs[2][1]=100;
	   obs[3][0]=400;
	   obs[3][1]=300;
	   obs[4][0]=200;
	   obs[4][1]=250;
	   obs[5][0]=420;
	   obs[5][1]=250;
	   line(obs[4][0],obs[4][1],obs[5][0],obs[5][1]);
	   line(obs[0][0],obs[0][1],obs[1][0],obs[1][1]);
	   line(obs[2][0],obs[2][1],obs[3][0],obs[3][1]);
	   outtextxy(100,450,"LEVEL 2");
}
void snake::level_three()
{
	   obs[0][0]=70;
	   obs[0][1]=50;
	   obs[1][0]=170;
	   obs[1][1]=50;
	   obs[2][0]=400;
	   obs[2][1]=100;
	   obs[3][0]=400;
	   obs[3][1]=300;
	   obs[4][0]=200;
	   obs[4][1]=250;
	   obs[5][0]=420;
	   obs[5][1]=250;
	   obs[6][0]=200;
	   obs[6][1]=180;
	   obs[7][0]=200;
	   obs[7][1]=380;
	   line(obs[6][0],obs[6][1],obs[7][0],obs[7][1]);
	   line(obs[4][0],obs[4][1],obs[5][0],obs[5][1]);
	   line(obs[0][0],obs[0][1],obs[1][0],obs[1][1]);
	   line(obs[2][0],obs[2][1],obs[3][0],obs[3][1]);
	   outtextxy(100,450,"LEVEL 3");
}
void snake::drawsnake()
{
	rectangle(window_x1,window_y1,window_x2,window_y2);
	head=new snakenode;
	head->x1=100;
	head->y1=100;
	head->x2=110;
	head->y2=110;
	head->dir=2;
	head->next=head->prev=NULL;
	tail=head;
	rectangle(head->x1,head->y1,head->x2,head->y2);
	insert();
	insert();
	insert();
	display(0);
}
void snake::startmenu()
{
	char start,level;
	cleardevice();
	settextstyle(4,0,9);
	outtextxy(20,20,"SNAKE");
	rectangle(20,140,400,400);
	settextstyle(1,0,4);
	outtextxy(150,170,"s. Start");
	outtextxy(150,220,"c. Choose Level");
	outtextxy(150,270,"q. QUIT");
	start=getch();
	if(start=='s')
	{
		cleardevice();
		drawsnake();
		game(0);
	}
	if(start=='c')
	{
		cleardevice();
		rectangle(20,140,400,400);
		settextstyle(1,0,4);
		outtextxy(150,170,"i. LEVEL 1");
		outtextxy(150,220,"o. LEVEL 2");
		outtextxy(150,270,"p. LEVEL 3");
		level=getch();
		if(level=='i')
		{
			cleardevice();
			drawsnake();
			game(1);
		}
		if(level=='o')
		{
			cleardevice();
			drawsnake();
			game(2);
		}
		if(level=='p')
		{
			cleardevice();
			drawsnake();
			game(3);
		}


	}
	if(start=='q')
	{
		cleardevice();
		outtextxy(100,100,"Exiting..");
		closegraph();
	}
}
void snake::insert()
{
	snakenode* curr;
	curr=new snakenode;
	curr->next=curr->prev=NULL;
	if(tail->dir==0)
	{
		curr->x1=tail->x1;
		curr->y1=tail->y1+10;
		curr->x2=tail->x2;
		curr->y2=tail->y2+10;
		curr->dir=0;
	}
	if(tail->dir==1)
	{
		curr->x1=tail->x1;
		curr->y1=tail->y1-10;
		curr->x2=tail->x2;
		curr->y2=tail->y2-10;
		curr->dir=1;
	}
	if(tail->dir==2)
	{
		curr->x1=tail->x1-10;
		curr->y1=tail->y1;
		curr->x2=tail->x2-10;
		curr->y2=tail->y2;
		curr->dir=2;
	}
	if(tail->dir==3)
	{
		curr->x1=tail->x1+10;
		curr->y1=tail->y1;
		curr->x2=tail->x2+10;
		curr->y2=tail->y2;
		curr->dir=3;
	}
	curr->prev=tail;
	tail->next=curr;
	tail=curr;
}

void snake::fruit()
{
	food_x=(rand()%30)*10+100;
	food_y=(rand()%30)*10+100;
}

void snake::game(int lno)
{
	int i=2,food=0,collision=0;
	char g,*p;
	snakenode* curr;
	int k,l;
	char ch,s;
	score=0;
	while(1)
	{

			setlinestyle(3,1,4);
			rectangle(window_x1,window_y1,window_x2,window_y2);
			setlinestyle(0,0,0);
			if(food==0)
			{
				fruit();
				food=1;
			}
			if((abs(head->x1-food_x)==0 || abs(head->x2-food_x)==0) && ( abs(head->y1-food_y)==0 || abs(head->y1-food_y)==0))
			{
				score++;
				food=0;
				insert();
			}
			if(head->x1==window_x1 || head->x2==window_x2 || head->y1==window_y1 || head->y2==window_y2)
			{
				collision=1;
			}
			curr=head->next;
			while(curr!=NULL)
			{
				if(abs(head->x1-curr->x1)<=5 && abs(head->y1-curr->y1)<=5)
				{
					collision=1;
					break;
				}
				curr=curr->next;
			}
			k=0,l=0;
			while(obs[k][0]!=0&&lno!=0)
			{
				l=k+1;
				if((head->x1>=obs[k][0])&&(head->y2>=obs[k][1])&&(head->x1<=obs[l][0])&&(head->y2<=obs[l][1]))
				{
					collision=1;
					break;
				}
				k++;
			}
			if(collision==1)
			{
				settextstyle(1,0,3);
				cleardevice();
				outtextxy(220,200,"GAME OVER");
				settextstyle(1,0,1);
				outtextxy(220,230,"SCORE = ");
				outtextxy(300,230,t);
				outtextxy(220,250,"Press R to Restart");
				outtextxy(220,270,"Press Q to Quit");
				g=getch();
				if(g=='r')
				     startmenu();
				else
					break;
			}
			if(kbhit())
			{
				ch=getch();
				if(ch=='w')
				i=0;
				else if(ch=='s')
				i=1;
				else if(ch=='d')
				i=2;
				else if(ch=='a')
				i=3;
				else if (ch=='q')
				{
					cleardevice();
					outtextxy(100,100,"Exiting..");
					break;
				}
				else if(ch=='r')
				{
					cleardevice();
					startmenu();
				}
			}
			else
			move(i);
			if(food==1)
			rectangle(food_x,food_y,food_x+10,food_y+10);
			delay(200);
			cleardevice();
			display(lno);


	}
}
void snake::move(int i)
{
	if(i==0)
	{
	  snake_up();
	}
	if(i==1)
	{
	  snake_down();
	}
	if(i==2)
	{
	  snake_right();
	}
	if(i==3)
	{
	  snake_left();
	}
}
void snake::snake_up()
{
	snakenode* curr,* del;
	curr=new snakenode;
	curr->next=curr->prev=NULL;
	curr->x1=head->x1;
	curr->y1=head->y1-10;
	curr->x2=head->x2;
	curr->y2=head->y2-10;
	curr->dir=0;
	curr->next=head;
	head->prev=curr;
	head=curr;
	del=tail;
	tail=tail->prev;
	delete(del);
	tail->next=NULL;
}
void snake::snake_down()
{
		snakenode* curr,* del;
	curr=new snakenode;
	curr->next=curr->prev=NULL;
	curr->x1=head->x1;
	curr->y1=head->y1+10;
	curr->x2=head->x2;
	curr->y2=head->y2+10;
	curr->dir=0;
	curr->next=head;
	head->prev=curr;
	head=curr;
	del=tail;
	tail=tail->prev;
	delete(del);
	tail->next=NULL;
}
void snake::snake_left()
{
	snakenode* curr,* del;
	curr=new snakenode;
	curr->next=curr->prev=NULL;
	curr->x1=head->x1-10;
	curr->y1=head->y1;
	curr->x2=head->x2-10;
	curr->y2=head->y2;
	curr->dir=0;
	curr->next=head;
	head->prev=curr;
	head=curr;
	del=tail;
	tail=tail->prev;
	delete(del);
	tail->next=NULL;
}
void snake::snake_right()
{
	snakenode* curr,* del;
	curr=new snakenode;
	curr->next=curr->prev=NULL;
	curr->x1=head->x1+10;
	curr->y1=head->y1;
	curr->x2=head->x2+10;
	curr->y2=head->y2;
	curr->dir=0;
	curr->next=head;
	head->prev=curr;
	head=curr;
	del=tail;
	tail=tail->prev;
	delete(del);
	tail->next=NULL;
}

void main()
{       char start;
	snake s;
	int gd,gm;
	gd=DETECT;
	initgraph(&gd,&gm,"..\\Bgi");
	s.startmenu();
	closegraph();
}