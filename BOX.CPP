#include<graphics.h>
//#include<conio.h>

char d[9][2];
char a[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

int x,y;



void chtostr()
{
 char s[2];
 int count=0;
 for(int i=0;i<3;i++)
 {
  for(int j=0;j<3;j++)
  {
   s[0]=a[i][j];
   s[1]='\0';
   strcpy(d[count+j],s);
  }
  count+=3;
 }
}


void output()
{

 chtostr();

 x= getmaxx()/2-20;
 y =getmaxy()/2-40;


// cleardevice();
 setcolor(10);
 settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
 outtextxy(250,50,"X O GAME");
 setcolor(WHITE);


 for(int i=0;i<2;i++)
  for(int j=0;j<2;j++)
   rectangle( x+(i-1)*50 , y+(j-1)*50 , x+(i+1)*50 , y+(j+1)*50 );

 setcolor(RED);

 int k=0;
  for( i=0;i<3;i++)
   for( j=0;j<3;j++)
   {
   outtextxy(x+float(i-0.5)*55 , y+float(j-1)*55 ,d[k++]);
   }

}

int select()
{

 output();

 char a,gett;
 int grap,countv=1,counth=1;
 int ax,by;
 ax=x-50;
 by=y-50;
 grap=50;


  while(1)
 {
  int k=0;


  for(int  i=0;i<3;i++)
   for(int  j=0;j<3;j++)
   {
   outtextxy(x+float(i-0.5)*55 , y+float(j-1)*55 ,d[k++]);
   }

 a=getch();
 if(a!=(char)13)
  gett=getch();

 else
 {
  int c= countv+3*(counth-1);
	switch(c)
			{
				case 7:	return 1;
				case 8:	return 2;
				case 9: return 3;
				case 4: return 4;
				case 5:	return 5;
				case 6:	return 6;
				case 1: return 7;
				case 2: return 8;
				case 3:	return 9;
			 }
 }
  setcolor(WHITE);
  rectangle( ax , by , ax+50 , by+50 );

 if(gett=='H')
 {

  by-=grap;
  countv--;
  if(countv<=0)
  {
   by=y+50;
   countv=3;
  }
  setcolor(RED);
  rectangle( ax , by , ax+50 , by+50 );
 }
 else if(gett=='P')
 {

  by+=grap;
  countv++;
  if(countv>3)
  {
   by=y-50;
   countv=1;
  }
  setcolor(RED);
  rectangle( ax , by , ax+50 , by+50 );
 }
 else if(gett=='K')
 {

  ax-=grap;
  counth--;
  if(counth<=0)
  {
   ax=x+50;
   counth=3;
  }
  setcolor(RED);
  rectangle( ax , by , ax+50 , by+50 );
 }
 else if(gett=='M')
 {
  ax+=grap;
  counth++;
  if(counth>3)
  {
   ax=x-50;
   counth=1;
  }
  setcolor(RED);
  rectangle( ax , by , ax+50 , by+50 );
 }
}
}