
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

/*
This is the recursive function with memoization. It is correct in principle, but the stringent memory requirements force me to
use an iterative solution, which I can further optimize by only using one row at a time, instead of the entire DP matrix.
*/

int findMinInsertion(string &base, int i, int j, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        return dp[i][j] = 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];
    if (base[i] == base[j])
    {
        return dp[i][j] = findMinInsertion(base, i + 1, j - 1, dp);
    }

    return dp[i][j] = 1 + min(findMinInsertion(base, i + 1, j, dp), findMinInsertion(base, i, j - 1, dp));
}

// This is the iterative version
int findMinInsertionIterative(string base)
{
    int N = base.length();
    vector<vector<int>> dp(N, vector<int>(N, 0));
    int end;

    for (int size = 2; size <= N; size++)
    {
        for (int start = 0; start <= N - size; start++)
        {

            end = start + size - 1;

            if (base[start] == base[end])
            {
                dp[start][end] = dp[start + 1][end - 1];
            }
            else
            {
                dp[start][end] = 1 + min(dp[start + 1][end], dp[start][end - 1]);
            }
        }
    }
    return dp[0][N - 1];
}

// This is the iterative version optimized to use one row at a time
long long findMinInsertionIterativeOptimized(string base)
{
    int N = base.length();

    vector<long long> dp(N, 0);

    for (int i = N - 2; i >= 0; --i)
    {

        long long prevDiag = 0;
        for (int j = i + 1; j < N; ++j)
        {

            long long temp = dp[j];
            if (base[i] == base[j])
            {
                dp[j] = prevDiag;
            }
            else
            {

                dp[j] = 1 + min(dp[j], dp[j - 1]);
            }
            prevDiag = temp;
        }
    }
    return dp[N - 1];
}

int main()
{
    int N;
    cin >> N;
    string base;
    cin >> base;

    cout << findMinInsertionIterativeOptimized(base);

    return 0;
}