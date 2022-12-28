#include "objects.h"
#include <graphics.h>

//Local Functions starts......
void resetSTATE()
{
    //Reseting to Default State
    setfillstyle(SOLID_FILL, WHITE);
    setcolor(WHITE);
}
int DdrawX(int x, int y, int len , int Color)
{
    setcolor(Color);
    drawLinesThicker(x - len, y - len, x + len, y + len, 10, 1);
    drawLinesThicker(x + len, y - len, x - len, y + len, 10, 1);
    resetSTATE();
}
int DdrawO(int x, int y,int Color)
{
    setcolor(Color);
    drawCircleThicker(x, y, 40, 5);
    resetSTATE();
}
//Local Functions ends........

//Functions in Header Files starts.....
void drawLinesThicker(int x1, int y1, int x2, int y2, int thick, int isVert)
{
    if (isVert == 0)
    {
        for (int i = thick; i >= 0; i--)
        {
            line(x1 + i, y1, x2 + i, y2);
        }
    }
    else if (isVert == 1)
    {
        for (int i = thick; i >= 0; i--)
        {
            line(x1, y1 + i, x2, y2 + i);
        }
    }
    else
    {
        for (int i = thick; i >= 0; i--)
        {
            line(x1 + i, y1 + i, x2 + i, y2 + i);
        }
    }
}
int posFinder(int x, int y)
{
    int RowVal[] = {200, 365, 565, 700};
    int ColVal[] = {150, 316, 517, 650};
    int res = 1;
    int ck = 0;
    for (int i = 0; i < 4; i++)
    {
        if (x > RowVal[i] && x < RowVal[i + 1])
        {
            res += i;
            ck = 1;
        }
    }

    for (int j = 0; j < 4; j++)
    {
        if (y > ColVal[j] && y < ColVal[j + 1])
        {
            res += j * 3;
            ck = 1;
        }
    }
    if (ck == 0)
    {
        return 0;
    }
    else
    {
        return res;
    }
}
void drawCircleThicker(int x, int y, int radius, int thick)
{
    for (int i = 0; i <= thick; i++)
    {
        circle(x, y, radius + i);
    }
}
void drawBoard()
{

    setcolor(CYAN);
    setfillstyle(SOLID_FILL, WHITE);
    /*
        Drawing Basic Board
    */
    drawLinesThicker(365, 150, 365, 650, 3, 0);
    drawLinesThicker(565, 150, 565, 650, 3, 0);
    drawLinesThicker(200, 316, 700, 316, 3, 1);
    drawLinesThicker(200, 517, 700, 517, 3, 1);

    //Reseting to Default State
    resetSTATE();
}
void drawLogo()
{
    //will update later
    resetSTATE();
}
void drawSettings()
{
    //will update later
    resetSTATE();
}
void drawSettingsMenu()
{
    //will update later
    resetSTATE();
}

int drawX(int x, int y, int len)
{
    if (x > 200 && x < 700 && y > 150 && y < 650)
    {
        setcolor(COLOR(255, 223, 0));
        drawLinesThicker(x - len, y - len, x + len, y + len, 10, 1);
        drawLinesThicker(x + len, y - len, x - len, y + len, 10, 1);
        return posFinder(x, y);
    }
    resetSTATE();
}

int drawO(int x, int y)
{
    if (x > 200 && x < 700 && y > 150 && y < 650)
    {
        setcolor(WHITE);
        drawCircleThicker(x, y, 40, 5);
        resetSTATE();
        return posFinder(x, y);
    }
    resetSTATE();
}
void drawCloseButton()
{

    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    setbkcolor(RED);
    rectangle(800, 10, 860, 40);
    floodfill(810, 20, RED);
    setcolor(WHITE);
    outtextxy(810, 20, (char *)"close"); //800,10,860,40
    setbkcolor(BLACK);
    resetSTATE();
}
void drawNGameButton()
{
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    setbkcolor(GREEN);
    rectangle(690, 15, 780, 70);
    floodfill(735, 45, GREEN);
    setcolor(WHITE);
    outtextxy(700, 37, (char *)"New Game"); //800,10,860,40
    setbkcolor(BLACK);
    resetSTATE();
}

void drawPlayer(int player)
{

    if (player == 1)
    {
        drawLinesThicker(165, 70, 400, 70, 5, 0);
        drawLinesThicker(165, 80, 350, 80, 5, 0);
        drawLinesThicker(165, 90, 300, 90, 5, 0);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(165, 50, (char *)"Player's Turn");
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
        DdrawO(70,80,BLACK);
        DdrawX(70, 80, 35,YELLOW);
        resetSTATE();
    }
    else if (player == 2)
    {
        drawLinesThicker(165, 70, 400, 70, 5, 0);
        drawLinesThicker(165, 80, 350, 80, 5, 0);
        drawLinesThicker(165, 90, 300, 90, 5, 0);
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        outtextxy(165, 50, (char *)"Player's Turn");
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
        DdrawX(70,80,35,BLACK);
        DdrawO(70, 80,WHITE);
        resetSTATE();
    }
    
}
void drawCelebBox(){
    cleardevice();
    setcolor(BROWN);
    rectangle(200,300,700,600);
    setfillstyle(XHATCH_FILL,GREEN);
    floodfill(500,450,BROWN);
    resetSTATE();
}
void drawHome(){
    setcolor(WHITE);
    rectangle(100,100,800,400);
    drawLinesThicker(450,100,450,400,6,1);
    setfillstyle(HATCH_FILL,BLUE);
    floodfill(500,450,BLUE);
    resetSTATE();
}
//Functions in Header Files ends.....