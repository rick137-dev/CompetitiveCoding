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

// Standard prefix sum array solution

int main()
{
       int n, q;
       cin >> n >> q;
       vector<long long> array(n);
       for (int i = 0; i < n; i++)
       {
              cin >> array[i];
       }
       for (int i = 1; i < n; i++)
       {
              array[i] += array[i - 1];
       }
       int a, b;
       for (int i = 0; i < q; i++)
       {
              cin >> a >> b;

              if (a - 2 < 0)
              {
                     cout << array[b - 1] << "\n";
              }
              else
              {
                     cout << array[b - 1] - array[a - 2] << "\n";
              }
       }

       return 0;
}
