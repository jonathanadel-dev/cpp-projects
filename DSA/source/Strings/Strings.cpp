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


// Max depth
int maxDepth(string s) {

    int count = 0, maxCount = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            count++;
            maxCount = max(maxCount, count);
        }
        else if (s[i] == ')') count--;
    }

    return maxCount;

}


// Roman to int
int romanToInt(string s) {

    int number = 0;

    auto toNumber = [](char c) {

        int n = 0;
        switch (c) {
        case 'I': n = 1; break;
        case 'V': n = 5; break;
        case 'X': n = 10; break;
        case 'L': n = 50; break;
        case 'C': n = 100; break;
        case 'D': n = 500; break;
        case 'M': n = 1000; break;
        };
        return n;

        };

    for (int i = 0; i < s.size(); i++) {

        if (i < s.size() - 1) {

            if (s[i] == 'I' && s[i + 1] == 'V') {
                number += toNumber('V') - toNumber('I');
                i++;
            }
            else if (s[i] == 'I' && s[i + 1] == 'X') {
                number += toNumber('X') - toNumber('I');
                i++;
            }
            else if (s[i] == 'X' && s[i + 1] == 'L') {
                number += toNumber('L') - toNumber('X');
                i++;
            }
            else if (s[i] == 'X' && s[i + 1] == 'C') {
                number += toNumber('C') - toNumber('X');
                i++;
            }
            else if (s[i] == 'C' && s[i + 1] == 'D') {
                number += toNumber('D') - toNumber('C');
                i++;
            }
            else if (s[i] == 'C' && s[i + 1] == 'M') {
                number += toNumber('M') - toNumber('C');
                i++;
            }
            else {
                number += toNumber(s[i]);
            }

        }
        else {
            number += toNumber(s[i]);
        }

    }

    return number;

}