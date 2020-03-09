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

struct Line {
	int b = 0;
	int k = 0;

	void printLine() {
		cout << "k:" << k
			<< " b:" << b << endl;
	}
};

struct Cross {
	int x = 0;
	int y = 0;
};