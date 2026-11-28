#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
#include <stack>
#include <functional>
#include <algorithm>
#include "../Headers/Globals.h"
using namespace std;


int main()
{

	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	
	reverseStack(st);

	for (int i = 0; i < 5; i++) {
		cout << st.top() << " ";
		st.pop();
	}

}