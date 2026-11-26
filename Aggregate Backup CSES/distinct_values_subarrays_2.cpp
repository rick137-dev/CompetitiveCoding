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

// Problem : https://cses.fi/problemset/task/2428/

// The main logic for the solution here is to go through the array, and consider at every index, what is the longest subarray which ends at this index starting from the left of it?
// Every subarray ending at the index smaller than the largest one must be valid, and are also unique for each index.
// Thus, we can just count the length of each subarray, since that is the number of starting points for the subarrays ending at the given index
// To ensure the validity of a subarray we must count the number of distinct elements, which we can do using a frequency count.
// We don't need to go through the entire frequency map each time, we just need to count the number of times we add or remove a unique element by checking frequencies that pass by 0
// We could use a vector if we had a small set of values in the array, otherwise a hash map could work in O(1) but with certain inputs could cause O(n) worst case, while an ordered mapping guarantees O(logn) every time

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    long long totalSubs = 0;

    map<int, int> freq;

    int distinct_values = 0;

    int left = 0;

    for (int right = 0; right < n; right++)
    {
        if (freq[nums[right]] == 0)
        {
            distinct_values++;
        }

        freq[nums[right]]++;

        while (distinct_values > k)
        {
            freq[nums[left]]--;
            if (freq[nums[left]] == 0)
            {
                distinct_values--;
            }
            left++;
        }
        totalSubs += (long long)right - (long long)left + 1;
    }
    cout << totalSubs;
    return 0;
}
