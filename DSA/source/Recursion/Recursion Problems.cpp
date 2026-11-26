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


// Permute
vector<vector<int>> permute(vector<int>& nums) {

    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> current;
    vector<bool> used(n, false);

    function<void()> p = [&]() {

        if (current.size() == n) {
            ans.push_back(current);
            return;
        }

        for (int i = 0; i < n; i++) {

            if (used[i]) continue;

            used[i] = true;
            current.push_back(nums[i]);

            p();

            used[i] = false;
            current.pop_back();

        }

        };

    p();
    return ans;

}


// Letter combinations
vector<string> letterCombinations(string digits) {

    vector<string> ans;
    string current;


    // Get integer chars
    function<vector<char>(char)> getChars = [&](char number) -> vector<char> {

        vector<char> chars;

        switch (number) {
        case '2':
            chars.push_back('a');
            chars.push_back('b');
            chars.push_back('c');
            break;
        case '3':
            chars.push_back('d');
            chars.push_back('e');
            chars.push_back('f');
            break;
        case '4':
            chars.push_back('g');
            chars.push_back('h');
            chars.push_back('i');
            break;
        case '5':
            chars.push_back('j');
            chars.push_back('k');
            chars.push_back('l');
            break;
        case '6':
            chars.push_back('m');
            chars.push_back('n');
            chars.push_back('o');
            break;
        case '7':
            chars.push_back('p');
            chars.push_back('q');
            chars.push_back('r');
            chars.push_back('s');
            break;
        case '8':
            chars.push_back('t');
            chars.push_back('u');
            chars.push_back('v');
            break;
        case '9':
            chars.push_back('w');
            chars.push_back('x');
            chars.push_back('y');
            chars.push_back('z');
            break;
        }

        return chars;

        };


    // Generate strings
    function<void(int)> generate = [&](int start) {

        if (current.size() == digits.size()) {
            ans.push_back(current);
            return;
        }

        vector<char> chars = getChars(digits[start]);

        for (char c : chars) {
            current.push_back(c);
            generate(start + 1);
            current.pop_back();
        }

        };


    generate(0);
    return ans;

}


// Combination sum
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    vector<vector<int>> ans;
    vector<int> current;

    function<void(int)> sum = [&](int start) {

        // Base case
        int currentSum = 0;
        for (int i = 0; i < current.size(); i++) {
            currentSum += current[i];
            if (currentSum == target) {
                ans.push_back(current);
                return;
            }
            else if (currentSum > target) return;
        }

        for (int i = start; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            sum(i);
            current.pop_back();
        }

        };

    sum(0);
    return ans;

}