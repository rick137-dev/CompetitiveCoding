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

// Problem : https://cses.fi/problemset/task/1131

// Uses standard 2 dfs solution, one to find a node on the diameter, the other to find the length of the diameter

void dfs(int currNode, int parent, unordered_map<int, vector<int>> &Alist, int currDistance, int &maxDistance, int &maxNode)
{
       if (currDistance > maxDistance)
       {
              maxDistance = currDistance;
              maxNode = currNode;
       }

       for (int next : Alist[currNode])
       {
              if (next != parent)
              {
                     dfs(next, currNode, Alist, currDistance + 1, maxDistance, maxNode);
              }
       }
}

int main()
{

       int N;
       cin >> N;
       unordered_map<int, vector<int>> Alist;
       int a, b;
       for (int i = 0; i < N - 1; i++)
       {
              cin >> a >> b;
              a--;
              b--;
              Alist[a].push_back(b);
              Alist[b].push_back(a);
       }
       int maxNode = 0;
       int maxDistance = 0;

       dfs(0, -1, Alist, 0, maxDistance, maxNode);

       maxDistance = 0;
       int newStart = maxNode;

       dfs(newStart, -1, Alist, 0, maxDistance, maxNode);

       cout << maxDistance;

       return 0;
}