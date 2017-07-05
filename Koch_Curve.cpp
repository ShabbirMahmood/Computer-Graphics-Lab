/*
100
300
500
0
3
*/
/* Shabbir Mahmood ID: 14015439 Date: 28-04-2017 */
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void koch_curve(long double x,long double y,long double lenght,long double angle,int n_order);
void line_segment(int x_1,int y_1, int x_2,int y_2);   // Bresenham Line Generating algorithm

int main()
{
    int gd=DETECT,gm;
    long double x=0;
    long double y=0;
    long double l=0;
    long double angle=0;
    int n=0;

    cout<<"Enter the Starting point(x,y) of the Initiator(Line)"<<endl;
    cout<<"X Coordinate of the Initiator                      : ";
    cin>>x;
    cout<<"Y Coordinate of the Initiator                      : ";
    cin>>y;
    cout<<"Enter the Length of the Initiator(Line) in pixels  : ";
    cin>>l;
    cout<<"Angle of the Initiator(Line) with respect to X axis: ";
    cin>>angle;
    cout<<"Enter the Order(n) of the Koch Curve               : ";
    cin>>n;

    initgraph(&gd,&gm,"C:\\TC\\BGI");
    koch_curve(x,y,l,angle,n);
    getch();         // Wait until a Character is Pressed
    closegraph();
    return 0;
}
void koch_curve(long double x,long double y,long double lenght,long double angle,int n_order)
{
    if(n_order>0)
    {
        lenght/=3;                                         // Scaling Factor = 1/3

        koch_curve(x,y,lenght,angle,(n_order-1));          // 1st line segment of the generator

        x+=(lenght*cosl(angle*(M_PI/180)));
        y+=(lenght*sinl(angle*(M_PI/180)));

        koch_curve(x,y,lenght,(angle-60),(n_order-1));     // 2nd line segment of the generator

        x+=(lenght*cosl((angle-60)*(M_PI/180)));
        y+=(lenght*sinl((angle-60)*(M_PI/180)));

        koch_curve(x,y,lenght,(angle+60),(n_order-1));     // 3rd line segment of the generator

        x+=(lenght*cosl((angle+60)*(M_PI/180)));
        y+=(lenght*sinl((angle+60)*(M_PI/180)));

        koch_curve(x,y,lenght,angle,(n_order-1));          // 4th line segment of the generator
    }
    else
    {
        line_segment(x,y,(int)(x+lenght*cosl(angle*(M_PI/180))+0.5),(int)(y+lenght*sinl(angle*(M_PI/180))));
    }

}
void line_segment(int x_1,int y_1, int x_2,int y_2)  // Bresenham Line Generating algorithm
{
    int color=YELLOW;

    int x1=x_1;
    int y1=y_1;
    int x2=x_2;
    int y2=y_2;

    if(x_1>x_2)               // If Starting Point appears as Ending Point then Swap them
    {
        x1=x_2;
        y1=y_2;
        x2=x_1;
        y2=y_1;
    }
    int dx=abs(x2-x1);              // Constant dx
    int dy=abs(y2-y1);              // Constant dy
    int inc_dec=((y2>=y1)?1:-1);
    if(dx>dy)
    {
        int two_dy=(2*dy);          // Constant 2dy
        int two_dy_dx=(2*(dy-dx));  // Constant 2(dy-dx)
        int p=((2*dy)-dx);          // Initial Decision Parameter P0 = 2dy-dx
        int x=x1;
        int y=y1;
        putpixel(x,y,color);        // Initial Point of the line
        while(x<x2)  // If X coordinate of the starting point is greater than the end point
        {
            x++;                    // X increments in each iteration x=x+1 & y is unchanged
            if(p<0)                 // If decision parameter is negative (p<0)
                p+=two_dy;          // then Next decision parameter is p = p+2dy
            else                   // If decision parameter is positive (p>0)
            {
                y+=inc_dec;         // then y increments
                p+=two_dy_dx;       // and Next decision parameter is p = p+2dy-2dx
            }
            putpixel(x,y,color);    // Printing the pixel
        }
    }
    else          // If X coordinate of the starting point is less than the end point
    {
        int two_dx=(2*dx);
        int two_dx_dy=(2*(dx-dy));
        int p=((2*dx)-dy);
        int x=x1;
        int y=y1;
        putpixel(x,y,color);
        while(y!=y2)               // Y decrement and reaches to y2
        {
            y+=inc_dec;            // Y increments in each iteration y=y+1 & X is unchanged
            if(p<0)
                p+=two_dx;
            else
            {
                x++;              // X also increments x=x+1
                p+=two_dx_dy;
            }
            putpixel(x,y,color);
        }
    }
}

