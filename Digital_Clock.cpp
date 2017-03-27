/* Shabbir Mahmood  ID: 14015439 Part-3 Even Computer Graphics Lab 02. Digital Clock Date: 26-02-2017*/
#include<bits/stdc++.h>
#include<graphics.h>
#include<time.h>
using namespace std;

int main()
{
    int gd = DETECT;
    int gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    time_t rawTime;
    struct tm * currentTimeInfo;

    while(true)                              // Infinite Loop
    {
        time(&rawTime);                      // Current time in Unix Time Stamp
        currentTimeInfo = localtime(&rawTime); // Converting Current time in Local time from Unix Time Stamp

        char time_array[100], date_array[100];
        strftime(time_array,100,"%I:%M:%S %p",currentTimeInfo);  // Copying Current time

        setcolor(BLUE);                                          // Current Time Block
        settextstyle(SIMPLEX_FONT,HORIZ_DIR,10);
        outtextxy(200,200,time_array);

        strftime(date_array,100,"%A,%d %B,%Y",currentTimeInfo);  // Date Block
        setcolor(BLUE);
        settextstyle(SIMPLEX_FONT,HORIZ_DIR,5);
        outtextxy(350,400,date_array);

        setcolor(BLUE);                                         // "Digital Clock" Block
        settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);
        outtextxy(550,600,"Digital Clock");

        setcolor(BLUE);
        rectangle(170,180,1270,500);                            // Rectangle Border Block
        delay(1000);                                            // Delay 1 Second to refresh the screen
    }
    getch();
    closegraph();
}
