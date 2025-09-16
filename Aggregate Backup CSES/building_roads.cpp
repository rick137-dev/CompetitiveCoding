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

// Problem : https://cses.fi/problemset/task/1666

void dfs(int currentNode, unordered_map<int, vector<int>> &Alist, vector<int> &visited, int status)
{
       if (visited[currentNode] > -1)
       {
              return;
       }
       visited[currentNode] = status;
       for (int neigh : Alist[currentNode])
       {
              dfs(neigh, Alist, visited, status);
       }
}

int main()
{

       int n, m;
       cin >> n >> m;
       vector<vector<int>> edges;
       int a, b;

       for (int i = 0; i < m; i++)
       {
              cin >> a >> b;
              a--;
              b--;
              edges.push_back({a, b});
       }
       vector<int> visited(n, -1);

       unordered_map<int, vector<int>> Alist;
       for (vector<int> edge : edges)
       {
              Alist[edge[0]].push_back(edge[1]);
              Alist[edge[1]].push_back(edge[0]);
       }

       for (int i = 0; i < n; i++)
       {
              if (visited[i] == -1)
              {
                     dfs(i, Alist, visited, i);
              }
       }

       vector<int> toAddNodes;

       for (int i = 0; i < visited.size(); i++)
       {
              if (visited[i] == i)
              {
                     toAddNodes.push_back(i);
              }
       }

       cout << toAddNodes.size() - 1 << "\n";
       for (int i = 0; i < toAddNodes.size() - 1; i++)
       {
              cout << toAddNodes[i] + 1 << " " << toAddNodes[i + 1] + 1 << "\n";
       }

       return 0;
}
