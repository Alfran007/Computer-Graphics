

/* Author: Syed Alfran Ali
   Implementation of: Bresenham Line Drawing Algorithm */
/* Desired Task: Implement Bresenham's line drawing algorithm in C and show all intermediate points of that line.*/
# include <stdio.h>
# include <graphics.h>

void main()
{
/* Declarations*/
int dx,dy,xk,yk,xk1,yk1,pk,pk1,x1,y1,x2,y2;
int gd,gm;

/* Taking end points of line as input*/
printf("Enter the first cordinates (x1,y1):\n");
scanf("%d %d",&x1,&y1);
printf("Enter the first cordinates (x2,y2):\n");
scanf("%d %d",&x2,&y2);

/* Getting Difference of co-ordinates*/
dx = x2-x1;
dy = y2-y1;

/* Getting Slope */
float m = dy/dx;

/* Getting pk values according to slope */
if(m<1)
pk = 2*dy-dx;
else
pk = 2*dx-dy;

/* Initialising xk and yk */
xk = x1;
yk = y1;

/* Graph Initialisation */
initgraph(&gd,&gm,"C:\\TC\\BGI");

printf("Co-ordinates are:\n");
/* Condition checking in each iteration to find the next co-ordinate*/
while(xk<=x2 && yk<=y2)
{
	/* If slope is less than one */
	if(m<1)
	{
		if(pk < 0)
		{
			xk1=xk+1;
			yk1=yk;
		}
		else
		{
			xk1=xk+1;
			yk1=yk+1;
		}
		printf("(%d, %d) ",xk,yk);
		pk1 = pk + 2*(dy) - 2*dx*(yk1 -yk) ;
		/* Printing the line pixel by pixel*/
		putpixel(xk,yk,RED);
		xk = xk1;
		yk = yk1;
		pk = pk1;


	}
	/* If slope is greater than one */
	else if(m>1)
	{
		if(pk < 0)
		{
			xk1=xk;
			yk1=yk +1;
		}
		else
		{
			xk1=xk+1;
			yk1=yk+1;
		}
		printf("(%d, %d) ",xk,yk);
		pk1 = pk + 2*dx - 2*dy*(xk1-xk);
		pk = pk1;
		putpixel(xk,yk,RED);
		xk = xk1;
		yk = yk1;


	}
	/* If slope is one */
	else
	{
		xk1 = xk+1;
		yk1 = yk+1;
		putpixel(xk,yk,RED);
		printf("(%d, %d) ",xk,yk);
		xk = xk1;
		yk = yk1;


	}
}
/* Wait for character input*/
getch();
/* Closing the graph*/
closegraph();

}

