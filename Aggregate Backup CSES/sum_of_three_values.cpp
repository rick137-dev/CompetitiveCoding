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

// Problem : https://cses.fi/problemset/task/1641

int main()
{
       int N, target;
       cin >> N >> target;
       vector<pair<int, int>> array(N);
       int temp;

       for (int i = 0; i < N; i++)
       {
              cin >> temp;
              array[i] = {temp, i};
       }
       sort(array.begin(), array.end(), [](pair<int, int> a, pair<int, int> b)
            { return a.first < b.first; });

       for (int i = 0; i < N; i++)
       {
              int right = N - 1;
              int left = i + 1;
              int amount;
              while (right > left)
              {
                     amount = array[i].first + array[right].first + array[left].first;
                     if (amount == target && array[right].second != array[left].second)
                     {
                            cout << array[left].second + 1 << " " << array[right].second + 1 << " " << array[i].second + 1;
                            return 0;
                     }
                     else if (amount > target)
                     {
                            right--;
                     }
                     else
                     {
                            left++;
                     }
              }
       }

       cout << "IMPOSSIBLE";
       return 0;
}
