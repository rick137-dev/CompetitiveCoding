#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <climits>
#include <stack>
#include <map>
#include <cmath>

using namespace std;
int mod = 1e9 + 7;

/*
Codeforces problem 2148 A : Sublime Sequence

Problem : https://codeforces.com/problemset/problem/2148/A
*/
int main()
{
    int t;
    int x, n;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> x >> n;
        if (n % 2 == 0)
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << x << "\n";
        }
    }

    return 0;
}