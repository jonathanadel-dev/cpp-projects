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


// My ATOI
int myAtoi(string s) {

    int number = 0, sign = 1;
    bool isNumberFound = false;

    auto toNumber = [](char c) {

        int number = -1;

        switch (c) {
        case '0': number = 0; break;
        case '1': number = 1; break;
        case '2': number = 2; break;
        case '3': number = 3; break;
        case '4': number = 4; break;
        case '5': number = 5; break;
        case '6': number = 6; break;
        case '7': number = 7; break;
        case '8': number = 8; break;
        case '9': number = 9; break;
        }

        return number;

        };

    auto addNumber = [&](char c) {
        if (
            number > 0 && (
                number > (INT_MAX / 10) || (number * 10) > INT_MAX - toNumber(c)
                )
            ) number = INT_MAX;
        else if (
            number < 0 && (
                number < (INT_MIN / 10) || (number * 10) < INT_MIN + toNumber(c)
                )
            ) number = INT_MIN;
        else {
            number *= 10;
            if (sign == 1) {
                number += toNumber(c);
            }
            else {
                number -= toNumber(c);
            }
        }
        };

    for (int i = 0; i < s.size(); i++) {

        if (number == INT_MAX || number == INT_MIN) return number;

        if (isNumberFound) {

            if (toNumber(s[i]) == -1) break;
            else {
                addNumber(s[i]);
            }

        }
        else {

            if (toNumber(s[i]) != -1) {
                isNumberFound = true;
                addNumber(s[i]);
            }
            else if (s[i] == '-' && i < s.size() - 1 && toNumber(s[i + 1]) != -1) {
                isNumberFound = true;
                sign = -1;
            }
            else if (s[i] == ' ') continue;
            else if (s[i] == '+' && i < s.size() - 1 && toNumber(s[i + 1]) != -1) continue;
            else return 0;

        }

    }

    return number;

}


// Count substrings
long long countSubstrings(string s) {
    int n = s.size();
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int freq[10] = { 0 };
        int odd = 0;

        for (int j = i; j < n; j++) {
            int c = s[j] - 'a';
            freq[c]++;
            if (freq[c] % 2 == 1) odd++;
            else odd--;

            if (odd <= 1) ans++;
        }
    }
    return ans;
}


// Longest palindrome
string longestPalindrome(string s) {

    string t = "#";
    for (auto c : s) {
        t += c;
        t += "#";
    }

    int n = t.size();
    vector<int> r(n, 0);
    int center = 0, right = 0, bestCenter = 0, bestLength = 0;

    for (int i = 0; i < n; i++) {

        if (i < right) r[i] = min(r[2 * center - i], right - i);

        while (
            i - r[i] - 1 >= 0 &&
            i + r[i] + 1 < n &&
            t[i - r[i] - 1] == t[i + r[i] + 1]
            ) r[i]++;

        if (i + r[i] > right) {
            center = i;
            right = i + r[i];
        }

        if (r[i] > bestLength) {
            bestCenter = i;
            bestLength = r[i];
        }

    }

    return s.substr((bestCenter - bestLength) / 2, bestLength);

}


// Beauty sum
int beautySum(string s) {

    int n = s.size(), sum = 0;

    for (int i = 0; i < n; i++) {
        vector<int> freq(26, 0);
        for (int j = i; j < n; j++) {

            freq[s[j] - 97]++;

            int minimum = INT_MAX, maximum = INT_MIN;

            for (int k = 0; k < freq.size(); k++) {
                if (freq[k] != 0) minimum = min(minimum, freq[k]);
                maximum = max(maximum, freq[k]);
            }

            sum += maximum - minimum;

        }
    };

    return sum;

}