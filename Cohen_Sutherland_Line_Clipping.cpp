#include<iostream>

#include<graphics.h>
#include<bitset>
/*
100
100
200
200
150 150
250 90

*/
double m;
typedef unsigned int region_code;
enum{LEFT=0x1,RIGHT=0x2,BELOW=0x4,ABOVE=0x8};

using namespace std;

region_code Compregion_code(double ,double ,double ,double ,double ,double );
void CSLCAD(double x1,double y1,double x2,double y2,double xmin,double xmax,double ymin,double ymax)
{

    region_code region_code1,region_code2,region_codeout;
    boolean accept=FALSE, done=FALSE;
    region_code1=Compregion_code(x1,y1,xmin,xmax,ymin,ymax);
    region_code2=Compregion_code(x2,y2,xmin,xmax,ymin,ymax);
    cout<<"region_code1="<<region_code1<<endl;
    cout<<"region_code2="<<region_code2<<endl;

    ///////////////

    cout<<"region_code1="<<region_code1<<" => "<<bitset<4>(region_code1)<<endl;
    cout<<"region_code2="<<region_code2<<" => "<<bitset<4>(region_code2)<<endl;
    /////////////////
    do
    {
        if(region_code1==0 && region_code2==0)  //********** And (&&)
        {
            accept=TRUE;
            done=TRUE;
        }
        else if(region_code1 & region_code2)  //********* Bitwise And (&)
            {
                done=TRUE;
            }
            else
            {
                double x,y;
                m = ((y2-y1)/(x2-x1)); //*****Slope
                int ocd=region_code1 ? region_code1:region_code2;  // if region_code1 is not zero then it will be assigned to ocd
                if(ocd & ABOVE)
                {
                    y=ymin;
                    x=x1+(y-y1)/m;   // m = (y2-y1)/(x2-x1);
                }
                else if(ocd & BELOW)
                {
                    y=ymax;
                    x=x1+(y-y1)/m;
                }
                else if(ocd & LEFT)
                {
                    x=xmin;
                    y=y1+m*(x-x1);
                }
                else
                {
                   x=xmax;
                   y=y1+m*(x-x1);
                }
                if(ocd==region_code1)
                {
                    x1=x;
                    y1=y;
                    region_code1=Compregion_code(x1,y1,xmin,xmax,ymin,ymax);
                }
                else
                {
                    x2=x;
                    y2=y;
                    region_code2=Compregion_code(x2,y2,xmin,xmax,ymin,ymax);
                }
            }

    }while(done==FALSE);

    if(accept==TRUE)
    {
        line(x1,y1,x2,y2);
    }
}

region_code Compregion_code(double x,double y,double xmin,double xmax,double ymin,double ymax)
{
    region_code code=0;   // Unsigned Integer
    if(y>ymax)
        code|=BELOW;
    if(y<ymin)
        code|=ABOVE;
    if(x>xmax)
        code|=RIGHT;
    if(x<xmin)
        code|=LEFT;
    return code;
}

int main()
{
    string ch;
    double xmin,xmax,ymin,ymax,x1,y1,x2,y2;

    initwindow(500,600);

    cout<<"Enter the BELOW co-ordinates of window:";
 cin>>xmin;
 cout<<"Enter the left coordinates of the window:";
 cin>>ymin;
 cout<<"Enter the right coordinates of the window:";
 cin>>xmax;
 cout<<"Enter the ABOVE coordinates of the window:";
 cin>>ymax;
 rectangle(xmin,ymin,xmax,ymax);

 cout<<"Enter the coordinates(Terminal Points) of the line: ";
 cin>>x1>>y1;
 cin>>x2>>y2;
 line(x1,y1,x2,y2);

    delay(5000);
    cleardevice();
    CSLCAD(x1,y1,x2,y2,xmin,xmax,ymin,ymax);
    rectangle(xmin,ymin,xmax,ymax);
    delay(50000);

    closegraph();
}
