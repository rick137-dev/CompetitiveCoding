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

// Problem : https://cses.fi/problemset/task/1674
int dfs(int currentNode, unordered_map<int, vector<int>> &Alist, vector<int> &subs)
{

       if (subs[currentNode] != -1)
              return subs[currentNode];

       int total = 0;
       for (int neighs : Alist[currentNode])
       {
              total += 1 + dfs(neighs, Alist, subs);
       }

       return subs[currentNode] = total;
}

int main()
{
       int N;
       cin >> N;
       unordered_map<int, vector<int>> Alist;
       int temp;
       for (int i = 1; i < N; i++)
       {
              cin >> temp;
              Alist[temp - 1].push_back(i);
       }
       vector<int> subs(N, -1);

       for (int i = 0; i < N; i++)
       {
              cout << dfs(i, Alist, subs) << " ";
       }

       return 0;
}