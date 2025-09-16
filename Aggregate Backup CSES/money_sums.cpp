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

// Problem : https://cses.fi/problemset/task/1745

// 2D Recursive Solution
int canMake(int amount, int index, vector<int> &array, vector<vector<int>> &dp)
{
       if (index < 0 || amount < 0)
              return 0;

       if (dp[amount][index] != -1)
       {
              return dp[amount][index];
       }

       if (amount == 0)
       {
              return dp[amount][index] = 1;
       }
       if (index == 0)
       {
              if (array[0] == amount || amount == 0)
              {
                     return 1;
              }
              else
              {
                     return 0;
              }
       }
       if (canMake(amount, index - 1, array, dp) == 1 || canMake(amount - array[index], index - 1, array, dp) == 1)
       {
              return dp[amount][index] = 1;
       }
       else
       {
              return dp[amount][index] = 0;
       }
}

// 2D Iterative solution
int canMake2DIterative(int amount, const vector<int> &array)
{
       int n = array.size();
       vector<vector<char>> dp(n + 1, vector<char>(amount + 1, 0));

       dp[0][0] = 1;

       for (int i = 1; i <= n; i++)
       {
              for (int t = 0; t <= amount; t++)
              {

                     dp[i][t] = dp[i - 1][t];

                     if (t >= array[i - 1] && dp[i - 1][t - array[i - 1]])
                     {
                            dp[i][t] = 1;
                     }
              }
       }
       return dp[n][amount] ? 1 : 0;
}

// 1D Iterative Solution
int canMake1DIterative(int amount, const vector<int> &array)
{
       vector<char> dp(amount + 1, 0);
       dp[0] = 1;

       for (int x : array)
       {

              for (int t = amount; t >= x; --t)
              {
                     if (dp[t - x])
                            dp[t] = 1;
              }
       }
       return dp[amount] ? 1 : 0;
}

int main()
{
       int N;
       cin >> N;
       vector<int> array(N);
       int maxAmount = 0;

       for (int i = 0; i < N; i++)
       {
              cin >> array[i];
              maxAmount += array[i];
       }

       vector<vector<int>> dp(maxAmount + 1, vector<int>(N, -1));
       dp[maxAmount][N - 1] = 1;
       int k = 0;
       vector<int> goods;
       for (int i = 1; i <= maxAmount; i++)
       {
              if (canMake(i, N - 1, array, dp) == 1)
              {
                     k++;
                     goods.push_back(i);
              }
       }
       cout << k << "\n";
       for (int i = 0; i < goods.size(); i++)
       {

              cout << goods[i] << " ";
       }

       return 0;
}