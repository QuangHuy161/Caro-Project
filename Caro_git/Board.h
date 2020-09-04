#pragma once
#include"coordinate.h"
#include"function.h"
#include"Common.h"
#include <string>

class Board
{
private:
	int size;
	int left, top;
	Coordinate** B;
	fstream file;
public:
	int CountX;
	int CountY;
	int score_1, score_2;
	Board();
	Board& operator =(Board&);
	Board(int, int, int);
	~Board();
	void setStausAt(int, int, int);
	int getSize();
	int getLeft();
	int getTop();
	int getXAt(int, int);
	int getYAt(int, int);
	int getStatusAt(int, int);
	void resetData();
	void drawBoard();
	void userBoard_1();
	void userBoard_2();
	void userGuideBoard();
	void menuBoard();
	void GroupBoard();
	void HelpBoard();
	void LoadGameBoard();
	void loadData(int, int, int);
	int get_Check(int i, int j) { return B[i][j].getStatus(); }
};