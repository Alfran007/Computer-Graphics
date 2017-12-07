/*
	Author: Syed Alfran Ali
	Implementation of:	Cohen-Sutherland Line Clipping Algorithm
								*/
/* Desired Task: Implement Cohen-Sutherland line clipping algorithm.
    input: 1) A line that have two points(x1,y1) and (x2,y2) and window coordinates (Xmin, Ymin, Xmax, Ymax).
    output: if line is completely inside the window than ACCEPT,
    if completely outside the window than REJECT and if partially inside than coordinates of intersections.*/

/* Key Terms Used:
	isp[][] = Points where line gets intersected
	xmn,xmx,ymn,ymx = minimum and maximum co-ordinates of the window
	i = Index
	m = slope
*/

/* Multithreading of graph init and main thread is properly implemented.*/
#include<graphics.h>
#include<stdlib.h>
// Defining region codes
const int IN = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000
int xmn,ymn,xmx,ymx;
int max(int a,int b)
{
	return ((a) > (b) ? (a) : (b));
}
int min(int a,int b)
{
	return ((a) < (b) ? (a) : (b));
}


int isp[2][2];
/* End points of rectangle */


/* Using left shift operator to get the region code of the line */
int getCode(int x, int y)
{
	int result=IN;

	if (y>ymx)
		result= result|TOP;
	else if (y<ymn)
		result=result|BOTTOM;

	if (x>xmx)
		result=result|RIGHT;
	else if (x<xmn)
		result=result|LEFT;

	return result;
}

void changeOnePoint(int i,int x,int y)
{
	isp[i][0] = x;
	isp[i][1] = y;
}
/* Calling change for one point 2 times */
void changeBothPoints(int x1,int y1,int x2,int y2)
{
	changeOnePoint(0,x1,y1);
	changeOnePoint(1,x2,y2);
}

int main(void)
{
	int x1,x2,y1,y2;
	/* Taking the window co-ordinates */
	printf("Enter the co-ordinates of window\n");
	printf("Enter xmin : ");
	scanf("%d",&xmn);
	printf("\n");
	printf("Enter ymin : ");
	scanf("%d",&ymn);
	printf("\n");
	printf("Enter xmax : ");
	scanf("%d",&xmx);
	printf("\n");
	printf("Enter ymax : ");
	scanf("%d",&ymx);
	printf("\n");


	/* Taking the co-ordinates of the line */
	printf("First Point\n");
	printf("Enter x1: ");
	scanf("%d",&x1);
	printf("\n");
	printf("Enter y1: ");
	scanf("%d",&y1);
	printf("\n");
	printf("Second Point\n");
	printf("Enter x2: ");
	scanf("%d",&x2);
	printf("\n");
	printf("Enter y2: ");
	scanf("%d",&y2);
	printf("\n");

	/* Finding the region Code. */
	int regionCodeA=0;
	int regionCodeB=0;
	regionCodeA = getCode(x1,y1);
	regionCodeB = getCode(x2,y2);

	/* Condition Checking Begins */

	/* Line is parallel to x-axis */
	if(y1 == y2)
	{
		if(y1 >= ymn && y1 <= ymx)
			changeBothPoints(xmn,y1,xmx,y1);
	}
	/* Line is parallel to y-axis */
	else if(x1 == x2)
	{
		if(x1 >= xmn && x1 <= xmx)
			changeBothPoints(x1,ymn,x1,ymx);
	}

	/* If line is not parallel with any of the axes */
	else
	{
		/* Getting the slope of the line */
		/* Type Casting integers for proper division */
		double m = ((double)y2 - (double)y1)/((double)x2 - (double)x1);

		/* 1) If both the line co-ordinates are inside the window */
		if(regionCodeA == 0 && regionCodeB == 0)
			 changeBothPoints(x1,y1,x2,y2);

		/* If both the line co-ordinates are outside the window */
		else if(regionCodeA != 0 && regionCodeB != 0)
		{
			int i = 0,x,y;

			x = ((double)ymn-(double)y1)/m + x1;
			if((x >= x1 && x <= x2) && x <= xmx && x >= xmn)
				changeOnePoint(i++,x,ymn);

			x = ((double)ymx-(double)y1)/m + x1;
			if((x >= x1 && x <= x2) && x <= xmx && x >= xmn)
				changeOnePoint(i++,x,ymx);

			y = ((double)xmn-(double)x1)*m + y1;
			if(i < 2 && (y <= max(y1,y2)) && y >= min(y1,y2) && y <= ymx && y >= ymn)
				changeOnePoint(i++,xmn,y);

			y = ((double)xmx-(double)x1)*m + y1;
			if(i < 2 && (y <= max(y1,y2)) && y >= min(y1,y2) && y <= ymx && y >= ymn)
				changeOnePoint(i++,xmx,y);
		}
		 /* 'If the co-ordinate point 'A' is inside the window and co-ordinate point 'B' is outside. */
		else if(regionCodeA == 0)
		{
			int i = 0,x,y;
			changeOnePoint(i++,x1,y1);

			x = ((double)ymn-(double)y1)/m + x1;
			if((x >= x1 && x <= x2) && x <= xmx && x >= xmn)
				changeOnePoint(i++,x,ymn);

			x = ((double)ymx-(double)y1)/m + x1;
			if((x >= x1 && x <= x2) && x <= xmx && x >= xmn)
				changeOnePoint(i++,x,ymx);

			y = ((double)xmx-(double)x1)*m + y1;
			if(i < 2 && (y <= max(y1,y2)) && y >= min(y1,y2) && y <= ymx && y >= ymn)
				changeOnePoint(i++,xmx,y);
		}
		/* 'If the co-ordinate point 'A' is inside the window and co-ordinate point 'B' is outside. */
		else if(regionCodeB == 0)
		{
			int i = 0,x,y;
			changeOnePoint(i++,x2,y2);

			x = ((double)ymn-(double)y1)/m + x1;
			if((x >= x1 && x <= x2) && x <= xmx && x >= xmn)
				changeOnePoint(i++,x,ymn);

			x = ((double)ymx-(double)y1)/m + x1;
			if((x >= x1 && x <= x2) && x <= xmx && x >= xmn)
				changeOnePoint(i++,x,ymx);

			y = ((double)xmn-(double)x1)*m + y1;
			if(i < 2 && (y <= max(y1,y2) && y >= min(y1,y2)) && y <= ymx && y >= ymn)
				changeOnePoint(i++,xmn,y);
		}
	}
	/* Creation of the graph, with use of graphics.h */
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);

	/* Rectangle Window display */
	rectangle(xmn,ymn,xmx,ymx);

	/* Line Formation*/
	line(x1,y1,x2,y2);

	if((regionCodeA & regionCodeB) == 0)
	{
		printf("ACCEPT\n");
		/* drawing clipped line and intersection points. */
		setcolor(BLUE);
		line(isp[0][0],isp[0][1],isp[1][0],isp[1][1]);
		setcolor(RED);
		/* For Display of co-ordinates */
		pieslice(isp[0][0],isp[0][1],0,360,4);
		/* Color Display */
		setcolor(RED);
		pieslice(isp[1][0],isp[1][1],0,360,4);
		char *p1,*p2;
		/* Creating Holders to store the co-ordinates in p1 and p2 for better display */
		p1 = (char *)malloc(20*sizeof(char));
		p2 = (char *)malloc(20*sizeof(char));
		sprintf(p1,"P1 : (%d,%d)",isp[0][0],isp[0][1]);
		sprintf(p2,"P2 : (%d,%d)",isp[1][0],isp[1][1]);
		/* Fixing the postion of co-ordinates display */
		outtextxy(isp[0][0]-30,isp[0][1]-30,p1);
		outtextxy(isp[1][0]-30,isp[1][1]-30,p2);
	}
	else
	{
		printf("REJECT\n");
	}

	getch();
	closegraph();

	return 0;
}
