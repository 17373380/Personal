#include "main.h"

Line::Line(int x1, int y1, int x2, int y2) {
	if (x1 == x2) {
		this->a = 1;
		this->b = 0;
		this->c = -x1;
	}
	else if (y1 == y2) {
		this->a = 0;
		this->b = 1;
		this->c = -y1;
	}
	else {
		this->a = y2 - y1;
		this->b = x1 - x2;
		this->c = y1 * x2 - y2 * x1;
	}
}

Line::~Line(){

}

void Line::printLine() {
	cout << this->a << "*x+" 
		<< this->b << "*y+" 
		<< this->c << "=0" << endl;
}