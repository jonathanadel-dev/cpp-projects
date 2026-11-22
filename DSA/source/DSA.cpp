#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include "../Headers/Globals.h"
using namespace std;


int main()
{
	string number = "321";
	cout << next_permutation(number.begin(), number.end());
	//cout << findNthRoot(4, 81);

}