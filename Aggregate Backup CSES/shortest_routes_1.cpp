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

int main()
{
    long n, m;
    cin >> n >> m;
    long a, b, c;
    unordered_map<long, vector<pair<long, long>>> Alist;

    for (long i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        Alist[a].push_back({b, c});
    }

    vector<long> distances(n + 1, LONG_MAX); // This is 1-indexed
    distances[1] = 0;

    priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> myQueue;
    myQueue.push({0, 1}); // This is where we start from

    while (!myQueue.empty())
    {
        long current_distance = myQueue.top().first;
        long current_node = myQueue.top().second;
        myQueue.pop();

        if (current_distance > distances[current_node])
        {
            continue;
        }

        for (auto &edge : Alist[current_node])
        {
            long v = edge.first;
            long weight = edge.second;

            if (distances[v] > distances[current_node] + weight)
            {
                distances[v] = distances[current_node] + weight;
                myQueue.push({distances[v], v});
            }
        }
    }

    for (long i = 1; i <= n; i++)
    {
        cout << distances[i] << " ";
    }

    return 0;
}
