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

// Problem : https://cses.fi/problemset/task/1090

int main()
{
       int N, max_weight;
       cin >> N >> max_weight;
       vector<int> weights(N);

       for (int i = 0; i < N; i++)
       {
              cin >> weights[i];
       }
       sort(weights.begin(), weights.end());
       int amount = 0;
       int left = 0;
       int right = N - 1;
       while (right >= left)
       {
              if (weights[left] + weights[right] <= max_weight)
              {
                     left++;
                     right--;
              }
              else
              {
                     right--;
              }
              amount++;
       }

       cout << amount;
       return 0;
}