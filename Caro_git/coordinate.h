#pragma once
class Coordinate
{
public:
	Coordinate();
	Coordinate(int cX, int cY,int st);
	~Coordinate();
	int getX();
	int getY();
	void setX(int _x);
	void setY(int _y);
	bool setStatus(int _status);
	int getStatus();
private:
	int x, y,status;
};
