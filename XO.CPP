#include <iostream.h>
#include <stdlib.h>
//#include <cstdlib>
//#include <ctime>
#include<dos.h>
#include<string.h>
#include<stdlib.h>
//using namespace std;
#include<conio.h>
#include"box.cpp"
#include"arw.cpp"
int i,j,count=0,c,choic,dum;
char q[9]={'x','o','x','o','x','o','x','o','x'},*b=&q[0],*p=&a[0][0];
char ch;

void s_input_p();
void s_input_h();
void s_input_m();
void s_input_e();
void m_input();
int ae_check(char ,int);
int ah_check(char,int);
int am_check(char,int);
int ap_check(char,int);
int r_check();
int p_check(int);
void pl_check();
void pro_check();
void output();
int rand_int();
void toss(int);
int conv(char);

int main(){
	char pl;
	ag:
	for(int z=0;z<3;z++)
		for(int s=0;s<3;s++)
				a[z][s]=' ';
				b=&q[0];

	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\Turboc3\\BGI");

	count =0;

	u:
	cleardevice();
	ch=toggle(3,1);

     //	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
     //	cout << " Menu \n 1.Single Player \n 2.Multi Player \n ";
     //	ch = getch();
    //	choic = ch -'0';
    //	clrscr();

//	output();
	if (ch == 1)
	{
		j:
			cleardevice();
		      //	cout<<" Menu \n 1.Easy \n 2.Moderate \n 3.Hard \n 4.Professional  \n";
		      //	cout << "\n After Selecting the type of game you will take toss";
			ch = toggle(5,2);
		      //	choic = ch -'0';
			cleardevice();
			if ( ch ==1 )
				s_input_e();

			else if ( ch == 2)
				s_input_m();

			else if ( ch == 3)
				s_input_h();

			else if ( ch == 4)
				s_input_p();

			else
			   goto u;

		       //	else
			//{
			 //	cout<<"\nWrong Input";
			 //	goto j;
			//}
	}
	else if(ch==2)
	{
		cleardevice();
		m_input();
	}

	else
		exit(0);



	plc:

	if(dum==1)
	{
		output();
		getch();
		cleardevice();
		cout<<"\n******Match is Draw*******";
	}

	cout<<"\n Do you want to play another game(y/n)";
	cin>>pl;
	if(pl=='y'||pl=='Y')
		goto ag;
	else if(pl =='n'||pl=='N')
	{
		cout<<"Thanks for playing";
		getch();
		closegraph();
		exit(0);
	}
	else
	{
		cout<<"\nInvalid option";
		goto plc;
	}

	closegraph();
}
int rand_int(){
    srand((unsigned)time(0));
    int random_integer;
    random_integer = (rand()%10)+1;
		return random_integer;

}
/*void output(){
       //	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	 clrscr();
	cout << "     |     |     \n";
	cout << "  " << a[0][0] << "  |  " << a[0][1] << "  |  " << a[0][2] << "\n";

	cout << "_____|_____|_____\n";
	cout << "     |     |     \n";

	cout << "  " << a[1][0] << "  |  " << a[1][1] << "  |  " << a[1][2] << "\n";

	cout << "_____|_____|_____\n";
	cout << "     |     |     \n" ;

	cout << "  " << a[2][0] << "  |  " << a[2][1] << "  |  " << a[2][2] << "\n";

       //	cout << "     |     |     \n\n\n\n\n\n\n\n\n\n" ;
} */
void s_input_e(){
	toss(1);
	for(int k=0;k<9;k++)
	{
		ip:
			if( count % 2 == 0)
			{
				//ch = getch();
				j = select();

				if ( j < 4)
						c=p_check(j+5);
				else if(j<7)
						c=p_check(j-1);
				else if (j<10)
						c=p_check(j-7);


				if ( c == 1)
				{
					outtextxy(200,400,"Position Already Ocupied");
					goto ip;
				}
				else
					count++;
			}
			else
			{
				j=ae_check(*b,0);
				if ( j == 0 )
				{
					count++;
					output();
					dum=r_check();
					if(dum==0)
					 break;
					b++;
					continue;
				}
				else
				{
					c=1;
					count++;
				}
			}
			switch(j)
			{
				case 1:	a[0][0]=*b;break;
				case 2:	a[0][1]=*b;break;
				case 3: a[0][2]=*b;break;
				case 4: a[1][0]=*b;break;
				case 5:	a[1][1]=*b;break;
				case 6:	a[1][2]=*b;break;
				case 7:	a[2][0]=*b;break;
				case 8: a[2][1]=*b;break;
				case 9:	a[2][2]=*b;break;
			}

			output();
			dum=r_check();
			if(dum==0)
			 break;
			if ( c == 1 )
				b++;
			else
				b++;
	}
}
void s_input_m()
{
	toss(2);
	for(int k=0;k<9;k++)
	{
		ip:
			if( count % 2 == 0)
			{
			       //	ch = getch();
				j = select();
				if ( j < 4)
						c=p_check(j+5);
				else if(j<7)
						c=p_check(j-1);
				else if (j<10)
						c=p_check(j-7);

				if ( c == 1)
				{
					outtextxy(200,400,"Position Already Ocupied");
					goto ip;
				}
				else
					count++;
			}
			else
			{
				j=am_check(*b,0);
				if ( j == 0 )
				{
					count++;
					output();
					dum=r_check();
					if(dum==0)
					 break;
					b++;
					continue;
				}
				else
				{
					c=1;
					count++;
				}
			}
			switch(j)
			{
				case 7:	a[0][0]=*b;break;
				case 8:	a[0][1]=*b;break;
				case 9: a[0][2]=*b;break;
				case 4: a[1][0]=*b;break;
				case 5:	a[1][1]=*b;break;
				case 6:	a[1][2]=*b;break;
				case 1:	a[2][0]=*b;break;
				case 2: a[2][1]=*b;break;
				case 3:	a[2][2]=*b;break;
			}
			output();
			dum=r_check();
			if(dum==0)
			 break;
			if ( c == 1 )
				b++;
			else
				b++;
	}
}
void s_input_h(){
	toss(3);
	for(int k=0;k<9;k++)
	{
		ip:
			if( count % 2 == 0)
			{
			       //	ch = getch();
				j = select();
				if ( j < 4)
						c=p_check(j+5);
				else if(j<7)
						c=p_check(j-1);
				else if (j<10)
						c=p_check(j-7);


				if ( c == 1)
				{
					outtextxy(200,400, "Position Already Ocupied");
					goto ip;
				}
				else
					count++;
			}
			else
			{
				ah_check(*b,0);
				count++;
				output();
				dum=r_check();
				if(dum==0)
				 break;
				b++;
				continue;
			}
			switch(j)
			{	case 7:	a[0][0]=*b;break;
				case 8:	a[0][1]=*b;break;
				case 9: a[0][2]=*b;break;
				case 4: a[1][0]=*b;break;
				case 5:	a[1][1]=*b;break;
				case 6:	a[1][2]=*b;break;
				case 1:	a[2][0]=*b;break;
				case 2: a[2][1]=*b;break;
				case 3:	a[2][2]=*b;break;
			}
			output();
			dum=r_check();
			if(dum==0)
			 break;
			b++;

	}
}
void s_input_p(){
	toss(4);
	for(int k=0;k<9;k++)
	{
		ip:
			if( count % 2 == 0)
			{
			       //	cin>>ch;
				j = select();
				if ( j < 4)
						c=p_check(j+5);
				else if(j<7)
						c=p_check(j-1);
				else if (j<10)
						c=p_check(j-7);

				if ( c == 1)
				{
					outtextxy(200,400,"Position Already Ocupied");
					goto ip;
				}
				else
					count++;
			}
			else
			{
				ap_check(*b,0);
				count++;
				output();
				dum=r_check();
				if(dum==0)
				 break;
				b++;
				continue;
			}
			switch(j)
			{
				case 7:	a[0][0]=*b;break;
				case 8:	a[0][1]=*b;break;
				case 9: a[0][2]=*b;break;
				case 4: a[1][0]=*b;break;
				case 5:	a[1][1]=*b;break;
				case 6:	a[1][2]=*b;break;
				case 1:	a[2][0]=*b;break;
				case 2: a[2][1]=*b;break;
				case 3:	a[2][2]=*b;break;
			}
			output();
			dum=r_check();
			if(dum==0)
			 break;
			b++;
	}
}
void m_input(){

	for(int k=0;k<9;k++)
	{

		output();
		ip:
			       //	ch = getch();
				j = select();
				if ( j < 4)
						c=p_check(j+5);
				else if(j<7)
						c=p_check(j-1);
				else if (j<10)
						c=p_check(j-7);

				if ( c == 1)
				{
					while(!kbhit())
				      {
				 outtextxy(200,400,"Position Already Ocupied");
					}
					cleardevice();
					output();
					goto ip;
				}

			       //	count++;
			       //	b++;

			switch(j)
			{
				case 7:	a[0][0]=*b;break;
				case 8:	a[0][1]=*b;break;
				case 9: a[0][2]=*b;break;
				case 4: a[1][0]=*b;break;
				case 5:	a[1][1]=*b;break;
				case 6:	a[1][2]=*b;break;
				case 1:	a[2][0]=*b;break;
				case 2: a[2][1]=*b;break;
				case 3:	a[2][2]=*b;break;
			}
			output();
			count++;
			b++;
		dum=r_check();
			if(dum==0)
			 break;
	}
}
int p_check(int l){
	if(*(p+l) == ' ')
		return 0;
	else
		return 1;
}

void win_disp()
{
	char player[2];
	if(*b=='x')
		 strcpy(player,"X");
	else
		 strcpy(player,"Y");

	output();
	getch();
	cleardevice();
	cout<<player<<" won the game";
	getch();
}

int r_check()
{
	for(int i=0;i<3;i++)
	{
		if(a[i][0]==*b &&a[i][1]==*b &&a[i][2]==*b )
		{
			win_disp();
			return 0;

		}
		if(a[0][i]==*b &&a[1][i]==*b &&a[2][i]==*b )
		{
			win_disp();
			return 0;

		}
	}

	if(a[0][0]==*b &&a[1][1]==*b &&a[2][2]==*b )
	{
		win_disp();
		return 0;
	}
	if(a[2][0]==*b &&a[1][1]==*b &&a[0][2]==*b )
	{
		win_disp();
		return 0;
	}
	return 1;
}
int ah_check( char w , int f )
{
	for ( int i = 0 ; i < 3 ; i++ )
	{
		if ( (a[i][0] == w)&&(a[i][1] == w )&&(a[i][2] == ' ') )
		{
			a[i][2] = *b;
			return 0;
		}
		if ( (a[i][0] == w)&&(a[i][2] == w )&&(a[i][1] == ' ') )
		{
			a[i][1] = *b;
			return 0;
		}
		if ( (a[i][2] == w)&&(a[i][1] == w )&&(a[i][0] == ' ') )
		{
			a[i][0] = *b;
			return 0;
		}
		if ( (a[0][i] == w)&&(a[1][i]== w )&&(a[2][i]) == ' ' )
		{
			a[2][i]=*b;
			return 0;
		}
		if ( (a[0][i] == w)&&(a[2][i]== w )&&(a[1][i]) == ' ' )
		{
			a[1][i]=*b;
			return 0;
		}
		if ( (a[2][i] == w)&&(a[1][i]== w )&&(a[0][i]) == ' ' )
		{
			a[0][i]=*b;
			return 0;
		}
	}
	if ( (a[1][1] == w )&& (a[2][2] == w )&&(a[0][0] == ' '))
	{
		a[0][0]=*b;
		return 0;
	}
	if ( (a[0][0] == w )&& (a[2][2] == w )&&(a[1][1] == ' '))
	{
		a[1][1]=*b;
		return 0;
	}
	if ( (a[1][1] == w )&& (a[0][0] == w )&&(a[2][2] == ' '))
	{
		a[2][2]=*b;
		return 0;
	}
	if ( (a[2][0] == w )&& (a[1][1] == w) && (a[0][2] == ' '))
	{
		a[0][2]=*b;
		return 0;
	}
	if ( (a[2][0] == w )&& (a[0][2] == w) && (a[1][1] == ' '))
	{
		a[1][1]=*b;
		return 0;
	}
	if ( (a[0][2] == w )&& (a[1][1] == w) && (a[2][0] == ' '))
	{
		a[2][0]=*b;
		return 0;
	}
	if ( f == 0 )
		ah_check(*(b+1),1);
	else
		pl_check();
}
int am_check( char w , int f ){
	for ( int i = 0 ; i < 3 ; i++ )
	{
		if ( (a[i][0] == w)&&(a[i][1] == w )&&(a[i][2] == ' ') )
		{
			a[i][2] = *b;
			return 0;
		}
		if ( (a[i][0] == w)&&(a[i][2] == w )&&(a[i][1] == ' ') )
		{
			a[i][1] = *b;
			return 0;
		}
		if ( (a[i][2] == w)&&(a[i][1] == w )&&(a[i][0] == ' ') )
		{
			a[i][0] = *b;
			return 0;
		}
		if ( (a[0][i] == w)&&(a[1][i]== w )&&(a[2][i]) == ' ' )
		{
			a[2][i]=*b;
			return 0;
		}
		if ( (a[0][i] == w)&&(a[2][i]== w )&&(a[1][i]) == ' ' )
		{
			a[1][i]=*b;
			return 0;
		}
		if ( (a[2][i] == w)&&(a[1][i]== w )&&(a[0][i]) == ' ' )
		{
			a[0][i]=*b;
			return 0;
		}
	}
	if ( (a[1][1] == w )&& (a[2][2] == w )&&(a[0][0] == ' '))
	{
		a[0][0]=*b;
		return 0;
	}
	if ( (a[0][0] == w )&& (a[2][2] == w )&&(a[1][1] == ' '))
	{
		a[1][1]=*b;
		return 0;
	}
	if ( (a[1][1] == w )&& (a[0][0] == w )&&(a[2][2] == ' '))
	{
		a[2][2]=*b;
		return 0;
	}
	if ( (a[2][0] == w )&& (a[1][1] == w) && (a[0][2] == ' '))
	{
		a[0][2]=*b;
		return 0;
	}
	if ( (a[2][0] == w )&& (a[0][2] == w) && (a[1][1] == ' '))
	{
		a[1][1]=*b;
		return 0;
	}
	if ( (a[0][2] == w )&& (a[1][1] == w) && (a[2][0] == ' '))
	{
		a[2][0]=*b;
		return 0;
	}
	if ( f == 0 )
		am_check(*(b-1),1);
	else
		{
			i:
				j = rand_int();
				if ( j < 4)
						c=p_check(j+5);
				else if(j<7)
						c=p_check(j-1);
				else if (j<10)
						c=p_check(j-7);
				else
						goto i;
				if ( c == 1)
					goto i;
				else
						return j;
		}
}
int ae_check( char w , int f ){
	for ( int i = 0 ; i < 3 ; i++ )
	{
		if ( (a[i][0] == w)&&(a[i][1] == w )&&(a[i][2] == ' ') )
		{
			a[i][2] = *b;
			return 0;
		}
		if ( (a[i][0] == w)&&(a[i][2] == w )&&(a[i][1] == ' ') )
		{
			a[i][1] = *b;
			return 0;
		}
		if ( (a[i][2] == w)&&(a[i][1] == w )&&(a[i][0] == ' ') )
		{
			a[i][0] = *b;
			return 0;
		}
		if ( (a[0][i] == w)&&(a[1][i]== w )&&(a[2][i]) == ' ' )
		{
			a[2][i]=*b;
			return 0;
		}
		if ( (a[0][i] == w)&&(a[2][i]== w )&&(a[1][i]) == ' ' )
		{
			a[1][i]=*b;
			return 0;
		}
		if ( (a[2][i] == w)&&(a[1][i]== w )&&(a[0][i]) == ' ' )
		{
			a[0][i]=*b;
			return 0;
		}
	}
	if ( (a[1][1] == w )&& (a[2][2] == w )&&(a[0][0] == ' '))
	{
		a[0][0]=*b;
		return 0;
	}
	if ( (a[0][0] == w )&& (a[2][2] == w )&&(a[1][1] == ' '))
	{
		a[1][1]=*b;
		return 0;
	}
	if ( (a[1][1] == w )&& (a[0][0] == w )&&(a[2][2] == ' '))
	{
		a[2][2]=*b;
		return 0;
	}
	if ( (a[2][0] == w )&& (a[1][1] == w) && (a[0][2] == ' '))
	{
		a[0][2]=*b;
		return 0;
	}
	if ( (a[2][0] == w )&& (a[0][2] == w) && (a[1][1] == ' '))
	{
		a[1][1]=*b;
		return 0;
	}
	if ( (a[0][2] == w )&& (a[1][1] == w) && (a[2][0] == ' '))
	{
		a[2][0]=*b;
		return 0;
	}
	i:
		j = rand_int();
		if ( j < 4)
			c=p_check(j+5);
		else if(j<7)
			c=p_check(j-1);
		else if (j<10)
		c=p_check(j-7);
		else
			goto i;
		if ( c == 1)
			goto i;
		else
			return j;
}
int ap_check( char w , int f ){
	for ( int i = 0 ; i < 3 ; i++ )
	{
		if ( (a[i][0] == w)&&(a[i][1] == w )&&(a[i][2] == ' ') )
		{
			a[i][2] = *b;
			return 0;
		}
		if ( (a[i][0] == w)&&(a[i][2] == w )&&(a[i][1] == ' ') )
		{
			a[i][1] = *b;
			return 0;
		}
		if ( (a[i][2] == w)&&(a[i][1] == w )&&(a[i][0] == ' ') )
		{
			a[i][0] = *b;
			return 0;
		}
		if ( (a[0][i] == w)&&(a[1][i]== w )&&(a[2][i]) == ' ' )
		{
			a[2][i]=*b;
			return 0;
		}
		if ( (a[0][i] == w)&&(a[2][i]== w )&&(a[1][i]) == ' ' )
		{
			a[1][i]=*b;
			return 0;
		}
		if ( (a[2][i] == w)&&(a[1][i]== w )&&(a[0][i]) == ' ' )
		{
			a[0][i]=*b;
			return 0;
		}
	}
	if ( (a[1][1] == w )&& (a[2][2] == w )&&(a[0][0] == ' '))
	{
		a[0][0]=*b;
		return 0;
	}
	if ( (a[0][0] == w )&& (a[2][2] == w )&&(a[1][1] == ' '))
	{
		a[1][1]=*b;
		return 0;
	}
	if ( (a[1][1] == w )&& (a[0][0] == w )&&(a[2][2] == ' '))
	{
		a[2][2]=*b;
		return 0;
	}
	if ( (a[2][0] == w )&& (a[1][1] == w) && (a[0][2] == ' '))
	{
		a[0][2]=*b;
		return 0;
	}
	if ( (a[2][0] == w )&& (a[0][2] == w) && (a[1][1] == ' '))
	{
		a[1][1]=*b;
		return 0;
	}
	if ( (a[0][2] == w )&& (a[1][1] == w) && (a[2][0] == ' '))
	{
		a[2][0]=*b;
		return 0;
	}
	if ( f == 0 )
		ap_check(*(b+1),1);
	else
		pro_check();
}
void pl_check(){
	if ( a[1][1] == ' ' )
	{
		a[1][1] = *b;
	}
	else if ( a[2][1] == ' ')
	{
		a[2][1] = *b;
	}
	else if ( a[2][0] == ' ')
	{
		a[2][0] = *b;
	}
	else if(a[1][0]==' ')
	{
		a[1][0]=*b;
	}
	else if(a[2][2]==' ')
	{
		a[2][2]=*b;
	}
}
void pro_check(){
	if(a[2][2]=='o')
	{
		if ( a[1][1] == ' ' )
			a[1][1] = *b;
		else if ( a[2][1] == ' ')
			a[2][1] = *b;
		else if ( a[1][0] == ' ')
			a[1][0] = *b;
		else if(a[2][0]==' ')
			a[2][0]=*b;
		else if(a[2][2]==' ')
			a[2][2]=*b;
	}
	else
	{
		if ( a[1][1] == ' ' )
			a[1][1] = *b;
		else if ( a[2][1] == ' ')
			a[2][1] = *b;
		else if ( a[2][0] == ' ')
			a[2][0] = *b;
		else if(a[1][0]==' ')
			a[1][0]=*b;
		else if(a[2][2]==' ')
			a[2][2]=*b;
	}
}
void toss(int j)
{
	char choice[10];

	cleardevice();

	cout<<"\nenter heads or tails...\n";
	cin>>choice;

	for(int i=0;i<50;i++)
	{
		if(i%2==0 )
			cout<<(char)8<<"T";

		else
			cout<<(char)8<<"H";

		if(i<40)
			delay(2+5*i);
		else
			delay(10*i);
	}

	if(j==4)
	{
		if(strcmpi(choice,"heads")==0)
			cout<<(char)8<<"T";

		else
			cout<<(char)8<<"H";

		count = 1;
	 }

	 else if(j==1)
	 {
		int a=rand_int();

		if(a==9 || a==8)
		{
			 if(strcmpi(choice,"heads") == 0)
				cout<<(char)8<<"T";

			 else
				cout<<(char)8<<"H";


			count = 1;
		}

		else
		{
			if(strcmpi(choice,"heads")==0)
				cout<<(char)8<<"H";

			else
				cout<<(char)8<<"T";


			count = 0;
		}
	}

	else if(j==2)
	{
		int a=rand_int();

		if(a==9|| a==8 ||a==7 ||a==6 ||a==5)
		{
			if(strcmpi(choice,"heads")==0)
				cout<<(char)8<<"T";

			else
				cout<<(char)8<<"H";

			count = 1;
		}

		else
		{

			if(strcmpi(choice,"heads")==0)
				cout<<(char)8<<"H";

			else
				cout<<(char)8<<"T";

			count = 0;
		}
	 }

	 else if(j==3)
	 {
		int a=rand_int();

		if(a==9|| a==8)
		{
			if(strcmpi(choice,"heads")==0)
				cout<<(char)8<<"H";

			else
				cout<<(char)8<<"T";


			count = 0 ;
		}

		else
		{
			if(strcmpi(choice,"heads")==0)
				cout<<(char)8<<"T";

			else
				cout<<(char)8<<"H";

			count = 1;

		}
	 }

	 else
		cout<<"invalid input";

	if(count==0)
		cout<<"\nuser starts the game with X";

	else
		cout<<"\ncomputer starts the game with X";

	cout<<"\n\npress any key to continue";
	choic = getch();
	cleardevice();
}

int conv(char a)
{
	if(a=='q'||a=='Q')
		return 7;
	else
	if(a=='w'||a=='W')
		return 8;
	else
	if(a=='e'||a=='E')
		return 9;
	else
	if(a=='a'||a=='A')
		return 4;
	else
	if(a=='s'||a=='S')
		return 5;
	else
	if(a=='d'||a=='D')
		return 6;
	else
	if(a=='z'||a=='Z')
		return 1;
	else
	if(a=='x'||a=='X')
		return 2;
	else
	if(a=='c'||a=='C')
		return 3;

}
