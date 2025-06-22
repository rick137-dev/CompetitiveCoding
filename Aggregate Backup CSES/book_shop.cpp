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
