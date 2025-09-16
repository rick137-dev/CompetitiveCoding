
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

// Problem : https://cses.fi/problemset/task/1132

// This is a DP based solution using DP on trees

void farthestNode(vector<vector<int>> &Alist, int currentNode, vector<bool> &visited, int &maxDist, int &farNode, int currentDistance)
{
    visited[currentNode] = true;
    if (currentDistance > maxDist)
    {
        maxDist = currentDistance;
        farNode = currentNode;
    }

    for (int next : Alist[currentNode])
    {
        if (!visited[next])
        {
            farthestNode(Alist, next, visited, maxDist, farNode, currentDistance + 1);
        }
    }
}

void distanceFromNode(vector<vector<int>> &Alist, int currentNode, vector<bool> &visited, vector<int> &distances, int currentDistance)
{
    visited[currentNode] = true;
    distances[currentNode] = currentDistance;
    for (int next : Alist[currentNode])
    {
        if (!visited[next])
        {
            distanceFromNode(Alist, next, visited, distances, currentDistance + 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> Alist(n);
    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        Alist[a].push_back(b);
        Alist[b].push_back(a);
    }

    vector<bool> visited(n, false);
    int maxDist = 0;
    int farNode = 0;

    farthestNode(Alist, 0, visited, maxDist, farNode, 0);
    int X = farNode;
    int Y = 0;
    fill(visited.begin(), visited.end(), false);
    maxDist = 0;

    farthestNode(Alist, X, visited, maxDist, Y, 0);

    vector<int> distance_from_X(n);
    vector<int> distance_from_Y(n);

    fill(visited.begin(), visited.end(), false);
    distanceFromNode(Alist, X, visited, distance_from_X, 0);

    fill(visited.begin(), visited.end(), false);
    distanceFromNode(Alist, Y, visited, distance_from_Y, 0);

    for (int i = 0; i < n; i++)
    {
        cout << max(distance_from_Y[i], distance_from_X[i]) << " ";
    }

    return 0;
}
