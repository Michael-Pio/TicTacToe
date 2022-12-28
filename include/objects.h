#ifndef OBJECTS_H
#define OBJECTS_H



void drawLinesThicker(int x1, int y1, int x2, int y2, int thick, int isVert);
void drawCircleThicker(int x, int y, int radius, int thick);

void drawBoard();
void drawLogo();
void drawCloseButton();
void drawHome();
void drawSettings();
void drawSettingsMenu();
void drawPlayer(int player);
int drawX(int x, int y, int len);
int drawO(int x, int y);
int posFinder(int x, int y);
void drawNGameButton();
void drawCelebBox();
//Values

#endif