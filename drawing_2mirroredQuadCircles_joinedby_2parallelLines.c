/* Author: Syed Alfran Ali */
/* Desired Task : Draw following figure

        (----------------------)
      (                       )
    ( -----------------------)

    ( ----> is circle part.. Run the code to see the program's output */

#include<stdio.h>
#include<graphics.h>
double x[50000],y[50000];
int main()
{
	int i,flag=0;
	/* Initializing the variables */
	double xa[10000],ya[10000],xb[10000],yb[10000];
	double r=50;
	double xin=250,yin=250;
	double x_k=0, y_k=r, p_k = 1-r, p_k1, x_k1, y_k1;
	/* Initializing the graph thread */
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	x[flag] = x_k;
	y[flag] = y_k;
	flag++;
	/* Condition Checking */
	if(p_k >= 0)
	{
		x_k1  = x_k + 1;
		y_k1  = y_k - 1;
	}
	else
	{
		x_k1  = x_k + 1;
		y_k1  = y_k;
	}
	x[flag] = x_k1;
	y[flag] = y_k1;
	flag++;
	/* Storing the c-ordinates in th earray for quadrants */
	while( x_k1 <= y_k1)
	{
		p_k1 = (p_k + 2*(x_k+1)+(y_k1*y_k1-y_k*y_k)-(y_k1-y_k)+1);
		if(p_k1 >= 0)
		{
			x_k1  = x_k1 + 1;
			y_k1  = y_k1 - 1;
		}
		else
		{
			x_k1  = x_k1 + 1;
			y_k1  = y_k1;
		}
		x_k = x[flag-1];
		y_k = y[flag-1];
		x[flag] = x_k1;
		y[flag] = y_k1;
		flag++;
		p_k = p_k1;
	}
	flag--;
	int bu = flag;

	int m = flag;
	int ku = flag;
	for(i=0;i<m;i++)
	{
		x[flag] = y[i];
		y[flag] = x[i];
		flag++;
	}
	m = flag;
	int counter = 0;
	int counter2=0,counter3=0;
	/* Storing the co-ordinates pg both the quadrant points */
	for(i=0;i<m;i++)
	{
		x[flag] = x[i];
		y[flag] = -y[i];
		xa[counter] = x[i];
		ya[counter] = y[i];
		xb[counter2] = -x[i];
		yb[counter2] = -y[i];
		counter2++;
		counter++;
		flag++;
	}

	m = flag;

	for(i=0;i<m;i++)
	{
		x[flag] = -x[i];
		y[flag] = y[i];
		flag++;
	}
	/* Showing the co-ordinates */
	for(i=0;i<counter;i++)
	{
		putpixel(xa[i]+300,ya[i]+300,WHITE);
	}

	for(i=0;i<counter2;i++)
	{
		putpixel(xb[i]+300-75,yb[i]+300+50,WHITE);
	}
	/* Line Drawing*/
	line(0+300,r+300,-75+300,r+300);
	line(0+300+50,r+300-50,-75+300,r+300-50);
	line(0+300,r+300,300-125,r+300);

   getch();
}

