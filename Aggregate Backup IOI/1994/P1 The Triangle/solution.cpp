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

int main()
{

    int N;
    cin >> N;

    int temp;

    vector<int> prev;

    for (int step = 1; step <= N; step++)
    {
        vector<int> curr(step);
        for (int i = 0; i < step; i++)
        {
            cin >> temp;
            curr[i] = temp;
        }

        for (int i = 0; i < step; i++)
        {
            int left = i - 1;
            int right = i;
            if (left >= 0 && right < prev.size())
            {
                curr[i] = curr[i] + max(prev[left], prev[right]);
            }
            else if (left >= 0)
            {
                curr[i] += prev[left];
            }
            else if (right < prev.size())
            {
                curr[i] += prev[right];
            }
        }
        prev = curr;
    }

    int maxVal = INT_MIN;
    for (int val : prev)
    {
        maxVal = max(maxVal, val);
    }
    cout << maxVal;
}
