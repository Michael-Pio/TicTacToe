#include "gamemode.h"
#include <graphics.h>

#define Exit 1
#define NwGame 2
#define Xwon 3
#define Owon 4
#define Draw 5
#define Idle 0
#define ODD 1
#define EVEN 0
void ButtonSensor(int mX, int mY, int *ValueHolder)
{

	if (mX > 800 && mX < 860 && mY > 10 && mY < 40)
	{ //800,10,860,40 coordinates of closebtn
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			clearmouseclick(WM_LBUTTONDBLCLK);
			*ValueHolder = 1;
		}
	}
	else if (mX > 690 && mX < 780 && mY > 15 && mY < 70)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			clearmouseclick(WM_LBUTTONDBLCLK);
			*ValueHolder = 2;
		}
	}
	else
	{
		*ValueHolder = 0;
	}
}
void WinLoseDrawState(int *WinLoseValueHolder, int counter, int GameState[9])
{
	if (counter >= 4)
	{
		/*Horizontals*/
		if (GameState[0] == GameState[1] && GameState[1] == GameState[2])
		{
			*WinLoseValueHolder = GameState[0];
		}
		else if (GameState[3] == GameState[4] && GameState[4] == GameState[5])
		{
			*WinLoseValueHolder = GameState[3];
		}
		else if (GameState[6] == GameState[7] && GameState[7] == GameState[8])
		{
			*WinLoseValueHolder = GameState[6];
		}
		/*Verticals*/
		else if (GameState[0] == GameState[3] && GameState[3] == GameState[6])
		{
			*WinLoseValueHolder = GameState[0];
		}
		else if (GameState[1] == GameState[4] && GameState[4] == GameState[7])
		{
			*WinLoseValueHolder = GameState[1];
		}
		else if (GameState[2] == GameState[5] && GameState[5] == GameState[8])
		{
			*WinLoseValueHolder = GameState[2];
		}
		/*Diagonals*/
		else if (GameState[0] == GameState[4] && GameState[4] == GameState[8])
		{
			*WinLoseValueHolder = GameState[0];
		}
		else if (GameState[2] == GameState[4] && GameState[4] == GameState[6])
		{
			*WinLoseValueHolder = GameState[0];
		}
		/*Draw*/
		else if (counter == 8)
		{
			*WinLoseValueHolder = 3;
		}
	}
	else
	{
		*WinLoseValueHolder = 0;
	}
}

void GameBegin()
{
	int mX, mY;
	int GameStateManager = NwGame;
	int winlosedrawState = 0;
	int close = 0;
	int GameState[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int counter = 0;
	/*	0 = vaccant		1 = x	2 = y	*/
	while (close != 1)
	{
		mX = mousex();
		mY = mousey();
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			ButtonSensor(mX, mY, &GameStateManager);
		}
		switch (GameStateManager)
		{
		case Exit:
		    close =1;
			cleardevice();
			settextstyle(BOLD_FONT, HORIZ_DIR, 4);
			outtextxy(250, 430, (char *)"NEW Game Starts Now");
			drawCelebBox();
			settextstyle(BOLD_FONT, HORIZ_DIR, 4);
			outtextxy(350, 430, (char *)"GAME is Closing");
			settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
			
			break;

		case NwGame:
			settextstyle(BOLD_FONT, HORIZ_DIR, 4);
			outtextxy(250, 430, (char *)"NEW Game Starts Now");
			drawCelebBox();
			settextstyle(BOLD_FONT, HORIZ_DIR, 4);
			outtextxy(250, 430, (char *)"NEW Game Starts Now");
			settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
			delay(3000);
			cleardevice();
			for (int i = 0; i < 9; i++)
				GameState[i] = 0;
			counter = 0;
			GameStateManager = Idle;
			break;
		case Xwon:
			drawCelebBox();
			settextstyle(BOLD_FONT, HORIZ_DIR, 4);
			outtextxy(250, 430, (char *)"Congrats X won the Game");
			settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
			delay(5000);
			GameStateManager = NwGame;
			break;
		case Owon:
			drawCelebBox();
			settextstyle(BOLD_FONT, HORIZ_DIR, 4);
			outtextxy(250, 430, (char *)"Congrats O won the Game");
			settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
			delay(5000);
			GameStateManager = NwGame;
			break;
		case Draw:
			drawCelebBox();
			settextstyle(BOLD_FONT, HORIZ_DIR, 4);
			outtextxy(350, 430, (char *)"Match DRAW");
			settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
			delay(5000);
			GameStateManager = NwGame;
			break;
		case Idle:
			switch (counter % 2)
			{
			case EVEN:
				if (ismouseclick(WM_LBUTTONDOWN))
				{
					int pF = posFinder(mX, mY);
					if (GameState[pF - 1] == 0)
					{
						int Position = drawX(mX, mY, 35) - 1;
						if (Position != -1)
						{
							GameState[Position] = 1;
							counter++;
						}
						WinLoseDrawState(&winlosedrawState, counter, GameState);
						if (winlosedrawState == 1)
						{
							GameStateManager = Xwon;
						}
						else if (winlosedrawState == 3)
						{
							GameStateManager = Draw;
						}
					}
					clearmouseclick(WM_LBUTTONDOWN);
				}
				break;
			case ODD:
				if (ismouseclick(WM_LBUTTONDOWN))
				{
					int pF = posFinder(mX, mY);
					if (GameState[pF - 1] == 0)
					{
						int Position = drawO(mX, mY) - 1;
						if (Position != -1)
						{
							GameState[Position] = 2;
							counter++;
						}
						WinLoseDrawState(&winlosedrawState, counter, GameState);
						if (winlosedrawState == 2)
						{
							GameStateManager = Owon;
						}
						else if (winlosedrawState == 3)
						{
							GameStateManager = Draw;
						}
					}
				}
				clearmouseclick(WM_LBUTTONDOWN);
				break;
			default:
				break;
			}

			break;
		default:
			break;
		}
		clearmouseclick(WM_LBUTTONDOWN);
		drawCloseButton();
		drawNGameButton();
		drawPlayer(counter % 2 + 1);
		drawBoard();
		delay(10);
	}
}