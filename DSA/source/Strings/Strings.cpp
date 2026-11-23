#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
#include <functional>
#include <algorithm>
using namespace std;


// Remove outer parentheses
string removeOuterParentheses(string s) {

    string newString = "";
    int count = 1, openedIndex = 0;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '(') count++;
        else if (s[i] == ')') count--;

        if (count == 0) {
            openedIndex++;
            while (openedIndex < i) newString += s[openedIndex++];
            openedIndex++;
        }

    }

    return newString;

}