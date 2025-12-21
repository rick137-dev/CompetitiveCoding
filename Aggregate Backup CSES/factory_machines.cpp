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
This can be solved using a priority queue, executing the least time-expensive machine first, but a binary search solution through the possible times
to make all the products is much faster in practice.
*/

// Problem : https://cses.fi/problemset/task/1620

bool canMake(vector<long long> &times, long long time, long long products)
{

    long long productsMade = 0;

    for (long long currentTime : times)
    {
        productsMade += time / currentTime;
    }

    return productsMade >= products;
}

int main()
{

    int n, necessaryProducts;
    cin >> n >> necessaryProducts;

    vector<long long> times(n);

    for (int i = 0; i < n; i++)
    {
        cin >> times[i];
    }

    long long low = 0;
    long long high = necessaryProducts * (*min_element(times.begin(), times.end()));

    long long mid;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (canMake(times, mid, necessaryProducts))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << low;
    return 0;
}
