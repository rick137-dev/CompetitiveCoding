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
This problem is a classic example of a solution using the Greedy method of stacking on top of the smallest cube which can take the
current cube. In general, this is called Patience Sorting and can be used in solutions to other problems as well.
*/

// Problem : https://cses.fi/problemset/task/1073

int main()
{
    int n;
    cin >> n;

    vector<int> towers;
    int currentCube;

    for (int i = 0; i < n; i++)
    {
        cin >> currentCube;
        auto it = upper_bound(towers.begin(), towers.end(), currentCube);

        if (it == towers.end())
        {
            towers.push_back(currentCube);
        }
        else
        {
            *it = currentCube;
        }
    }

    cout << towers.size();

    return 0;
}
