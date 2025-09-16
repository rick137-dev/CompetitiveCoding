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

// Problem : https://cses.fi/problemset/task/1635

// Recursive version
int countWays(int target, const vector<int> &coins, vector<int> &dp)
{
       if (target == 0)
              return 1;
       if (target < 0)
              return 0;
       if (dp[target] != -1)
              return dp[target];

       long long ways = 0;
       for (int c : coins)
       {
              ways = (ways % MOD + countWays(target - c, coins, dp) % MOD) % MOD;
       }

       return dp[target] = ways;
}

// Simple iterative DP solution with loops inverted since we're counting permutations
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
       for (int i = 1; i <= target; i++)
       {
              for (int c : coins)
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