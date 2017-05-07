/* Shabbir Mahmood  ID: 14015439 Part-3 Even Computer Graphics Lab Assignment-06. Bezier Curve Date: 06-05-2017*/
/*
4
100 200
300 400
400 300
200 100

4
200 200
300 50
500 350
600 200

5
200 200
300 100
400 500
500 100
600 200

*/

#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int c[10];

void compute_coefficients(int n)
{
    for(int k=0; k<=n; k++)
    {
        c[k] = 1;    // Compute combination of c(n,k)
        for(int i=n; i>=k+1; i--)  // Don't need to calculate factorial(k) because of k+1 (if n=4 & k=2 then need to calculate 4 * 3 only)
        {
            c[k] *= i;
        }
        for(int i=n-k; i>=2; i--)
        {
            c[k] /= i;
        //cout<<k<<" = " <<c[k]<<endl;
        }
    }
}



int main()
{
    int gd = DETECT;
    int gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    int no_points,x[10],y[10],n,px,py;
    cout<<"Enter the number of Control Points: ";
    cin>>no_points;

    cout<<"Enter Control Points Coordinates(X & Y): "<<endl;
    for(int i=0; i<no_points; i++)
    {
        cout<<"P"<<i<<" : ";
        cin>>x[i];
        cin>>y[i];
    }
    n = no_points - 1; // Degree of the Polynomial (N-1) for N Control Points
    compute_coefficients(n);

    // Bezier Curve Algorithm
    // Drawing Control Points Frame
    for(int i=1; i<no_points; i++)
    {
        setcolor(RED);
        line(x[i],y[i],x[i-1],y[i-1]);
    }
    // Drawing Bezier Curve
    double u;
    for( u=0.0; u<=1.0; u+=0.001)
    {
        double blend;
        px = 0;
        py = 0;
        for(int k=0; k<no_points; k++)
        {
            blend = c[k] * pow(u,k) * pow(1-u,n-k);  // Bezier Blending Function
            px += x[k]*blend;
            py += y[k]*blend;
        }
        putpixel(px,py,WHITE);
        /////////////////////
        setcolor(RED);                                         // Printing the Value of 'u' on the Screen
        settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);

        char msg[100];
        sprintf(msg, "U = %0.2f",u);
        outtextxy(550,600, msg);
        /////////////////////
        delay(1);
    }

    for(int i=1; i<no_points; i++)
    {
        line(x[i],y[i],x[i-1],y[i-1]);
    }
    getch();
    closegraph();
    return 0;
}
