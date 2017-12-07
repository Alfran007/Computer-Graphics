
/* Author: Syed Alfran Ali
   Desired Task : Implementation of boundary fill Algorithm */
#include<stdio.h>
#include<graphics.h>
void filler(int x,int y,int f,int b)
{
		int c;
		c=getpixel(x,y);
		if((c!=b)&&(c!=f))
		{
			putpixel(x,y,f);
			delay(5);
			filler(x+1,y,f,b);
			filler(x,y+1,f,b);
			filler(x+1,y+1,f,b);
			filler(x-1,y-1,f,b);
			filler(x-1,y,f,b);
			filler(x,y-1,f,b);
			filler(x-1,y+1,f,b);
			filler(x+1,y-1,f,b);

		}
}

int main()
{
	int gd=DETECT,gm,x,y,i;
	int arr[10];
	int brr[12];
	printf("Enter the co-ordinates of the rectangle x1, y1, x2,y2,x3,y3,x4,y4 and then the point inside the rectangle xin,yin\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	y = arr[9];
	arr[8]=arr[0];
	arr[9]=arr[1];
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	drawpoly(5,arr);=
	filler(x,y,4,15);
	getch();
	closegraph();
	return 0;
}
