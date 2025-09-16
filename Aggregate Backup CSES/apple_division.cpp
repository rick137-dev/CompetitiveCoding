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

using namespace std;

// Problem : https://cses.fi/problemset/task/1623

// This is quite similar to subset sum problem so it can be solved with DP, but this brute force approach is ok for small N
int main()
{
       long total_min;
       total_min = INT_MAX;
       int N;
       cin >> N;
       long long limit = 1LL << N;

       vector<int> apples(N);
       for (int i = 0; i < N; i++)
       {
              cin >> apples[i];
       }

       for (int i = 0; i < limit; i++)
       {

              long group1 = 0;
              long group2 = 0;

              for (int t = 0; t < N; t++)
              {
                     if (i & (1 << t))
                     {
                            group1 += apples[t];
                     }
                     else
                     {
                            group2 += apples[t];
                     }
              }
              total_min = min(total_min, abs(group1 - group2));
       }
       cout << total_min;
}
