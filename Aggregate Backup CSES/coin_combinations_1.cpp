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