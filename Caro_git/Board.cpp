#include "Board.h"
#include<iostream>
using namespace std;

Board::Board() {
	size = 20;
	left = 0;
	top = 0;
	B = new Coordinate * [size];
	for (int i = 0; i < size; i++) B[i] = new Coordinate[size];
	file.open("info.txt", ios::in|ios::out | ios::app);
}
Board::Board(int pSize, int pX, int pY) {
	for (int i = 0; i < size; i++) delete[] B[i];
	delete[] B;
	size = pSize;
	left = pX;
	top = pY;
	B = new Coordinate * [pSize];
	for (int i = 0; i < pSize; i++) B[i] = new Coordinate[pSize];
	file.open("info.txt", ios::out | ios::app);
}
Board& Board::operator=(Board& b) {
	for (int i = 0; i < size; i++) delete[] B[i];
	delete[] B;
	Board* btmp = new Board;
	btmp->size = b.size;
	btmp->left = b.left;
	btmp->top = b.top;
	btmp->B = new Coordinate * [size];
	for (int i = 0; i < size; i++) btmp->B[i] = new Coordinate[size];
	return *btmp;
}

void Board::setStausAt(int i, int j, int sta) {
	B[i][j].setStatus(sta);
}
void Board::resetData()
{
	if (size == 0) return;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			B[i][j].setX(4 * j + left + 4);
			B[i][j].setY(2 * i + top + 2);
			B[i][j].setStatus(0);
		}
	}
}
int Board::getSize() { return size; }
int Board::getLeft() { return left; }
int Board::getTop() { return top; }
int Board::getXAt(int i, int j) {
	return B[i][j].getX();
}
int Board::getYAt(int i, int j) {
	return B[i][j].getY();
}

int Board::getStatusAt(int i, int j) {
	return B[i][j].getStatus();
}

void Board::drawBoard() {
	if (size == 0) return;
	//dong dau
	for (int i = 0; i < size * 4; i++)
	{
		//ki tu dau
		if (i == 0) {
			_Common::gotoXY(i + left + 4, 0 + top + 2);
			cout << char(201);
		}
		else
			//ki tu chia o
			if (i % 4 == 0 && (i != 0 || i != size * 4)) {
				_Common::gotoXY(i + left + 4, 0 + top + 2);
				cout << char(203);
			}
			else
				//ki tu thuong
			{
				_Common::gotoXY(i + left + 4, 0 + top + 2);
				cout << char(205);
			}
		Sleep(5);
	}
	//ki tu cuoi
	{
		_Common::gotoXY(size * 4 + left + 4, 0 + top + 2);
		cout << char(187);
	}

	//dong thuong
	for (int j = 1; j < size * 2; j++)
	{
		if (j % 2 == 0) {
			for (int i = 0; i < size * 4; i++)
			{
				//ki tu dau
				if (i == 0) {
					_Common::gotoXY(i + left + 4, j + top + 2);
					cout << char(204);
				}
				else
					//ki tu chia o
					if (i % 4 == 0 && (i != 0 || i != size * 4)) {
						_Common::gotoXY(i + left + 4, j + top + 2);
						cout << char(206);
					}
					else
						//ki tu thuong
					{
						_Common::gotoXY(i + left + 4, j + top + 2);
						cout << char(205);
					}
				Sleep(0.8);
			}
			//ki tu cuoi
			{
				_Common::gotoXY(size * 4 + left + 4, j + top + 2);
				cout << char(185);
			}
			Sleep(5);
		}
		else {
			for (int i = 0; i < size * 4; i++)
			{
				//ki tu chia o
				if (i % 4 == 0) {
					_Common::gotoXY(i + left + 4, j + top + 2);
					cout << char(186);
				}
				Sleep(0.8);
			}
			//ki tu cuoi
			{
				_Common::gotoXY(size * 4 + left + 4, j + top + 2);
				cout << char(186);
			}
			Sleep(5);
		}
		Sleep(5);
	}

	//dong cuoi
	for (int i = 0; i < size * 4; i++)
	{
		//ki tu dau
		if (i == 0) {
			_Common::gotoXY(i + left + 4, size * 2 + top + 2);
			cout << char(200);
		}
		else
			//ki tu chia o
			if (i % 4 == 0 && (i != 0 || i != size * 4)) {
				_Common::gotoXY(i + left + 4, size * 2 + top + 2);
				cout << char(202);
			}

			else
				//ki tu thuong
			{
				_Common::gotoXY(i + left + 4, size * 2 + top + 2);
				cout << char(205);
			}
		Sleep(10);
	}
	//ki tu cuoi
	{
		_Common::gotoXY(size * 4 + left + 4, size * 2 + top + 2);
		cout << char(188);
	}

}
void Board::userBoard_1()
{
	SetColor(22);
	for (int j = (size / 2) * 4 + left + 4 + 50; j <= 140; j++)
	{
		_Common::gotoXY(j, top + 2);
		cout << char(254);
		_Common::gotoXY(j, size - 4 + top + 2);
		cout << char(254);
	}

	for (int j = (size / 2) * 4 + left + 4 + 50; j <= 140; j++) {
		_Common::gotoXY(j, top + 2 + 6);
		cout << char(236);
	}

	for (int i = top + 2; i < size + top - 2; i++)
	{
		_Common::gotoXY((size / 2) * 4 + left + 4 + 50, i + top);
		cout << char(254);
		_Common::gotoXY((size / 2) * 4 + left + 4 + 50 + 46, i + top);
		cout << char(254);
	}



	// 4 corner
	_Common::gotoXY((size / 2) * 4 + left + 4 + 50, top + 2);
	cout << char(254);

	_Common::gotoXY((size / 2) * 4 + left + 4 + 50, top + 2 + 16);
	cout << char(254);


	_Common::gotoXY((size / 2) * 4 + left + 4 + 54, top + 2 + 1);
	cout << " _____  _                        ___   ";
	_Common::gotoXY((size / 2) * 4 + left + 4 + 54, top + 2 + 2);
	cout << "|  _  || | ___  _ _  ___  ___   |_  |  ";
	_Common::gotoXY((size / 2) * 4 + left + 4 + 54, top + 2 + 3);
	cout << "|   __|| || .'|| | || -_||  _|   _| |_ ";
	_Common::gotoXY((size / 2) * 4 + left + 4 + 54, top + 2 + 4);
	cout << "|__|   |_||__,||_  ||___||_|    |_____|";
	_Common::gotoXY((size / 2) * 4 + left + 4 + 54, top + 2 + 5);
	cout << "               |___|                   ";


	// Player info
	SetColor(0); 
	_Common::gotoXY((size / 2) * 4 + left + 4 + 57, top + 2 + 10);
	cout << "Name: ";
	string name;
	int p = _getch();
	if (p != 13){
		cout << (char)p;
		getline(cin, name);
		file << (char)p << name << endl;
	}

	_Common::gotoXY((size / 2) * 4 + left + 4 + 57, top + 2 + 13);
	cout << "Turn:\t";
	_Common::gotoXY((size / 2) * 4 + left + 4 + 57 + 10, top + 2 + 13);
	cout << score_1;

	Sleep(10);

	// Draw X
	SetColor(12);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 28 + 26, top + 2 + 18);
	cout << char(178) << char(178) << char(178) << char(178) << char(177) << "      " << char(178) << char(178) << char(178) << char(178) << char(177);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 28 + 28, top + 2 + 19);
	cout << char(178) << char(178) << char(178) << char(178) << char(177) << "  " << char(178) << char(178) << char(178) << char(178) << char(177);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 28 + 31, top + 2 + 20);
	cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(177);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 28 + 28, top + 2 + 21);
	cout << char(178) << char(178) << char(178) << char(178) << char(177) << "  " << char(178) << char(178) << char(178) << char(178) << char(177);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 28 + 26, top + 2 + 22);
	cout << char(178) << char(178) << char(178) << char(178) << char(177) << "      " << char(178) << char(178) << char(178) << char(178) << char(177);
}

void Board::userBoard_2()
{
	SetColor(21);
	for (int j = (size / 2) * 4 + left + 4 + 50; j <= 140; j++)
	{
		_Common::gotoXY(j, top + 2 + 24);
		cout << char(254);
		_Common::gotoXY(j, size - 4 + top + 2 + 24);
		cout << char(254);
	}
	for (int j = (size / 2) * 4 + left + 4 + 50; j <= 140; j++) {
		_Common::gotoXY(j, top + 2 + 24 + 6);
		cout << char(236);
	}

	for (int i = top + 2; i < size + top - 3; i++)
	{
		_Common::gotoXY((size / 2) * 4 + left + 4 + 50, i + top + 25);
		cout << char(254);
		_Common::gotoXY((size / 2) * 4 + left + 4 + 50 + 46, i + top + 25);
		cout << char(254);

	}

	// 4 corner
	_Common::gotoXY((size / 2) * 4 + left + 4 + 50, top + 2 + 24);
	cout << char(254);


	_Common::gotoXY((size / 2) * 4 + left + 4 + 50, top + 2 + 40);
	cout << char(254);


	_Common::gotoXY((size / 2) * 4 + left + 4 + 54, top + 2 + 25);
	cout << " _____  _                        ___ ";
	_Common::gotoXY((size / 2) * 4 + left + 4 + 54, top + 2 + 26);
	cout << "|  _  || | ___  _ _  ___  ___   |_  |";
	_Common::gotoXY((size / 2) * 4 + left + 4 + 54, top + 2 + 27);
	cout << "|   __|| || .'|| | || -_||  _|  |  _|";
	_Common::gotoXY((size / 2) * 4 + left + 4 + 54, top + 2 + 28);
	cout << "|__|   |_||__,||_  ||___||_|    |___|";
	_Common::gotoXY((size / 2) * 4 + left + 4 + 54, top + 2 + 29);
	cout << "               |___|                   ";


	// Player info
	SetColor(0);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 57, top + 2 + 34);
	cout << "Name: ";
	string name;
	int p = _getch();
	if (p != 13){
		cout << (char)p;
		getline(cin, name);
		file << (char)p << name << endl;
	}
		
	//}
	_Common::gotoXY((size / 2) * 4 + left + 4 + 57, top + 2 + 37);
	cout << "Turn:\t" ;
	_Common::gotoXY((size / 2) * 4 + left + 4 + 57 + 10, top + 2 + 37);
	cout << score_2;
	Sleep(10);

	// Draw O
	SetColor(10);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 17 + 62, top + 2 + 18);
	cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(177);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 17 + 60, top + 2 + 19);
	cout << char(178) << char(178) << char(178) << char(178) << char(177) << "      " << char(178) << char(178) << char(178) << char(178) << char(177);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 17 + 58, top + 2 + 20);
	cout << "  "<<char(178) << char(178) << char(178) << char(178) << char(177) << "      " << char(178) << char(178) << char(178) << char(178) << char(177);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 17 + 60, top + 2 + 21);
	cout << char(178) << char(178) << char(178) << char(178) << char(177) << "      " << char(178) << char(178) << char(178) << char(178) << char(177);
	_Common::gotoXY((size / 2) * 4 + left + 4 + 17 + 62, top + 2 + 22);
	cout << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(178) << char(177);
}

void Board::userGuideBoard()
{
	SetColor(0);
	for (int j = (size / 2) * 4 + left + 4 + 98; j <= 200; j++)
	{
		_Common::gotoXY(j, top + 2);
		cout << char(254);
		_Common::gotoXY(j, size - 4 + top + 6);
		cout << char(254);
		_Common::gotoXY(j, size - 4 + top + 26);
		cout << char(254);

	}

	for (int i = top + 2; i < size + top - 2 + 25; i++)
	{
		_Common::gotoXY((size / 2) * 4 + left + 4 + 98, i + top);
		cout << char(254);
		_Common::gotoXY((size / 2) * 4 + left + 4 + 108 + 48, i + top);
		cout << char(254);
		//_Common::gotoXY((size / 2) * 4 + left + 4 + 50 + 106, i + top);
		//cout << char(254);
	}
	for (int i = 0; i < 4; i++) {
		SetColor(i + 10);
		_Common::gotoXY((size / 2) * 4 + left + 4 + 105, top + 2 + 7);
		cout << "             _                               ";
		SetColor(i);
		_Common::gotoXY((size / 2) * 4 + left + 4 + 105, top + 2 + 8);
		cout << "            (_)                              ";
		SetColor(i + 2);
		_Common::gotoXY((size / 2) * 4 + left + 4 + 105, top + 2 + 9);
		cout << " __      __  _   _ __    _ __     ___   _ __ ";
		SetColor(i + 5);
		_Common::gotoXY((size / 2) * 4 + left + 4 + 105, top + 2 + 10);
		cout << " \\ \\ /\\ / / | | | '_ \\  | '_ \\   / _ \\ | '__|";
		SetColor(i + 7);
		_Common::gotoXY((size / 2) * 4 + left + 4 + 105, top + 2 + 11);
		cout << "  \\ V  V /  | | | | | | | | | | |  __/ | |   ";
		SetColor(i + 1);
		_Common::gotoXY((size / 2) * 4 + left + 4 + 105, top + 2 + 12);
		cout << "   \\_/\\_/   |_| |_| |_| |_| |_|  \\___| |_|   ";


		SetColor(i + 3);
		_Common::gotoXY((size / 2) * 4 + left + 4 + 110, top + 25);
		cout << "   ___   _   _   ___   ___    ___ ";
		SetColor(i);
		_Common::gotoXY((size / 2) * 4 + left + 4 + 110, top + 26);
		cout << "  / __| | | | | |_ _| |   \\  | __|";
		SetColor(i + 2);
		_Common::gotoXY((size / 2) * 4 + left + 4 + 110, top + 27);
		cout << " | (_ | | |_| |  | |  | |) | | _| ";
		SetColor(i + 1);
		_Common::gotoXY((size / 2) * 4 + left + 4 + 110, top + 28);
		cout << "  \\___|  \\___/  |___| |___/  |___|";

		SetColor(i++);
		_Common::gotoXY((size / 2) * 4 + left + 4 + 120, top + 32);
		cout << "W:\tMOVE UP";
		SetColor(i++);
		_Common::gotoXY((size / 2) * 4 + left + 4 + 120, top + 33);
		cout << "S:\tMOVE DOWN";
		SetColor(i++);
		_Common::gotoXY((size / 2) * 4 + left + 4 + 120, top + 34);
		cout << "A:\tMOVE LEFT";
		SetColor(i++);
		_Common::gotoXY((size / 2) * 4 + left + 4 + 120, top + 35);
		cout << "D:\tMOVE RIGHT";
		SetColor(i++);
		_Common::gotoXY((size / 2) * 4 + left + 4 + 120, top + 36);
		cout << "ENTER:\tCHOOSE";
		SetColor(i++);
		_Common::gotoXY((size / 2) * 4 + left + 4 + 120, top + 37);
		cout << "ESC:\tMENU";
	}
	

}

void Board::menuBoard()
{
	// viền ngang và 4 góc
	for (int j = 99; j <= 113; j++)
	{
		//1.Start game
		//SetColor(j);
		_Common::gotoXY(j, 18);
		cout << char(205);
		_Common::gotoXY(j, 20);
		cout << char(205);
		_Common::gotoXY(98, 18);
		cout << char(201);
		_Common::gotoXY(98, 20);
		cout << char(200);
		_Common::gotoXY(114, 18);
		cout << char(187);
		_Common::gotoXY(114, 20);
		cout << char(188);

		//2.Load game
		//SetColor(j + 1);
		_Common::gotoXY(j, 21);
		cout << char(205);
		_Common::gotoXY(j, 23);
		cout << char(205);
		_Common::gotoXY(98, 21);
		cout << char(201);
		_Common::gotoXY(98, 23);
		cout << char(200);
		_Common::gotoXY(114, 21);
		cout << char(187);
		_Common::gotoXY(114, 23);
		cout << char(188);

		//3. About
		//SetColor(j + 2);
		_Common::gotoXY(j, 24);
		cout << char(205);
		_Common::gotoXY(j, 26);
		cout << char(205);
		_Common::gotoXY(98, 24);
		cout << char(201);
		_Common::gotoXY(98, 26);
		cout << char(200);
		_Common::gotoXY(114, 24);
		cout << char(187);
		_Common::gotoXY(114, 26);
		cout << char(188);

		//4. Help
		//SetColor(j + 3);
		_Common::gotoXY(j, 27);
		cout << char(205);
		_Common::gotoXY(j, 29);
		cout << char(205);
		_Common::gotoXY(98, 27);
		cout << char(201);
		_Common::gotoXY(98, 29);
		cout << char(200);
		_Common::gotoXY(114, 27);
		cout << char(187);
		_Common::gotoXY(114, 29);
		cout << char(188);

		//5. Exit
		//SetColor(j + 4);
		_Common::gotoXY(j, 30);
		cout << char(205);
		_Common::gotoXY(j, 32);
		cout << char(205);
		_Common::gotoXY(98, 30);
		cout << char(201);
		_Common::gotoXY(98, 32);
		cout << char(200);
		_Common::gotoXY(114, 30);
		cout << char(187);
		_Common::gotoXY(114, 32);
		cout << char(188);
		//Sleep(15);
	}


	//viền dọc
	for (int i = 19; i < 20; i++)
	{
		//1.Start game
		_Common::gotoXY(98, i);
		cout << char(186);
		_Common::gotoXY(114, i);
		cout << char(186);

		//2.Load game
		_Common::gotoXY(98, i + 3);
		cout << char(186);
		_Common::gotoXY(114, i + 3);
		cout << char(186);

		//3. About
		_Common::gotoXY(98, i + 6);
		cout << char(186);
		_Common::gotoXY(114, i + 6);
		cout << char(186);

		//4. Help
		_Common::gotoXY(98, i + 9);
		cout << char(186);
		_Common::gotoXY(114, i + 9);
		cout << char(186);

		//5. Exit
		_Common::gotoXY(98, i + 12);
		cout << char(186);
		_Common::gotoXY(114, i + 12);
		cout << char(186);
		//Sleep(15);
	}
}

void Board::GroupBoard()
{
	SetColor(12);
	_Common::gotoXY(30,5);
	cout << "                   (         )      (      (         )                                               )                                *               ";

	_Common::gotoXY(30, 6);
	cout << "   (       (       )\\ )   ( /(      )\\ )   )\\ )   ( /(                   (      *   )       (     ( /(      *   )           (       (  `           )  ";

	_Common::gotoXY(30, 7);
	cout << "   )\\      )\\     (()/(   )\\())    (()/(  (()/(   )\\())     (    (       )\\   ` )  /(     ( )\\    )\\())   ` )  /(   (       )\\      )\\))(       ( /(  ";

	_Common::gotoXY(30, 8);
	cout << " (((_)  ((((_)(    /(_)) ((_)\\      /(_))  /(_)) ((_)\\      )\\   )\\    (((_)   ( )(_))    )((_)  ((_)\\     ( )(_))  )\\   ((((_)(   ((_)()\\      )\\()) ";

	_Common::gotoXY(30, 9);
	cout << " )\\___   )\\ _ )\\  (_))     ((_)    (_))   (_))     ((_)    ((_) ((_)   )\\___  (_(_())    ((_)_  __ ((_)   (_(_())  ((_)   )\\ _ )\\  (_()((_)    ((_)\\  ";

	SetColor(6);
	_Common::gotoXY(30, 10);
	cout << "((/ __|  (_)_\\(_) | _ \\   / _ \\    | _ \\  | _ \\   / _ \\   _ | | | __| ((/ __| |_   _|     | _ ) \\ \\ / /   |_   _|  | __|  (_)_\\(_) |  \\/  |   | | (_) ";

	_Common::gotoXY(30, 11);
	cout << " | (__    / _ \\   |   /  | (_) |   |  _/  |   /  | (_) | | || | | _|   | (__    | |       | _ \\  \\ V /      | |    | _|    / _ \\   | |\\/| |   |_  _|  ";

	_Common::gotoXY(30, 12);
	cout << "  \\___|  /_/ \\_\\  |_|_\\   \\___/    |_|    |_|_\\   \\___/   \\__/  |___|   \\___|   |_|       |___/   |_|       |_|    |___|  /_/ \\_\\  |_|  |_|     |_|   ";

	for (int j = 70; j <= 140; j++)
	{
		SetColor(14);
		//19127161 - Nguyen Quang Huy
		_Common::gotoXY(j, 18);
		cout << char(205);
		_Common::gotoXY(j, 20);
		cout << char(196);
		_Common::gotoXY(69, 18);
		cout << char(213);
		_Common::gotoXY(69, 20);
		cout << char(192);
		_Common::gotoXY(141, 18);
		cout << char(187);
		_Common::gotoXY(141, 20);
		cout << char(189);
		SetColor(3);
		_Common::gotoXY(92, 19);
		cout << "19127161 - Nguyen Quang Huy (Leader) ";
		
		//cout << "";

		SetColor(14);
		//19127103 - Nguyen Thai Binh
		_Common::gotoXY(j, 21);
		cout << char(205);
		_Common::gotoXY(j, 23);
		cout << char(196);
		_Common::gotoXY(69, 21);
		cout << char(213);
		_Common::gotoXY(69, 23);
		cout << char(192);
		_Common::gotoXY(141, 21);
		cout << char(187);
		_Common::gotoXY(141, 23);
		cout << char(189);
		_Common::gotoXY(92, 22);
		cout << "19127103 - Nguyen Thai Binh";


		//19127011 - Nguyen Quoc Bao
		_Common::gotoXY(j, 24);
		cout << char(205);
		_Common::gotoXY(j, 26);
		cout << char(196);
		_Common::gotoXY(69, 24);
		cout << char(213);
		_Common::gotoXY(69, 26);
		cout << char(192);
		_Common::gotoXY(141, 24);
		cout << char(187);
		_Common::gotoXY(141, 26);
		cout << char(189);
		_Common::gotoXY(92, 25);
		cout << "19127011 - Nguyen Quoc Bao";


		//19127033 - Trinh Anh Khoa
		_Common::gotoXY(j, 27);
		cout << char(205);
		_Common::gotoXY(j, 29);
		cout << char(196);
		_Common::gotoXY(69, 27);
		cout << char(213);
		_Common::gotoXY(69, 29);
		cout << char(192);
		_Common::gotoXY(141, 27);
		cout << char(187);
		_Common::gotoXY(141, 29);
		cout << char(189);
		_Common::gotoXY(92, 28);
		cout << "19127033 - Trinh Anh Khoa";

	}


	for (int i = 19; i < 20; i++)
	{
		//19127161 - Nguyen Quang Huy
		_Common::gotoXY(69, i);
		cout << char(179);
		_Common::gotoXY(141, i);
		cout << char(186);

		//19127103 - Nguyen Thai Binh
		_Common::gotoXY(69, i + 3);
		cout << char(179);
		_Common::gotoXY(141, i + 3);
		cout << char(186);

		//19127011 - Nguyen Quoc Bao
		_Common::gotoXY(69, i + 6);
		cout << char(179);
		_Common::gotoXY(141, i + 6);
		cout << char(186);

		//19127033 - Trinh Anh Khoa
		_Common::gotoXY(69, i + 9);
		cout << char(179);
		_Common::gotoXY(141, i + 9);
		cout << char(186);

	}
}

void Board::HelpBoard()
{
	system("color F0");
	SetColor(12);
	_Common::gotoXY(50, 5);
	cout << "  _   _      U  ___ u                     _____      U  ___ u       ____       _          _        __   __ ";
	_Common::gotoXY(50, 6);
	cout << " |'| |'|      \\/ _ \\/  __        __      |_   _|      \\/ _ \\/     U|  _ \\ u   | |     U  / \\  u    \\ \\ / / ";
	_Common::gotoXY(50, 7);
	cout << "/| |_| |\\     | | | |  \\ \\      / /        | |        | | | |     \\| |_) |/ U | | u    \\/ _ \\/      \\ V / "; 
	_Common::gotoXY(50, 8);
	cout << "U|  _  |u .-,_| |_| |  /\\ \\ /\\ / /\\       /| |\\   .-,_| |_| |      |  __/    \\| |/__   / ___ \\     U_| |_u "; 
	_Common::gotoXY(50, 9);
	cout << " |_| |_|   \\_)-\\___/  U  \\ V  V /  U     u |_|U    \\_)-\\___/       |_|        |_____| /_/   \\_\\      |_|   "; 
	_Common::gotoXY(50, 10);
	cout << " //   \\\\        \\\\    .-,_\\ /\\ /_,-.     _// \\\\_        \\\\         ||>>_      //  \\\\   \\\\    >>  .-,//|(_  "; 
	_Common::gotoXY(50, 11);
	cout << "(_') ('_)      (__)    \\_)-'  '-(_/     (__) (__)      (__)       (__)__)    (_')('_) (__)  (__)  \\_) (__) ";


	for (int j = 80; j <= 130; j++)
	{
		SetColor(0);
		_Common::gotoXY(j, 17);
		cout << char(205);
		_Common::gotoXY(j, 32);
		cout << char(205);
		_Common::gotoXY(79, 17);
		cout << char(201);
		_Common::gotoXY(79, 32);
		cout << char(200);
		_Common::gotoXY(131, 17);
		cout << char(187);
		_Common::gotoXY(131, 32);
		cout << char(188);
		SetColor(j);
		_Common::gotoXY(95, 19);
		cout << "A:\tMOVE LEFT";
		SetColor(j + 1);
		_Common::gotoXY(95, 21);
		cout << "D:\tMOVE RIGHT";
		SetColor(j + 2);
		_Common::gotoXY(95, 23);
		cout << "W:\tMOVE UP";
		SetColor(j + 3);
		_Common::gotoXY(95, 25);
		cout << "S:\tMOVE DOWN";
		SetColor(j + 4);
		_Common::gotoXY(95, 27);
		cout << "ENTER:\tCHOOSE";
		SetColor(j + 9);
		_Common::gotoXY(95, 29);
		cout << "ESC:\tMENU";
	}

	SetColor(0);
	for (int i = 18; i < 32; i++)
	{
		_Common::gotoXY(79, i);
		cout << char(186);
		_Common::gotoXY(131, i);
		cout << char(186);
	}
}

void Board::LoadGameBoard()
{
	SetColor(10);
	_Common::gotoXY(62, 4);
	cout << "   _                            _                ___                              ";
	SetColor(13);
	_Common::gotoXY(62, 5);
	cout << "  | |       ___     __ _     __| |      o O O   / __|    __ _     _ __      ___   ";
	SetColor(11);
	_Common::gotoXY(62, 6);
	cout << "  | |__    / _ \\   / _` |   / _` |     o       | (_ |   / _` |   | '  \\    / -_)  ";
	SetColor(12);
	_Common::gotoXY(62, 7);
	cout << "  |____|   \\___/   \\__,_|   \\__,_|    TS__[O]   \\___|   \\__,_|   |_|_|_|   \\___|  ";
	SetColor(3);
	_Common::gotoXY(62, 8);
	cout << "_|*****| _|*****| _|*****| _|*****|  {======| _|*****| _|*****| _|*****| _|*****| ";
	SetColor(14);
	_Common::gotoXY(62, 9);
	cout << "'`-0-0-' '`-0-0-' '`-0-0-' '`-0-0-' ./o--000' '`-0-0-' '`-0-0-' '`-0-0-' '`-0-0-' ";

	_Common::gotoXY(90, 14);
	cout << "DANH SACH NGUOI CHOI";
	string name;
	int line=15;
	int n = 1;
	while (getline(file,name))
	{	
		string tmp;
		tmp = name.substr(0);
		_Common::gotoXY(100, line);
		cout<<n <<" - " << tmp;
		line++;
		++n;
	}

	SetColor(6);
	_Common::gotoXY(65, line+5);
	cout << "   .-')      .-')      .-')      .-')      .-')      .-')      .-')      .-')   ";
	SetColor(6);
	_Common::gotoXY(65, line+6);
	cout << " _(  OO)   _(  OO)   _(  OO)   _(  OO)   _(  OO)   _(  OO)   _(  OO)   _(  OO)  ";
	SetColor(6);
	_Common::gotoXY(65,line +7);
	cout << "(,------. (,------. (,------. (,------. (,------. (,------. (,------. (,------. ";
	SetColor(6);
	_Common::gotoXY(65, line+8);
	cout << " '------'  '------'  '------'  '------'  '------'  '------'  '------'  '------' ";
}

Board::~Board() {
	for (int i = 0; i < size; i++) delete[] B[i];
	delete[] B;
	file.close();
}
void Board::loadData(int i, int j, int k)
{
	if (size == 0) return;
	B[i][j].setX(4 * j + left + 2);
	B[i][j].setY(2 * i + top + 1);
	B[i][j].setStatus(k);
	if (k == -1)
	{
		SetColor(9);
		_Common::gotoXY(4 * j + left + 2, 2 * i + top + 1);
		cout << "X";
		CountX++;
	}
	if (k == 1)
	{
		SetColor(10);	
		_Common::gotoXY(4 * j + left + 2, 2 * i + top + 1);
		cout << "O";
		CountY++;
	}

}
