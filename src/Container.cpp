#include "main.h"
#include "Container.h"

Container::Container() {
	//lineSet = new set<Line*>;
	//crossSet = new set<Cross*>;
}

Container::~Container(){}

void Container::addLine(Line *line) {
	lineSet->push_back(line);
}

bool parallel(Line line1, Line line2) {
	if (line1.a * line2.b == line1.b * line2.a) {
		return 1;
	}
	else {
		return 0;
	}
}

void Container::getNewCross(Line *nline) {
	for (Line* oline : *lineSet) {
		if (!parallel(*oline, *nline)) {
			Cross tempCross(nline, oline);
			crossSet->insert(tempCross);
			/*oline->printLine();
			nline->printLine();
			tempCross.printCross();
			cout << endl;*/
		}
	}
	addLine(nline);
}


int Container::getCrossNum() {
	return int(crossSet->size());
}

void Container::printCrossSet() {
	for (Cross cross : *crossSet) {
		cross.printCross();
	}
}

void Container::printLineSet() {
	for (Line* line : *lineSet) {
		line->printLine();
	}
}