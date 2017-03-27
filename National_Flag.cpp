/* Shabbir Mahmood  ID: 14015439 Part-3 Even Computer Graphics Lab 01. National Flag Date: 24-02-2017*/
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main()
{
    int gd = DETECT;
    int gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    // Rectangle
    rectangle(300,100,800,400);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(301,101,WHITE);
    // Circle
    circle(525,250,100);
    setfillstyle(SOLID_FILL,RED); //EMPTY_FILL, LINE_FILL, SOLID_FILL, HATCH_FILL,LTSLASH_FILL, BKSLASH_FILL, LTBKSLASH_FILL, XHATCH_FILL
    floodfill(525,250,WHITE);          //INTERLEAVE_FILL, WIDE_DOT_FILL,CLOSE_DOT_FILL, USER_FILL

    setcolor(WHITE);
    settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
    outtextxy(400,50,"National Flag of Bangladesh");


    getch();
    closegraph();
}

