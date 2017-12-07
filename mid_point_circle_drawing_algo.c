/* Author: Syed Alfran Ali
   Implementation of : Mid-point Circle Drawing Algorithm */
/* Desired Task: Implement mid point circles drawing algorithm */
#include<stdio.h>
#include<graphics.h>
double x[50000],y[50000];
int main()
{
	int i,flag=0;
	double r;
	printf("Please enter the radius of the circle: ");
	scanf("%lf",&r);
	double x_k=0, y_k=r, p_k = 1-r, p_k1, x_k1, y_k1;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	x[flag] = x_k;
	y[flag] = y_k;
	flag++;
	/* Condition checking of pk and accordingly changing xk1 and yk1*/
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
	while( x_k1 <= y_k1)
	{
		/* Calculating pk1 for next point information */
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
	int m = flag;
	/* Second octent formation by first octent */
	for(i=0;i<m;i++)
	{
		x[flag] = y[i];
		y[flag] = x[i];
		flag++;
	}
	m = flag;
	/* Formation of the fourth quadrant from the mirror image of the first */
	for(i=0;i<m;i++)
	{
		x[flag] = x[i];
		y[flag] = -y[i];
		flag++;
	}
	m = flag;
	/* Making the circle's second half from the other half by taking mirror image */
	for(i=0;i<m;i++)
	{
		x[flag] = -x[i];
		y[flag] = y[i];
		flag++;
	}
	/* Circle Drawing */
	if(r < 100)
	{
		for(i=0;i<flag;i++)
		{
			putpixel(x[i]+100,y[i]+100,WHITE);
		}
	}
	else
	{
		for(i=0;i<flag;i++)
		{
			putpixel(x[i]+r,y[i]+r,WHITE);
		}
	}
   getch();
}

