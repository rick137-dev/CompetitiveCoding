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

// This is a DP solution using recursion and memoization, a faster 1D iterative solution is also possible

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