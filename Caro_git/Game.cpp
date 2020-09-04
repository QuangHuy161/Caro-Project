#include"Game.h"

Game::Game() {
    _Board.resetData();
    _Board.drawBoard();
    _Board.userBoard_1();
    _Board.userBoard_2();
    _Board.userGuideBoard();
    left = _Board.getLeft();
    top = _Board.getTop();
    size = _Board.getSize();
    //center of __Board game
    xMidRect = _Board.getXAt(10, 10);
    yMidRect = _Board.getYAt(10, 10);
    _Common::gotoXY(xMidRect + 2, yMidRect + 1);
	_turn = true;
}
void Game::startGame() {
    while (true)
    {
    x:
        {
            while (true)
            {
                int p = _getch();
                if (p == 115)moveDown();
                if (p == 119)moveUp();
                if (p == 97)moveLeft();
                if (p == 100)moveRight();
                if (p == 27) {
                    system("cls");
                    break;
                }
                if (p == 13)
                    //when press "ENTER" check coordinate at rectangle was imported or wasn't imported
                    //if not printed (status at i,j)=0 else status = 1 or status=-1
                    if (_Board.getStatusAt((xMidRect - left - 4) / 4, (yMidRect - top - 2) / 2) == 0)
                    {
                        //when status=0 then mark -1 at coordinate  when printing X
                        _Board.setStausAt((xMidRect - left - 4) / 4, (yMidRect - top - 2) / 2, -1);
                        SetColor(12);
                        cout << "X";
                        _Common::gotoXY((size / 2) * 4 + left + 4 + 57 + 10, top + 2 + 13);
                        cout << ++_Board.score_1;
                        Beep(885, 100);
                        if (checkWinRow() || checkWinCol() || checkDiagonalMain() || checkDiagonalSub()) {
                            PlaySound(L"winSound", NULL, SND_ASYNC);
                            for(int i=3;i<15;i++){
                                SetColor(i);
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 7);
                                cout << " " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "        " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << "     " << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 8);
                                cout << "  " << char(219) << char(219) << char(219) << char(186) << "    " << char(219) << char(219) << char(219) << char(186) << "       " << char(219) << char(219) << char(219) << char(186) << "        " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(219) << char(219) << "    " << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 9);
                                cout << "    " << char(219) << char(219) << char(219) << "  " << char(219) << char(219) << char(219) << char(186) << "        " << char(219) << char(219) << char(219) << char(186) << "        " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << char(219) << char(219) << "   " << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 10);
                                cout << "      " << char(219) << char(219) << char(219) << char(219) << char(186) << "          " << char(219) << char(219) << char(219) << char(186) << "   " << char(219) << char(186) << "   " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << " " << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 11);
                                cout << "    " << char(219) << char(219) << char(219) << "  " << char(219) << char(219) << char(219) << char(186) << "        " << char(219) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << "   " << char(219) << char(219) << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 12);
                                cout << "  " << char(219) << char(219) << char(219) << char(186) << "    " << char(219) << char(219) << char(219) << char(186) << "        " << char(219) << char(219) << char(219) << " " << char(219) << char(219) << char(219) << char(219) << char(219) << " " << char(219) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << "    " << char(219) << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 13);
                                cout << " " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "        " << char(219) << char(219) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << char(219) << char(219) << char(186) << "   " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << "     " << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 14);
                                cout << " " << char(200) << char(205) << char(205) << char(188) << "      " << char(200) << char(205) << char(205) << char(188) << "        " << char(200) << char(205) << char(205) << char(205) << char(188) << "  " << char(200) << char(205) << char(205) << char(205) << char(188) << "   " << char(200) << char(205) << char(205) << char(188) << " " << char(200) << char(205) << char(205) << char(188) << "     " << char(200) << char(205) << char(205) << char(188);
                                Sleep(100);
                            }
                            while (true)
                            {
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 7);
                                cout << " " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "        " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << "     " << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 8);
                                cout << "  " << char(219) << char(219) << char(219) << char(186) << "    " << char(219) << char(219) << char(219) << char(186) << "       " << char(219) << char(219) << char(219) << char(186) << "        " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(219) << char(219) << "    " << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 9);
                                cout << "    " << char(219) << char(219) << char(219) << "  " << char(219) << char(219) << char(219) << char(186) << "        " << char(219) << char(219) << char(219) << char(186) << "        " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << char(219) << char(219) << "   " << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 10);
                                cout << "      " << char(219) << char(219) << char(219) << char(219) << char(186) << "          " << char(219) << char(219) << char(219) << char(186) << "   " << char(219) << char(186) << "   " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << " " << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 11);
                                cout << "    " << char(219) << char(219) << char(219) << "  " << char(219) << char(219) << char(219) << char(186) << "        " << char(219) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << "   " << char(219) << char(219) << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 12);
                                cout << "  " << char(219) << char(219) << char(219) << char(186) << "    " << char(219) << char(219) << char(219) << char(186) << "        " << char(219) << char(219) << char(219) << " " << char(219) << char(219) << char(219) << char(219) << char(219) << " " << char(219) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << "    " << char(219) << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 13);
                                cout << " " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "        " << char(219) << char(219) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << char(219) << char(219) << char(186) << "   " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << "     " << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 14);
                                cout << " " << char(200) << char(205) << char(205) << char(188) << "      " << char(200) << char(205) << char(205) << char(188) << "        " << char(200) << char(205) << char(205) << char(205) << char(188) << "  " << char(200) << char(205) << char(205) << char(205) << char(188) << "   " << char(200) << char(205) << char(205) << char(188) << " " << char(200) << char(205) << char(205) << char(188) << "     " << char(200) << char(205) << char(205) << char(188);
                                if (_getch())break;
                            }
                            system("cls");
                            break;
                        }
                        _Common::gotoXY(xMidRect + 2, yMidRect + 1);
                        goto o;
                    }
            }
            break;
        }
    o:
        {
            while (true)
            {
                int p = _getch();
                if (p == 115)moveDown();
                if (p == 119)moveUp();
                if (p == 97)moveLeft();
                if (p == 100)moveRight();
                if (p == 27) {
                    system("cls");
                    break;
                }
                //when press "ENTER" check coordinate at rectangle was imported or wasn't imported
                //if not printed (status at i,j)=0 else status = 1 or status=-1
                if (p == 13)
                    if (_Board.getStatusAt((xMidRect - left - 4) / 4, (yMidRect - top - 2) / 2) == 0)
                    {
                        //when status=0 then mark -1 at coordinate  when printing X
                        _Board.setStausAt((xMidRect - left - 4) / 4, (yMidRect - top - 2) / 2, 1);
                        SetColor(16);
                        cout << "O";
                        _Common::gotoXY((size / 2) * 4 + left + 4 + 57 + 10, top + 2 + 37);
                        cout << ++_Board.score_2;

                        Beep(990, 100);
                        if (checkWinRow() || checkWinCol() || checkDiagonalMain() || checkDiagonalSub()) {
                            PlaySound(L"winSound", NULL, SND_ASYNC);
                            for (int i = 14; i < 28; i++) {
                                SetColor(i);
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 7);
                                cout << "   " << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(186) << "        " << char(219) << char(219) << char(219) << char(186) << "        " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << "     " << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 8);
                                cout << " " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "        " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(219) << char(219) << "    " << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 9);
                                cout << " " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "        " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << char(219) << char(219) << "   " << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 10);
                                cout << " " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "   " << char(219) << char(186) << "   " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << " " << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 11);
                                cout << " " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << "   " << char(219) << char(219) << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 12);
                                cout << " " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "       " << char(219) << char(219) << char(219) << " " << char(219) << char(219) << char(219) << char(219) << char(219) << " " << char(219) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << "    " << char(219) << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 13);
                                cout << "   " << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(186) << "          " << char(219) << char(219) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << char(219) << char(219) << char(186) << "   " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << "     " << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 14);
                                cout << "   " << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << "          " << char(200) << char(205) << char(205) << char(205) << char(188) << "  " << char(200) << char(205) << char(205) << char(205) << char(188) << "   " << char(200) << char(205) << char(205) << char(188) << " " << char(200) << char(205) << char(205) << char(188) << "     " << char(200) << char(205) << char(205) << char(188);
                                Sleep(100);
                            }
                            while (true)
                            {
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 7);
                                cout << "   " << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(186) << "        " << char(219) << char(219) << char(219) << char(186) << "        " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << "     " << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 8);
                                cout << " " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "        " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(219) << char(219) << "    " << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 9);
                                cout << " " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "        " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << char(219) << char(219) << "   " << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 10);
                                cout << " " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "   " << char(219) << char(186) << "   " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << " " << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 11);
                                cout << " " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << "   " << char(219) << char(219) << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 12);
                                cout << " " << char(219) << char(219) << char(219) << char(186) << "      " << char(219) << char(219) << char(219) << char(186) << "       " << char(219) << char(219) << char(219) << " " << char(219) << char(219) << char(219) << char(219) << char(219) << " " << char(219) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << "    " << char(219) << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 13);
                                cout << "   " << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(186) << "          " << char(219) << char(219) << char(219) << char(219) << char(186) << "  " << char(219) << char(219) << char(219) << char(219) << char(186) << "   " << char(219) << char(219) << char(219) << char(186) << " " << char(219) << char(219) << char(219) << char(186) << "     " << char(219) << char(219) << char(219) << char(186) << endl;
                                _Common::gotoXY((size / 2) * 4 + left + 4 + 99, top + 2 + 14);
                                cout << "   " << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << "          " << char(200) << char(205) << char(205) << char(205) << char(188) << "  " << char(200) << char(205) << char(205) << char(205) << char(188) << "   " << char(200) << char(205) << char(205) << char(188) << " " << char(200) << char(205) << char(205) << char(188) << "     " << char(200) << char(205) << char(205) << char(188);
                                if (_getch())break;
                            }
                            system("cls");
                            break;
                        }
                        _Common::gotoXY(xMidRect + 2, yMidRect + 1);
                        goto x;
                    }
            }
            break;
        }
    }
}

void Game::moveDown() {
    //Pointer just move when isn't not move over border bottom
    if (yMidRect + 2 <= (size - 1) * 2 + top + 2) {
        _Common::gotoXY(xMidRect + 2, yMidRect + 2 + 1);
        yMidRect += 2;
    }
}
void Game::moveUp() {
    //Pointer just move when isn't not move over border top
    if (yMidRect - 2 >= top + 2) {
        _Common::gotoXY(xMidRect + 2, yMidRect - 2 + 1);
        yMidRect -= 2;
    }
}
void Game::moveLeft() {
    //Pointer just move when isn't not move over border left
    if (xMidRect - 4 >= left + 4) {
        _Common::gotoXY(xMidRect - 4 + 2, yMidRect + 1);
        xMidRect -= 4;
    }
}
void Game::moveRight() {
    //Pointer just move when isn't not move over border right
    if (xMidRect + 4 <= (size - 1) * 4 + left + 4) {
        _Common::gotoXY(xMidRect + 4 + 2, yMidRect + 1);
        xMidRect += 4;
    }
}
bool Game::checkWinRow() {
    int row = (yMidRect - top - 2) / 2;
    int r, l;
    l = r = (xMidRect - left - 4) / 4;
    int countL = 0, countR = 0;
    //status at coordinate(xMidRect,yMidRect)
    int status = _Board.getStatusAt((xMidRect - left - 4) / 4, (yMidRect - top - 2) / 2);//1 or -1
    while (_Board.getStatusAt(l - 1, row) == status)
    {
        ++countL;
        --l;
    }
    while (_Board.getStatusAt(r + 1, row) == status)
    {
        ++countR;
        ++r;
    }
    if (countL + countR >= 4)return true;
    else return false;
}
bool Game::checkWinCol() {
    int col = (xMidRect - left - 4) / 4;
    int a, u;//above under
    a = u = (yMidRect - top - 2) / 2;
    int countA = 0, countU = 0;
    int status = _Board.getStatusAt((xMidRect - left - 4) / 4, (yMidRect - top - 2) / 2);
    while (_Board.getStatusAt(col, a - 1) == status)
    {
        ++countA;
        --a;
    }
    while (_Board.getStatusAt(col, u + 1) == status)
    {
        ++countU;
        ++u;
    }
    if (countA + countU >= 4)return true;
    else return false;
}
bool Game::checkDiagonalMain() {
    int leftYMain, rightYMain, leftXMain, rightXMain, countLT = 0, countRB = 0;
    rightXMain = leftXMain = (xMidRect - left - 4) / 4;
    rightYMain = leftYMain = (yMidRect - top - 2) / 2;
    int status = _Board.getStatusAt((xMidRect - left - 4) / 4, (yMidRect - top - 2) / 2);
    while (_Board.getStatusAt(leftXMain - 1, leftYMain - 1) == status)
    {
        ++countLT;
        --leftXMain;
        --leftYMain;
    }
    while (_Board.getStatusAt(rightXMain + 1, rightYMain + 1) == status)
    {
        ++countRB;
        ++rightXMain;
        ++rightYMain;
    }
    if (countLT + countRB >= 4)return true;
    else return false;
}
bool Game::checkDiagonalSub() {

    int leftYSub, rightYSub, leftXSub, rightXSub, countRT = 0, countLB = 0;
    rightXSub = leftXSub = (xMidRect - left - 4) / 4;
    rightYSub = leftYSub = (yMidRect - top - 2) / 2;
    int status = _Board.getStatusAt((xMidRect - left - 4) / 4, (yMidRect - top - 2) / 2);
    //tren
    while (_Board.getStatusAt(rightXSub + 1, rightYSub - 1) == status)
    {
        ++countRT;
        ++rightXSub;
        --rightYSub;
    }
    //duoi
    while (_Board.getStatusAt(leftXSub - 1, leftYSub + 1) == status)
    {
        ++countLB;
        --leftXSub;
        ++leftYSub;
    }
    if (countRT + countLB >= 4)return true;
    else return false;
}
Game::~Game()
{
}

void Game::setCountXY()
{
    _Board.CountX = 0;
    _Board.CountY = 0;
}

int Game::DemNuocCoDaDi()
{
    return _Board.CountX + _Board.CountY;
}


