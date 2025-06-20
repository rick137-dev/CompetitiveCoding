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

// Standard memoization solution returns LTE, transformed to bottom-up iterative DP and used a 1D array to reduce memory

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
