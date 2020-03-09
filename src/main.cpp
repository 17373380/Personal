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

void point2line(int x1, int y1, int x2, int y2) {
	int m = 0;
	m = x2 - x1;
	double k, b;
	Line tempLine;
	if (m == 0) {
		k = 200000;
		b = x1;
	} 
	else {
		
		k = (y2 - y1) / (x2 - x1);
		b = y1 - k * x1;
	}
	lineTable.insert(make_pair(k, b));
}

bool getCross(double k1, double b1, double k2, double b2) {
	double x, y;
	if (k1 != k2) {
		if (k1 == 200000) {
			x = b1;
			y = k2 * x + b2;
		} 
		else if (k2 == 200000) {
			x = b2;
			y = k1 * x + b1;
		}
		else {
			x = (b1 - b2) / (k2 - k1);
			y = k1 * x + b1;
		}
		pointTable.insert(make_pair(x, y));

		return true;
	}
	else {
		return false;
	}
}


int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	string temp;
	string istemp;
	int lines = 0;
	int x1, x2, y1, y2;

	if (getline(in, temp)) {
		lines = str2int(temp);
	}
	//cout << lines << endl;
	int i;
	for (i = 0; i < lines; i++) {
		getline(in, temp);
		istringstream is(temp);
		is >> istemp;
		if (istemp[0] == 'L') {
			is >> istemp;
			x1 = str2int(istemp);
			is >> istemp;
			y1 = str2int(istemp);
			is >> istemp;
			x2 = str2int(istemp);
			is >> istemp;
			y2 = str2int(istemp);
			point2line(x1, y1, x2, y2);
		}
	}
	int count = 0;
	set<pair<double, double>>::iterator it1;
	set<pair<double, double>>::iterator it2;
	for (it1 = lineTable.begin(); it1 != lineTable.end(); it1++)
	{
		//cout << it->first;
		//cout << it->second;
		//cout << it1->first << endl;
		//cout << it1->second << endl;

		for (it2 = lineTable.begin(); it2 != lineTable.end(); it2++)
		{
			if (it1 == it2) {
				break;
			}
			count++;
			//cout << count << endl;
			getCross(it1->first, it1->second, it2->first, it2->second);
		}
		
	}

	/*set<pair<double, double>>::iterator it3;
	for (it3 = pointTable.begin(); it3 != pointTable.end(); it3++) {
		cout << it3->first << " " << it3->second << endl;
	}*/

	//cout << endl << "Answer: " << pointTable.size() << endl;
	cout << pointTable.size() << endl;

	return 0;

}