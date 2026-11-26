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


// Power
double myPow(double x, int n) {

    long long exp = n;
    bool negative = exp < 0;
    if (negative) exp = -exp;

    function<double(double, long long)> power = [&](double base, long long r) -> double {
        if (r == 0) return 1;

        double half = power(base, r / 2);
        if (r % 2 == 0) return half * half;
        return half * half * base;
        };

    double result = power(x, exp);
    return negative ? 1 / result : result;

}


// Generate parentheses
vector<string> generateParenthesis(int n) {

    vector<string> ans;
    string currentString;

    function<void(int, int)> comb = [&](int open, int close) {
        if (currentString.size() == 2 * n) {
            ans.push_back(currentString);
            return;
        }

        if (close < open) {
            currentString.push_back(')');
            comb(open, close + 1);
            currentString.pop_back();
        }

        if (open < n) {
            currentString.push_back('(');
            comb(open + 1, close);
            currentString.pop_back();
        }

        };

    comb(0, 0);

    return ans;

}


// Generate AB strings
vector<string> generateABStrings(int n) {
    vector<string> ans;
    string current = "";

    function<void()> generate = [&]() {

        if (current.size() == n) {
            ans.push_back(current);
            return;
        }

        current.push_back('A');
        generate();
        current.pop_back();

        current.push_back('B');
        generate();
        current.pop_back();

    };

    generate();

    return ans;

}


// Superset
vector<vector<int>> superset(vector<int>& nums) {

    vector<vector<int>> ans;
    vector<int> current;

    function<void(int)> subset = [&](int start) {

        ans.push_back(current);

        for (int i = start; i < nums.size(); i++) {

            current.push_back(nums[i]);
            subset(i + 1);
            current.pop_back();

        }

        };

    subset(0);

    return ans;

}