#include "main.h"

set<pair<double, double>> lineTable;
set<pair<double, double>> pointTable;

int crossCount = 0;

int str2int(string now) {
	int n = int(now.length());
	int num = 0;
	int i = 0;
	while (i < n) {
		num = num * 10 + now[i] - '0';
		i++;
	}
	return num;
}


int main(int argc, char** argv)
{
	ifstream in;
	ofstream out;
	int i;
	for (i = 0; i < argc; i++) {
		if ((string)argv[i] == "-i") {
			in.open(argv[i + 1]);
		}
		else if ((string)argv[i] == "-o") {
			out.open(argv[i + 1]);
		}
	}

	string temp;
	int lines = 0;
	int x1, x2, y1, y2;
	string type;
	Container container;

	if (getline(in, temp)) {
		lines = str2int(temp);
	}
	//cout << lines << endl;
	for (i = 0; i < lines; i++) {
		in >> type;
		if (type == "L") {
			in >> x1 >> y1 >> x2 >> y2;
			Line *tempLine = new Line(x1, y1, x2, y2);
			container.getNewCross(tempLine);
		}
	}
	in.close();
	out << container.getCrossNum();
	/*cout << endl;
	container.printLineSet();
	cout << endl;
	container.printCrossSet();*/
	

	return 0;

}