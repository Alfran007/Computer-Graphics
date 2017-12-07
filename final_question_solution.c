/* Author: Syed Alfran Ali
   Implementation of: final_task_question.pdf */
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI 3.14
double a[1000],b[1000],an[1000],bn[1000],pk,pk1,x,y,x_1,y_1, lx[1000],ly[1000],ddx[1000],ddy[1000];
int  x_ref = 350, y_ref = 300,flag=0,xo=300,yo= 300,r=50,x_new = 300,y_new=300,x_new2 = 300,y_new2=300;
void semi()
{
	int i;
	x = 0;
	y = r;
	pk = 1-r;
	a[flag] = x;
	b[flag] = y;
	flag++;
	if(pk>=0)
	{
		x_1 = x + 1;
		y_1 = y - 1;
	}
	else if(pk<0)
	{
		x_1 = x + 1;
		y_1 = y;
	}
	a[flag] = x_1;
	b[flag] = y_1;
	flag++;
	while(x_1<=y_1+1)
	{
		pk1 =pk + 2*(x+1) + (y_1*y_1 - y*y) - (y_1 - y) + 1;
		if(pk1>=0)
		{
			x_1 = x_1 + 1;
			y_1 = y_1 - 1;
		}
		else if(pk1<0)
		{
			x_1 = x_1 + 1;
			y_1 = y_1;
		}
		x = a[flag-1];
		y = b[flag -1];
		a[flag] = x_1;
		b[flag] = y_1;
		flag++;
		pk = pk1;
	}
	flag--;
	int m = flag;
	for(i=0;i<m;i++)
	{
		a[flag] = b[i];
		b[flag] = a[i];
		flag++;

	}
	flag--;
	m = flag;
	for(i=0;i<m;i++)
	{
		a[flag] = -a[i];
		b[flag] = b[i];
		flag++;
	}
	flag--;
	m = flag;
	for(i=0;i<m;i++)
	{
		a[flag] = a[i];
		b[flag] = -b[i];
		flag++;
	}
}
void draw()
{
	int i;
	for(i=0;i<flag;i++)
	{
		putpixel(xo+a[i],yo+b[i],WHITE);
	}

}
void fill()
{
	setcolor(GREEN);
	sector(xo,yo,330,360,100,100);
	setcolor(BLUE);
	sector(xo,yo,270,300,150,150);
	setcolor(MAGENTA);
	sector(xo,yo,210,240,100,100);
	setcolor(YELLOW);
	sector(xo,yo,150,180,150,150);
	setcolor(CYAN);
	sector(xo,yo,90,120,100,100);
	setcolor(RED);
	sector(xo,yo,30,60,150,150);
	setcolor(LIGHTGREEN);
	sector(xo,yo,300,330,50,50);
	sector(xo,yo,240,270,50,50);
	sector(xo,yo,180,210,50,50);
	sector(xo,yo,120,150,50,50);
	sector(xo,yo,60,90,50,50);
	sector(xo,yo,0,30,50,50);
}
void dda(int x1, int y1, int x2, int y2)
{
	double m = (y2 - y1)/(x2-x1);
	int i=0;
	i++;
	putpixel(x1,y1,WHITE);
	while(y1<=y2 && x1<=x2)
	{
		if(m>1)
		{
			y1++;
			x1 = x1+(1/m);
		}
		if(m<1)
		{
			x1++;
			y1 = y1 + m;
		}
		else
		{
			x1++;
			y1++;
		}
		putpixel(x1,y1,WHITE);
	}
}
void rotate(int x, int y)
{
	x_new = x*cos(PI/6) + y*sin(PI/6);
	y_new = y*cos(PI/6) - x*sin(PI/6);
}
void filler(int x, int y, int b, int f)
{
	int c= getpixel(x,y);
	while(c!=b&&c!=f)
	{
		putpixel(x,y,f);
		filler(x+1,y,b,f);
		filler(x-1,y,b,f);
		filler(x,y+1,b,f);
		filler(x,y-1,b,f);
	}
}
int main(void)
{

	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	semi();
	draw();
	r = 100;
	x_ref = 400;
	y_ref = 400;
	flag =0;
	semi();
	draw();
	r = 150;
	x_ref = 450;
	y_ref = 450;
	flag =0;
	semi();
	draw();

	dda(xo-150,yo,xo+100,yo);
	//rotate(xo-150+xo,yo);
	x_new2= x_new;
	y_new2 = y_new;
	//rotate(xo+100,yo);
	//line(x_new,y_new,x_new2,y_new2);
	line(xo,yo+100,xo,yo-150);
	//line(xo,yo+100,xo,yo-150);
	//rotate(xo,yo+100);
	x_new2= x_new;
	y_new2 = y_new;
	//rotate(xo,yo-150);
	//line(x_new,y_new,x_new2,y_new2);
	rotate(xo-150,yo);
	x_new2= x_new;
	y_new2 = y_new;
	rotate(xo+150,yo);

	line(x_new-xo,y_new-yo,x_new2-xo,y_new2-yo);
	line(xo-(100/sqrt(2)),yo-(100/sqrt(2)),xo+(150/sqrt(2)),yo+(150/sqrt(2)));
	//line(xo-(100/sqrt(2)/2),yo-(100/sqrt(2)/2),xo+(150/sqrt(2)/2),yo+(150/sqrt(2)/2));
	fill();

	delay(500000);
	closegraph();
}

cg_xam.c
Displaying cg_xam.c.
