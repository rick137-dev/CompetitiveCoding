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

// Problem : https://cses.fi/problemset/task/3420/

// Uses a trick of keeping track of the index of the last time the current value was seen in the array

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    unordered_map<int, int> lastSeen;
    int left = 0;

    long long numSubArrays = 0;

    for (int right = 0; right < n; right++)
    {
        if (lastSeen.count(nums[right]))
        {
            left = max(left, lastSeen[nums[right]] + 1);
        }
        lastSeen[nums[right]] = right;

        numSubArrays += (long long)(right - left + 1);
    }
    cout << numSubArrays;
    return 0;
}