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

int mod = 1e9 + 7;

int main()
{
       int N;
       cin >> N;
       vector<string> grid(N);

       for (int i = 0; i < N; i++)
       {
              cin >> grid[i];
       }

       if (grid[0][0] == '*')
       {
              cout << 0;
              return 0;
       }
       vector<vector<int>> dp(N, vector<int>(N, 0));
       dp[0][0] = 1;
       for (int i = 0; i < N; i++)
       {
              for (int j = 0; j < N; j++)
              {
                     if (grid[i][j] == '*')
                            continue;
                     int up = 0;
                     int left = 0;
                     if (i > 0)
                     {
                            up = dp[i - 1][j];
                     }
                     if (j > 0)
                     {
                            left = dp[i][j - 1];
                     }

                     dp[i][j] += (up % mod + left % mod) % mod;
              }
       }

       cout << dp[N - 1][N - 1];
       return 0;
}