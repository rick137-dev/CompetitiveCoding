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
#include <map>

using namespace std;

const int MOD = 1e9 + 7;

// Problem : https://cses.fi/problemset/task/1636

// Recursive 2D DP solution
int countWays(int index, int target, const vector<int> &coins, vector<vector<int>> &dp)
{
       if (target == 0)
              return 1;
       if (index == coins.size())
              return 0;
       if (dp[index][target] != -1)
              return dp[index][target];

       long long ways = 0;

       if (target - coins[index] >= 0)
       {
              ways = (ways % MOD + countWays(index, target - coins[index], coins, dp) % MOD) % MOD;
       }

       ways = (ways % MOD + countWays(index + 1, target, coins, dp) % MOD) % MOD;

       return dp[index][target] = ways;
}

// Simple iterative DP solution, 1D, so same time complexity but less memory use
int main()
{
       int N, target;
       cin >> N >> target;
       vector<int> coins(N), dp(target + 1);

       for (int i = 0; i < N; i++)
       {
              cin >> coins[i];
       }

       dp[0] = 1;
       for (int c : coins)
       {

              for (int i = 1; i <= target; i++)
              {

                     if (i - c >= 0)
                     {
                            (dp[i] += dp[i - c]) %= MOD;
                     }
              }
       }
       cout << dp[target] << '\n';
       return 0;
}