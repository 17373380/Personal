#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <utility>
using namespace std;

class Line {
public:
	int a;
	int b;
	int c;
	Line(int x1, int y1, int x2, int y2);
	~Line();
	void printLine();
};

class Cross {
public:
	int numX;
	int denX;
	int numY;
	int denY;
	Cross(Line *line1, Line *line2);
	~Cross();
	bool operator ==(const Cross&) const;
	bool operator >(const Cross&) const;
	bool operator <(const Cross&) const;
	void printCross();

};

class Container {
public:
	vector<Line*> *lineSet = new vector<Line*>(); //= new set<Line>();
	set<Cross> *crossSet = new set<Cross>();
	Container();
	~Container();
	void addLine(Line *line);
	void getNewCross(Line *nLIne);
	int getCrossNum();
	void printLineSet();
	void printCrossSet();
};