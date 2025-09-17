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

// Problem : https://cses.fi/problemset/task/3222/

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> numbers(n);

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    unordered_map<int, int> freq;

    for (int i = 0; i < k; i++)
    {
        freq[numbers[i]]++;
    }
    cout << freq.size() << " ";

    int start = 0;
    for (int end = k; end < n; end++)
    {
        freq[numbers[end]]++;
        freq[numbers[start]]--;
        if (freq[numbers[start]] == 0)
        {
            freq.erase(numbers[start]);
        }
        start++;
        cout << freq.size() << " ";
    }

    return 0;
}