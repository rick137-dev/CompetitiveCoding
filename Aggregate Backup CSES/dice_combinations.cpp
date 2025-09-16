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

// Problem : https://cses.fi/problemset/task/1633

long long diceCombs(int N, vector<int> &dp)
{
       if (N < 0)
              return 0;
       if (dp[N] != -1)
              return dp[N];
       long long total = 0;
       for (int i = 1; i <= 6; i++)
       {
              total = (total % mod + diceCombs(N - i, dp) % mod) % mod;
       }
       return dp[N] = total;
}
int main()
{
       int N;
       cin >> N;
       vector<int> dp(N + 1, -1);
       dp[0] = 1;
       dp[1] = 1;
       dp[2] = 2;
       cout << diceCombs(N, dp) % mod;

       return 0;
}
