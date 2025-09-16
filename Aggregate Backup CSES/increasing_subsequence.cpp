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

// Problem : https://cses.fi/problemset/task/1145

// This solution is based on Patience Sorting, since the standard DP approach is O(N^2), but the Patience Sorting approach is O(NlogN)
int main()
{
       int N;
       cin >> N;
       vector<int> array(N);
       for (int i = 0; i < N; i++)
       {
              cin >> array[i];
       }

       vector<int> lis;
       for (int x : array)
       {
              auto it = lower_bound(lis.begin(), lis.end(), x);
              if (it == lis.end())
              {
                     lis.push_back(x);
              }
              else
              {
                     *it = x;
              }
       }
       cout << lis.size();
       return 0;
}