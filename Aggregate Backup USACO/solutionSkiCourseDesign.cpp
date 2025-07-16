
/*
ID: caiulor1
LANG: C++
PROG: skidesign
*/

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

int main()
{
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    int minimum_diff = INT_MAX;
    int current_min;
    for (int a = 0; a <= 83; a++)
    {
        current_min = 0;

        for (int i = 0; i < n; i++)
        {
            if (heights[i] < a)
            {
                current_min += (heights[i] - a) * (heights[i] - a);
            }
            else if (heights[i] > a + 17)
            {
                current_min += (a + 17 - heights[i]) * (a + 17 - heights[i]);
            }
            else
            {
                continue;
            }
        }

        minimum_diff = min(minimum_diff, current_min);
    }
    cout << minimum_diff << "\n";

    return 0;
}
