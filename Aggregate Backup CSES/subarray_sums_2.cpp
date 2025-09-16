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

// Problem : https://cses.fi/problemset/task/1661

// Here I used ordered map since again, hash map caused collisions blowing up the time complexity to O(N^2)
int main()
{
       long long N, target;
       cin >> N >> target;
       vector<long> array(N);
       map<long, long> seen;
       for (int i = 0; i < N; i++)
       {
              cin >> array[i];
       }
       for (int i = 1; i < N; i++)
       {
              array[i] += array[i - 1];
       }

       long long total = 0;
       seen[0]++;

       for (int i = 0; i < N; i++)
       {
              total += seen[array[i] - target];

              seen[array[i]]++;
       }

       cout << total;
       return 0;
}
