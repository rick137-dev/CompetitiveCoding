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

// Problem : https://cses.fi/problemset/task/1092

/*
Since the numbers are [1..n] the problem can be simplified and solved in O(n) time rather than the usual O(nW)
The main idea is looking at the form the sum takes, the sum of the numbers from 1 to n inclusive is n(n+1)/2
By considering this sum needs to be divided into 2 groups, we can look at this sum mod 2
Which we get n must be 0 mod 4 or 3 mod 4. And these have separate rules to divide the numbers to find valid sums.
*/
int main()
{
    int n;
    cin >> n;

    if (n % 4 == 1 || n % 4 == 2)
    {
        cout << "NO\n";
        return 0;
    }

    if (n % 4 == 0)
    {
        cout << "YES\n";
        cout << n / 2 << "\n";
        for (int i = 1; i <= n / 2; i++)
        {
            if (i % 2 == 0)
            {
                cout << i << " " << n - i + 1 << " ";
            }
        }
        cout << "\n";
        cout << n / 2 << "\n";

        for (int i = 1; i <= n / 2; i++)
        {
            if (i % 2 == 1)
            {
                cout << i << " " << n - i + 1 << " ";
            }
        }

        return 0;
    }

    if (n % 4 == 3)
    {
        cout << "YES\n";
        vector<int> first = {1, 2};
        vector<int> second = {3};

        for (int i = 1; i <= n / 4; i++)
        {
            first.push_back(i * 4);
            first.push_back(i * 4 + 3);
            second.push_back(i * 4 + 1);
            second.push_back(i * 4 + 2);
        }

        cout << first.size() << "\n";
        for (int num : first)
        {
            cout << num << " ";
        }
        cout << "\n";
        cout << second.size() << "\n";
        for (int num : second)
        {
            cout << num << " ";
        }

        return 0;
    }

    return 0;
}
