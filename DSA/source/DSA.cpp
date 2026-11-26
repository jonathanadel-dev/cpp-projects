#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include "../Headers/Globals.h"
using namespace std;


int main()
{
	vector<string> strings = generateABStrings(4);

	for (string s : strings) {
		cout << s << endl;
	}

}