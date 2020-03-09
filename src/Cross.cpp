#include "main.h"

Cross::Cross(Line *line1, Line *line2) {
	this->numX = line1->c * line2->b - line2->c * line1->b;
	this->denX = line1->b * line2->a - line2->b * line1->a;
	this->numY = line1->a * line2->c - line2->a * line1->c;
	this->denY = this->denX;
	if (this->numX < 0 && this->denX < 0) {
		this->numX = -this->numX;
		this->denX = -this->denX;
	}
	if (this->numY < 0 && this->denY < 0) {
		this->numY = -this->numY;
		this->denY = -this->denY;
	}
}

Cross::~Cross() {
	 
}


bool Cross::operator ==(const Cross& cross2) const {
	return (numX * cross2.denX == cross2.numX * denX
		&& numY * cross2.denY == cross2.numY * denY);
}
bool Cross::operator <(const Cross& cross2) const {
	return (numX * cross2.denX < cross2.numX * denX
		|| (numX * cross2.denX == cross2.numX * denX
		&& numY * cross2.denY < cross2.numY * denY));
		
}
bool Cross::operator >(const Cross& cross2) const {
	return (numX * cross2.denX > cross2.numX * denX
		|| (numX * cross2.denX == cross2.numX * denX
		&& numY * cross2.denY > cross2.numY* denY));
		
}

void Cross::printCross() {
	cout << numX << " " << denX << "  " << numY << " " << denY << endl;
	cout << double(numX) / double(denX) << "  " <<double( numY)/double( denY )<< endl;
	cout << endl;
}