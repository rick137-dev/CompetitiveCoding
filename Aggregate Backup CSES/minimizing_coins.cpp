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

using namespace std;
// Problem : https://cses.fi/problemset/task/1634

// Recursive 2D solution
int coinChangeRecursive(int index, int target, vector<int> &coins, vector<vector<int>> &dp)
{
       if (target == 0)
              return 0;
       if (index < 0)
              return 1e9;

       if (dp[index][target] != -1)
              return dp[index][target];

       int notTake = coinChangeRecursive(index - 1, target, coins, dp);
       int take = 1e9;
       if (coins[index] <= target)
       {
              take = 1 + coinChangeRecursive(index, target - coins[index], coins, dp);
       }

       return dp[index][target] = min(take, notTake);
}

// 2D Iterative Solution
int coinChange2D(vector<int> &coins, int target)
{
       int n = coins.size();

       vector<vector<int>> dp(n, vector<int>(target + 1, INT_MAX));

       for (int i = 0; i < n; i++)
       {
              dp[i][0] = 0;
       }

       for (int t = 1; t <= target; t++)
       {
              if (t % coins[0] == 0)
                     dp[0][t] = t / coins[0];
       }

       for (int i = 1; i < n; i++)
       {
              for (int t = 1; t <= target; t++)
              {
                     int notTake = dp[i - 1][t];
                     int take = INT_MAX;
                     if (coins[i] <= t && dp[i][t - coins[i]] != INT_MAX)
                            take = 1 + dp[i][t - coins[i]];
                     dp[i][t] = min(take, notTake);
              }
       }

       int ans = dp[n - 1][target];
       return (ans >= INT_MAX ? -1 : ans);
}

// 1D Iterative solution
int coinChangeIterative(vector<int> &coins, int target)
{
       vector<int> dp(target + 1, target + 1);
       dp[0] = 0;

       for (int c : coins)
       {
              for (int t = c; t <= target; t++)
              {
                     dp[t] = min(dp[t], dp[t - c] + 1);
              }
       }

       return (dp[target] > target ? -1 : dp[target]);
}

int main()
{

       int N, target;
       cin >> N >> target;
       vector<int> coins(N);

       for (int i = 0; i < N; i++)
       {
              cin >> coins[i];
       }

       vector<int> dp(target + 1, target + 1);
       dp[0] = 0;
       for (int c : coins)
       {
              for (int t = c; t <= target; t++)
              {
                     dp[t] = min(dp[t], dp[t - c] + 1);
              }
       }

       int ans = dp[target] > target ? -1 : dp[target];

       cout << ans;
       return 0;
}
