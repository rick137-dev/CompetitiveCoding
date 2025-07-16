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

#define MOD 1000000007

// Main trick for this problem is recognizing it as an inverted shortest path problem, but with the addition of needing to find negative weight cycles. Hence the best solution
// here is to invert the sign of each weight and use the Bellman-Ford algorithm.

int main()
{
    unordered_map<int, vector<pair<int, int>>> Alist;
    unordered_map<int, vector<int>> invertedAlist;

    // node -> {node,weight}

    int n, m;
    cin >> n >> m;
    int a, b, weight;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> weight;
        Alist[a].push_back({b, -weight});
        invertedAlist[b].push_back(a);
    }
    vector<long long> dist(n + 1, LLONG_MAX); // Using 1-indexed array
    dist[1] = 0;

    // Relaxation of distances
    for (int i = 1; i < n; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (auto [v, w] : Alist[u])
            {
                if (dist[u] != LLONG_MAX && dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
    // To check for negative cycle we need to check if a negative cycle affects the path from 1 to n, otherwise it won't have any effect

    vector<bool> hasCycle(n + 1, false);

    for (int u = 1; u <= n; u++)
    {
        for (auto [v, w] : Alist[u])
        {
            if (dist[u] != LLONG_MAX && dist[u] + w < dist[v])
            {
                hasCycle[v] = true;
            }
        }
    }

    // Now we BFS from n to check if we hit any negative cycle nodes
    bool isCycle = false;
    unordered_set<int> visited;

    queue<int> myQueue;

    myQueue.push(n);
    visited.insert(n);
    int size;

    while (!myQueue.empty())
    {
        size = myQueue.size();
        for (int i = 0; i < size; i++)
        {
            int temp = myQueue.front();
            myQueue.pop();
            if (hasCycle[temp])
            {
                isCycle = true;
                break;
            }
            for (int next : invertedAlist[temp])
            {
                if (visited.count(next) == 0)
                {
                    myQueue.push(next);
                    visited.insert(next);
                }
            }
        }

        if (isCycle)
            break;
    }

    if (isCycle)
    {
        cout << -1;
    }
    else
    {

        cout << -dist[n];
    }

    return 0;
}
