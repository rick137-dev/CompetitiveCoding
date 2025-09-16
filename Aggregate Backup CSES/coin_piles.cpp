#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Problem : https://cses.fi/problemset/task/1754

bool canEmpty(long long a, long long b)
{

    long long y = (2 * b) - a;
    if (y % 3 != 0)
        return false;
    y = y / 3;
    long long x = 2 * a - b;
    if (x % 3 != 0)
    {
        return false;
    }
    x = x / 3;
    return (x >= 0 && y >= 0);
}

int main()
{
    long t;
    cin >> t;
    long long a, b;
    for (long i = 0; i < t; i++)
    {
        cin >> a >> b;
        if (canEmpty(a, b))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}