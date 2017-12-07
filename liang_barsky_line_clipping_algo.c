/* Author: Syed Alfran Ali
    Implementation of: Liang Barsky Line Clipping Algorithm */

/* Desired Task: Implement Liang–Barsky line clipping algorithm */
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
int main(void)
{
	int i;
	int gd = DETECT, gm;
 	gm = VGAMAX;
	float xmax,ymax,xmin,ymin,x1,x2,y1,y2,a,b,c,d,dx,dy;
	float p[4],q[4],temp,temp1 = 0,temp2 = 1;
	printf("Enter the co-ordinates of the window\n");
	printf("Enter xmax: ");
	scanf("%f",&xmax);
	printf("\n");
	printf("Enter ymax: ");
	scanf("%f",&ymax);
	printf("\n");
	printf("Enter xmin: ");
	scanf("%f",&xmin);
	printf("\n");
	printf("Enter ymin: ");
	scanf("%f",&ymin);
	printf("\n");

	printf("Enter the co-ordinates of the line\n");
	printf("Enter x1: ");
	scanf("%f",&x1);
	printf("\n");
	printf("Enter y1: ");
	scanf("%f",&y1);
	printf("\n");
	printf("Enter x2: ");
	scanf("%f",&x2);
	printf("\n");
	printf("Enter y2: ");
	scanf("%f",&y2);
	printf("\n");

	initgraph(&gd,&gm,NULL);
	rectangle(xmin,ymin,xmax,ymax);
	dx = x2 - x1;
	dy = y2 - y1;

	p[0] = -dx;
	p[1] = dx;
	p[2] =  -dy;
	p[3] = dy;

	q[0] = x1 - xmin;
	q[1] = xmax - x1;
	q[2] = y1 - ymin;
	q[3] = ymax - y1;


	for(i=0;i<4;i++)
	{
		if(p[i]==0.0)
		{
			printf("Line will be parallel of any of the axes\n");
			if(q[i] < 0.0)
			{
				printf("Line is outside the window\n");
			}
			if(q[i] >= 0.0)
			{
				/* Line is between the xmin and xmax */
				if(x1 > xmin && xmax > x1)
				{
					/* If line is parallel to y axis */
					/* If line is going above ymin then getting the co-ordinate where it gets intersected with the window */
					if(y1 < ymin)
					{
						y1 = ymin;
					}
					/* If line is going below ymax then getting the co-ordinate where it gets intersected with the window */
					if(y2 > ymax)
					{
						y2 = ymax;
					}
				}
				if(y1 > ymin && ymax > y1)
				{
					/* If line is parallel to x axis */
					/* If line is going above xmin then getting the co-ordinate where it gets intersected with the window */
					if(x1 < xmin)
					{
						x1 = xmin;
					}
					/* If line is going below xmax then getting the co-ordinate where it gets intersected with the window */
					if(x2 > xmax)
					{
						x2 = xmax;
					}
				}
			}
			setcolor(RED);
			line(x1,y1,x2,y2);
			setcolor(BLUE);
			pieslice(x1,y1,0,360,4);
			setcolor(BLUE);
			pieslice(x2,y2,0,360,4);
			char *p1,*p2;
			p1 = (char *)malloc(20*sizeof(char));
			p2 = (char *)malloc(20*sizeof(char));

			sprintf(p1,"P1 : (%.3f,%.3f)",x1,y1);
			sprintf(p2,"P2 : (%.3f,%.3f)",x2,y2);

			outtextxy(x1-40,y1-40,p1);
			outtextxy(x2-20,y2-20,p2);
			delay(50000);
			closegraph();
			return 1;
		}
	}
	for(i=0;i<4;i++)
	{
		temp=q[i]/p[i];
		/* For p(i) < 0 */
		if(p[i]<0)
		{
		/* Getting the maximum value of 0 or the q(i)/p(i) */
		    if(temp1 <= temp)
			temp1 = temp;
		}
		/* For p(i) > 0 */
		else
		{
		    if(temp2 > temp)
			temp2 = temp;
		}
	}
	/* Get the clipped co-ordinates */
	if(temp1 < temp2)
	{
		a = x1 + temp1*p[1];
		b = x1 + temp2*p[1];
		c = y1 + temp1*p[3];
		d = y1 + temp2*p[3];
	}
	setcolor(RED);
	/* drawing clipped line and intersection points. */
	line(x1,y1,x2,y2);
	setcolor(BLUE);
	/* For Display of co-ordinates */
	pieslice(a,c,0,360,4);
	/* Color Display */
	setcolor(BLUE);
	pieslice(b,d,0,360,4);
	char *p1,*p2;
	/* Creating Holders to store the co-ordinates in p1 and p2 for better display */
	p1 = (char *)malloc(20*sizeof(char));
	p2 = (char *)malloc(20*sizeof(char));
	sprintf(p1,"P1 : (%.3f,%.3f)",b,d);
	sprintf(p2,"P2 : (%.3f,%.3f)",a,c);
	setcolor(BLUE);
	line(a,c,b,d);
	/* Fixing the postion of co-ordinates display */
	outtextxy(b-20,d-20,p1);
	outtextxy(a-20,c-20,p2);
	delay(50000);
	closegraph();
	return 0;
}
