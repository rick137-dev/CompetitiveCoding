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

// Problem : https://cses.fi/problemset/task/1072/

// Slow version which checks only attacking pairs, making check O(k^2). The brute force version would be O(k^4) by manually checking each knight pair
long long numPositionsSlow(int k)
{
    if (k == 1)
        return 0;

    vector<pair<int, int>> steps = {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
    long long limit = k * k;
    long long attacking_pairs = 0;

    long long total_pairs = (limit * (limit - 1)) / 2;

    for (int position = 0; position < limit; position++)
    {
        int pos_x = position % k;
        int pos_y = (position - (position % k)) / k;

        int step_x, step_y;

        for (pair<int, int> step : steps)
        {
            step_x = step.first;
            step_y = step.second;

            int possible_pos_x = pos_x + step_x;
            int possible_pos_y = pos_y + step_y;

            if (!(possible_pos_x < 0 || possible_pos_x >= k || possible_pos_y < 0 || possible_pos_y >= k))
            {
                attacking_pairs++;
            }
        }
    }
    int non_attacking_pairs = total_pairs - (attacking_pairs / 2);
    return non_attacking_pairs;
}

// Fast version, which uses a combinatorial approach to calculate in O(1)
long long numPositionsFast(int k)
{
    long long limit = k * k;
    long long total_pairs = (limit * (limit - 1)) / 2;
    long long attacking_pairs = 4 * (k - 1) * (k - 2);
    return (total_pairs - attacking_pairs);
}
int main()
{

    int n;
    cin >> n;
    for (int k = 1; k <= n; k++)

    {
        cout << numPositionsFast(k) << "\n";
    }
    return 0;
}