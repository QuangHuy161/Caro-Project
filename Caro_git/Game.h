#pragma comment(lib, "winmm.lib")

#include "Board.h"
#include "Common.h"
#include "function.h"
#include<fstream>
class Game
{
public:
	Game();
	~Game();
	void moveDown();
	void moveUp();
	void moveLeft();
	void moveRight();
	void startGame();
	bool checkWinRow();
	bool checkWinCol();
	bool checkDiagonalMain();
	bool checkDiagonalSub();
	void setCountXY();
	int DemNuocCoDaDi();



private:
	int xMidRect, yMidRect;
	Board _Board;
	int top, left, size;
	int scorep1; 
	int scorep2; 
	int chedo;
	int _x, _y;
	bool _turn;
};

