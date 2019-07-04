//#include<graphics.h>
//#include<conio.h>
//#include<iostream.h>

char plr[][25]={"single player","multiplayer","EXIT"};
char dif[][25]={"easy","moderate","hard","professional","back"};
int ax1,by1,var,stop=0,cnt;

void arrow(int cycles,int grap)
{

 char a,gett;

while(1)
{

 a=getch();
 if(a!=(char)13)
  gett=getch();
 else
 {
  stop=1;
  break;
 }
 if(grap!=0)
 grap=40;

 if(gett=='H')
 {
  if(grap==0)
   by1--;
  else
   by1-=grap;
  cnt--;
  if(cnt<=0)
  {
   if(grap==0)
    by1+=cycles;
   else
    by1=(cycles*grap)+var-40;
   cnt=cycles;
  }
  if(grap==0)
   gotoxy(ax1,by1);
  else
   moveto(ax1,by1);
  stop=0;
 }
 else if(gett=='P')
 {
  if(grap==0)
   by1++;
  else
   by1+=grap;
  cnt++;
  if(cnt>cycles)
  {
   if(grap==0)
    by1-=cycles;
   else
    by1=var;
   cnt=1;
  }
  if(grap==0)
   gotoxy(ax1,by1);
  else
   moveto(ax1,by1);
  stop=0;
  }
 break;
 }

}


int toggle(int num,int page)
{
// int gd=DETECT, gm;
// initgraph(&gd,&gm,"C:\\Turboc3\\BGI");

 char temp[10][25];

 if(page==1)
   for(int i=0;i<num;i++)
    strcpy(temp[i],plr[i]);

 else
  for(int i=0;i<num;i++)
   strcpy(temp[i],dif[i]);


 ax1=150;
 cnt=1;
 by1=getmaxy()/2-num*25;
 var=by1;

 b:
 {

 cleardevice();
 setcolor(GREEN);
 rectangle(0,0,getmaxx(),getmaxy());
 rectangle(30,30,getmaxx()-30,getmaxy()-30);
 for(int i=0;i<num;i++)
 {
  moveto(250,i*40+var);
  if((by1-var)/40==i)
  {
   setcolor(RED);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
   outtext(temp[i]);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
  }
  else
  {
   setcolor(YELLOW);
   outtext(temp[i]);
  }
 }



 moveto(ax1-1,by1);

 arrow(num,1);

 if(stop==0)
  goto b;
}

for(i=0;i<num;i++)
 if(by1==var+i*40)
  return i+1;

}


