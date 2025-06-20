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

// This solution is O(N^3), there exists a better O(N^2) solution using hash maps, but similarly with the 3 number sum problem, the inputs cause frequent hashing collisions

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

       int amount, left, right;

       for (int i = 0; i < N; i++)
       {
              for (int j = i + 1; j < N; j++)
              {

                     left = j + 1;
                     right = N - 1;
                     while (left < right)
                     {
                            amount = array[left].first + array[right].first + array[i].first + array[j].first;
                            if (amount == target)
                            {
                                   cout << array[left].second + 1 << " " << array[right].second + 1 << " " << array[i].second + 1 << " " << array[j].second + 1;
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
       }

       cout << "IMPOSSIBLE";
       return 0;
}
