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

const int MOD = 1e9 + 7;

// Problem : https://cses.fi/problemset/task/1671
// It is simple to see a straight forward application of Dijkstra's algorithm works well here

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> dist(n, LLONG_MAX);
    dist[0] = 0;

    int a, b, c;
    vector<vector<pair<int, int>>> adjList(n);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        a--;
        b--;
        adjList[a].push_back({b, c});
    }

    auto cmp = [](const pair<int, long long> &a,
                  const pair<int, long long> &b)
    {
        return a.second > b.second;
    };

    priority_queue<
        pair<int, long long>,
        vector<pair<int, long long>>,
        decltype(cmp)>
        pq(cmp);

    pq.push({0, 0});

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        const auto &nextList = adjList[curr.first];

        if (curr.second != dist[curr.first])
            continue;

        for (auto next : nextList)
        {
            if (dist[curr.first] + next.second < dist[next.first])
            {
                dist[next.first] = dist[curr.first] + next.second;
                pq.push({next.first, dist[next.first]});
            }
        }
    }

    for (long long d : dist)
    {
        cout << d << " ";
    }
    return 0;
}
