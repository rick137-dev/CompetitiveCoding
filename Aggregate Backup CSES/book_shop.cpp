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

// Problem : https://cses.fi/problemset/task/1158

// Recursive 2D solution, simpler to code but uses more memory
long long maxPages(int idx, long long budget, vector<long long> &pages, vector<long long> &prices, vector<vector<long long>> &dp)
{
       if (idx < 0)
              return 0;
       if (dp[idx][budget] != -1)
              return dp[idx][budget];

       long long res = maxPages(idx - 1, budget, pages, prices, dp);

       // option 2: take this book (if budget allows)
       if (prices[idx] <= budget)
       {
              res = max(res, maxPages(idx - 1, budget - prices[idx], pages, prices, dp) + pages[idx]);
       }

       return dp[idx][budget] = res;
}

// Iterative 1D DP solution, 2D was recursive, it had the same runtime but the large memory use caused runtime errors, this solution uses optimal amounts of memory
long long maxPages(long long maxPrice, vector<long long> &pages, vector<long long> &prices)
{
       int N = pages.size();

       vector<long long> dp(maxPrice + 1, 0);

       long long cost, gain;
       for (int k = 0; k < N; ++k)
       {
              cost = prices[k];
              gain = pages[k];

              for (long long b = maxPrice; b >= cost; --b)
              {
                     dp[b] = max(dp[b], dp[b - cost] + gain);
              }
       }

       return dp[maxPrice];
}

int main()
{
       long long N, max_price;
       cin >> N >> max_price;
       vector<long long> prices(N);
       vector<long long> pages(N);
       for (int i = 0; i < N; i++)
       {
              cin >> prices[i];
       }
       for (int i = 0; i < N; i++)
       {
              cin >> pages[i];
       }

       cout << maxPages(max_price, pages, prices);

       return 0;
}
