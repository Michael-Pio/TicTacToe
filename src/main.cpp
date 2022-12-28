#include <graphics.h>
#include "objects.h"
#include "gamemode.h"
int main()
{
	initwindow(900,700,(const char*)"TicTacToe");
	GameBegin();
	delay(800);
	closegraph();	
	return 0;
}