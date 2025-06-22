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

int main()
{

       int n, m;
       cin >> n >> m;
       vector<bool> visited(n, false);
       unordered_map<int, vector<int>> Alist;
       vector<int> prev(n, -1);
       int a, b;
       for (int i = 0; i < m; i++)
       {
              cin >> a >> b;
              a--;
              b--;
              Alist[a].push_back(b);
              Alist[b].push_back(a);
       }

       queue<int> myQueue;
       myQueue.push(0);

       visited[0] = true;
       bool reached = false;

       while (!myQueue.empty())
       {
              int size = myQueue.size();
              for (int i = 0; i < size; i++)
              {
                     int curr = myQueue.front();
                     myQueue.pop();
                     if (curr == n - 1)
                     {
                            reached = true;
                            break;
                     }
                     for (int neigh : Alist[curr])
                     {
                            if (visited[neigh] == false)
                            {
                                   visited[neigh] = true;
                                   myQueue.push(neigh);
                                   prev[neigh] = curr;
                            }
                     }
              }
       }

       if (reached)
       {

              vector<int> path;
              int curr = n - 1;
              while (prev[curr] != -1)
              {
                     path.push_back(curr);
                     curr = prev[curr];
              }
              reverse(path.begin(), path.end());
              cout << path.size() + 1 << "\n";
              cout << 1 << " ";
              for (int i = 0; i < path.size(); i++)
              {
                     cout << path[i] + 1 << " ";
              }
       }
       else
       {
              cout << "IMPOSSIBLE";
       }
       return 0;
}
