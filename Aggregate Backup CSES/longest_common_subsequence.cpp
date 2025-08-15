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
// Generate DP table
int commonSub(vector<int> &a, vector<int> &b, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i] == b[j])
    {
        return dp[i][j] = 1 + commonSub(a, b, i - 1, j - 1, dp);
    }

    return dp[i][j] = max(commonSub(a, b, i - 1, j, dp), commonSub(a, b, i, j - 1, dp));
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> vec1(n);
    vector<int> vec2(m);

    for (int i = 0; i < n; i++)
    {
        cin >> vec1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> vec2[i];
    }
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int length = commonSub(vec1, vec2, n - 1, m - 1, dp);

    int starti = n - 1;
    int startj = m - 1;
    vector<int> result;

    // Simple function to convert unacessible elements to 0
    auto val = [&](int x, int y) -> int
    {
        if (x < 0 || y < 0)
            return 0;
        return dp[x][y];
    };

    while (starti >= 0 && startj >= 0)
    {

        if (vec1[starti] == vec2[startj])
        {
            result.push_back(vec1[starti]);
            starti--;
            startj--;
        }
        else if (val(starti - 1, startj) > val(starti, startj - 1))
        {
            starti--;
        }
        else
        {
            startj--;
        }
    }

    reverse(result.begin(), result.end());

    cout << length << "\n";
    for (int c : result)
    {
        cout << c << " ";
    }

    return 0;
}