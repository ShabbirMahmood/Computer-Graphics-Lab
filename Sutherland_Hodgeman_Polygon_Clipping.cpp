/* Shabbir Mahmood  ID: 14015439 Part-3 Even Computer Graphics Lab Assignment-06. Sutherland Hodgeman Polygon Clipping Curve Date: 05-07-2017*/
/*
200 200
400 400
3
150 300
300 150
300 300

200 200
400 400
3
300 150
150 300
450 300

*/
#include<bits/stdc++.h>
#include<graphics.h>
#define round(a) ((int)(a+0.5))
using namespace std;
int k;
float xmin,ymin,xmax,ymax,save[20],m;
void left_clipper(float x1,float y1,float x2,float y2) // Left Clipper
{
    if(x2-x1)
        m=(y2-y1)/(x2-x1);         // Slope
    else
        m=100000;
    if(x1 >= xmin && x2 >= xmin)  // If both points (v1 & v2) are located inside the boundary
    {
        save[k]=x2;
        save[k+1]=y2;             // Save v2 *** 2nd Condition(in to in) of the Algorithm
        k+=2;
    }
    if(x1 < xmin && x2 >= xmin)   // If v1 outside and v2 inside then save v1' & v2 *** 1st Condition(out to in)
    {
        save[k]=xmin;             // v1' x coordinate
        save[k+1]=y1+m*(xmin-x1); // v1' y coordinate
        save[k+2]=x2;             // v2 x coordinate
        save[k+3]=y2;             // v2 y coordinate
        k+=4;
    }
    if(x1 >= xmin  && x2 < xmin) // If v1 inside and v2 outside then save v1' *** 3rd Condition(in to out)
    {
        save[k]=xmin;             // v1' x coordinate
        save[k+1]=y1+m*(xmin-x1); // v1' y coordinate
        k+=2;
    }
}

void top_clipper(float x1,float y1,float x2,float y2)  // Top Clipper
{
    if(y2-y1)
        m=(x2-x1)/(y2-y1);
    else
        m=100000;
    if(y1 <= ymax && y2 <= ymax)
    {
        save[k]=x2;
        save[k+1]=y2;
        k+=2;
    }
    if(y1 > ymax && y2 <= ymax)
    {
        save[k]=x1+m*(ymax-y1);
        save[k+1]=ymax;
        save[k+2]=x2;
        save[k+3]=y2;
        k+=4;
    }
    if(y1 <= ymax  && y2 > ymax)
    {
        save[k]=x1+m*(ymax-y1);
        save[k+1]=ymax;
        k+=2;
    }
}

void right_clipper(float x1,float y1,float x2,float y2)  // Right Clipper
{
    if(x2-x1)
        m=(y2-y1)/(x2-x1);
    else
        m=100000;
    if(x1 <= xmax && x2 <= xmax)
    {
        save[k]=x2;
        save[k+1]=y2;
        k+=2;
    }
    if(x1 > xmax && x2 <= xmax)
    {
        save[k]=xmax;
        save[k+1]=y1+m*(xmax-x1);
        save[k+2]=x2;
        save[k+3]=y2;
        k+=4;
    }
    if(x1 <= xmax  && x2 > xmax)
    {
        save[k]=xmax;
        save[k+1]=y1+m*(xmax-x1);
        k+=2;
    }
}

void bottom_clipper(float x1,float y1,float x2,float y2)  // Bottom Clipper
{
    if(y2-y1)
        m=(x2-x1)/(y2-y1);
    else
        m=100000;
    if(y1 >= ymin && y2 >= ymin)
    {
        save[k]=x2;
        save[k+1]=y2;
        k+=2;
    }
    if(y1 < ymin && y2 >= ymin)
    {
        save[k]=x1+m*(ymin-y1);
        save[k+1]=ymin;
        save[k+2]=x2;
        save[k+3]=y2;
        k+=4;
    }
    if(y1 >= ymin  && y2 < ymin)
    {
        save[k]=x1+m*(ymin-y1);
        save[k+1]=ymin;
        k+=2;
    }
}

int main()
{
    int gd=DETECT,gm,n,poly[20],i;
    float xi,yi,xf,yf,poly_float[20];

    cout<<"Enter the Coordinates of Rectangular Clipping Window"<<endl;
    cout<<"xmin & ymin : ";
    cin>>xmin>>ymin;
    cout<<"xmax & ymax : ";
    cin>>xmax>>ymax;
    cout<<"Enter the number of Sides of the Polygon : ";
    cin>>n;
    cout<<"Enter the Coordinates of the Polygon : "<<endl;
    for(i=0;i < 2*n;i++)
    {
        cin>>poly_float[i];
    }
    poly_float[i]=poly_float[0];        // Coping first two points as Last two points
    poly_float[i+1]=poly_float[1];
    for(i=0;i < 2*n+2;i++)
    {
        poly[i]=round(poly_float[i]);
    }

    initgraph(&gd,&gm,"C:\\TC\\BGI");
    setcolor(BLUE);
    rectangle(xmin,ymax,xmax,ymin);
    cout<<"\n Before Clipping"<<endl;
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    fillpoly(n,poly);
	getch();          // Wait for a key press to start Clipping
    cleardevice();   // Before Clipping it will clear the screen
    // 1st Section
    k=0;
    for(i=0;i < 2*n;i+=2)
    {
        left_clipper(poly_float[i],poly_float[i+1],poly_float[i+2],poly_float[i+3]);
    }

    n=k/2;               // k/2 numbers of new clipped points generated(Updating number of points after clipping)
    for(i=0;i < k;i++)
    {
        poly_float[i]=save[i];
    }
    poly_float[i]=poly_float[0];
    poly_float[i+1]=poly_float[1];

    // 2nd Section
    k=0;
    for(i=0;i < 2*n;i+=2)
    {
       top_clipper(poly_float[i],poly_float[i+1],poly_float[i+2],poly_float[i+3]);
    }
    n=k/2;
    for(i=0;i < k;i++)
    {
        poly_float[i]=save[i];
    }
    poly_float[i]=poly_float[0];
    poly_float[i+1]=poly_float[1];

    // 3rd Section
    k=0;
    for(i=0;i < 2*n;i+=2)
    {
        right_clipper(poly_float[i],poly_float[i+1],poly_float[i+2],poly_float[i+3]);
    }
    n=k/2;
    for(i=0;i < k;i++)
    {
        poly_float[i]=save[i];
    }
    poly_float[i]=poly_float[0];
    poly_float[i+1]=poly_float[1];

    // 4th Section
    k=0;
    for(i=0;i < 2*n;i+=2)
    {
        bottom_clipper(poly_float[i],poly_float[i+1],poly_float[i+2],poly_float[i+3]);
    }
    n=k/2;
    for(i=0;i < k;i++)
    {
        poly[i]=round(save[i]);  // Taking the integer value after rounding up
    }
    if(k)
    {
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        fillpoly(n,poly);        // If new points exist, then draw the clipped polygon
    }

    setcolor(BLUE);
    rectangle(xmin,ymax,xmax,ymin); // Redrawing the clipping window
    cout<<"\n After Clipping"<<endl;
    getch();
    closegraph();
    return 0;
}
