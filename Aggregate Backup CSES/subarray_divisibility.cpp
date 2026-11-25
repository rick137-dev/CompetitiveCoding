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
#include <bit>

using namespace std;
int mod = 1e9 + 7;

// Problem : https://cses.fi/problemset/task/1662/
// Used standard prefix sum and frequency tracking solution for this type of problem, except making sure everything is considered mod n

int main()
{
    int n;
    cin >> n;
    vector<long long> nums(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    nums[0] = ((nums[0] % n) + n) % n;

    for (int i = 1; i < n; i++)
    {
        nums[i] += nums[i - 1];
        nums[i] = ((nums[i] % n) + n) % n;
    }

    vector<int> freq(n, 0);

    long long totalMatches = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            totalMatches++;
        }
        totalMatches += (long long)freq[nums[i]];
        freq[nums[i]]++;
    }
    cout << totalMatches;

    return 0;
}
