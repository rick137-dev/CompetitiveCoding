
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
#include <stack>
#include <map>
#include <cmath>

using namespace std;

// Problem : https://cses.fi/problemset/task/1669

bool dfs(unordered_map<int, vector<int>> &Alist, int currentNode, vector<bool> &visited, vector<int> &cycle, int parent)
{
    visited[currentNode] = true;
    cycle.push_back(currentNode);

    for (int next : Alist[currentNode])
    {
        if (next != parent)
        {
            if (visited[next])
            {
                cycle.push_back(next);
                return true;
            }

            if (dfs(Alist, next, visited, cycle, currentNode))
            {
                return true;
            }
        }
    }
    cycle.pop_back();
    return false;
}

int main()
{

    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<int>> Alist;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        Alist[a].push_back(b);
        Alist[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    vector<int> cycle;

    for (int node = 1; node <= n; node++)
    {
        if (!visited[node] && dfs(Alist, node, visited, cycle, -1))
        {
            int end = cycle.back();
            vector<int> result;

            for (int i = cycle.size() - 2; i >= 0; i--)
            {
                result.push_back(cycle[i]);
                if (cycle[i] == end)
                {
                    break;
                }
            }

            reverse(result.begin(), result.end());
            result.push_back(end);

            cout << result.size() << endl;
            for (int node : result)
                cout << node << " ";

            return 0;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}
