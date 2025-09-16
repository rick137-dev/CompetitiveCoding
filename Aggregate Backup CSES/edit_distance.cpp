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

using namespace std;

// Problem : https://cses.fi/problemset/task/1639

// 2D Resursive solution
int minDistance(string &in1, string &in2, int i, int j, vector<vector<int>> &dp)
{
    if (i == in1.length())
        return in2.length() - j;
    if (j == in2.length())
        return in1.length() - i;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (in1[i] == in2[j])
    {
        return dp[i][j] = minDistance(in1, in2, i + 1, j + 1, dp);
    }
    else
    {
        return dp[i][j] = (1 + min({minDistance(in1, in2, i + 1, j, dp), minDistance(in1, in2, i, j + 1, dp), minDistance(in1, in2, i + 1, j + 1, dp)}));
    }
}

// 2D Iterative solution
int minDistanceIterative(string &in1, string &in2, vector<vector<int>> &dp)
{
    int m = in1.size();
    int n = in2.size();

    for (int i = 0; i <= m; ++i)
        dp[i][n] = m - i;
    for (int j = 0; j <= n; ++j)
        dp[m][j] = n - j;

    for (int i = in1.length() - 1; i >= 0; i--)
    {
        for (int j = in2.length() - 1; j >= 0; j--)
        {

            if (in1[i] == in2[j])
            {
                dp[i][j] = dp[i + 1][j + 1];
            }
            else
            {
                dp[i][j] = 1 + min({dp[i + 1][j + 1], dp[i][j + 1], dp[i + 1][j]});
            }
        }
    }
    return dp[0][0];
}

// 1D Iterative solution
int minDistance1D(string &in1, string &in2)
{
    int m = in1.size();
    int n = in2.size();

    vector<int> dp(n + 1), prev(n + 1);

    for (int j = 0; j <= n; j++)
    {
        dp[j] = n - j;
    }

    for (int i = m - 1; i >= 0; i--)
    {
        prev = dp;
        dp[n] = m - i;

        for (int j = n - 1; j >= 0; j--)
        {
            if (in1[i] == in2[j])
            {
                dp[j] = prev[j + 1];
            }
            else
            {
                dp[j] = 1 + min({prev[j + 1],
                                 dp[j + 1],
                                 prev[j]});
            }
        }
    }

    return dp[0];
}

int main()
{

    string in1;
    string in2;
    cin >> in1;
    cin >> in2;
    vector<vector<int>> dp(in1.size(), vector<int>(in2.size(), -1));
    cout << minDistance(in1, in2, 0, 0, dp);

    return 0;
}