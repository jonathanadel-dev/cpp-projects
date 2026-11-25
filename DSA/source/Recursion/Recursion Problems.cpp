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