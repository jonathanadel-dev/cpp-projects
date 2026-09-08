#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include "../Headers/Globals.h"
using namespace std;


int main()
{

	vector<int> nums = { 4, 5, 6, 7, 0, 1, 2, 3 };

	cout << findHowManyTimesTheArrayIsRotated(nums);

}