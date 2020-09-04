#include"coordinate.h"

Coordinate::Coordinate()
{
	x = y = status = 0;
}
Coordinate::Coordinate(int cX, int cY, int st) {
	x = cX;
	y = cY;
	status = st;
}

void Coordinate::setX(int _x) { x = _x; }
void Coordinate::setY(int _y) { y = _y; }
int Coordinate::getX() { return x; }
int Coordinate::getY() { return y; }

bool Coordinate::setStatus(int _status) {
	if (_status == 0 || _status == 1 || _status == -1) {
		status = _status;
		return true;
	}
	return false;
}

int Coordinate::getStatus() {
	return status;
}

Coordinate::~Coordinate()
{
}
