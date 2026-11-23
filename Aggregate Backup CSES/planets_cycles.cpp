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
int mod = 1e9 + 7;

// Problem : https://cses.fi/problemset/task/1751

// This can be solved with a standard DFS, although skipping recursion due to the possibility of causing a stack overflow
// The main idea here is to explore until a node has been seen in the current exploration or has been explored in a previous exploration cycle
// Also it's important to mark the nodes inside a cycle with the same cycle length, and only those that have exited the cycle with increasing lengths

int explore(int start, vector<int> &next, vector<int> &steps)
{
    if (steps[start] != -1)
    {
        return steps[start];
    }

    unordered_map<int, int> currIndex;
    vector<int> seenNums;

    currIndex[start] = 0;
    seenNums.push_back(start);

    int curr = next[start];
    int index = 1;

    while (currIndex.count(curr) == 0 && steps[curr] == -1)
    {
        currIndex[curr] = index;
        seenNums.push_back(curr);
        index++;
        curr = next[curr];
    }

    if (steps[curr] != -1)
    {
        int count = steps[curr];

        while (!seenNums.empty())
        {
            steps[seenNums.back()] = ++count;
            seenNums.pop_back();
        }

        return steps[start];
    }

    int cycleSize = seenNums.size() - currIndex[curr];

    while (seenNums.size() > 0)
    {
        steps[seenNums.back()] = cycleSize;

        if (seenNums.back() == curr)
        {
            seenNums.pop_back();
            break;
        }
        seenNums.pop_back();
    }

    cycleSize++;

    while (seenNums.size() > 0)
    {
        steps[seenNums.back()] = cycleSize;
        seenNums.pop_back();
        cycleSize++;
    }

    return steps[start];
}

int main()
{
    int n;
    cin >> n;
    vector<int> next(n);
    int temp;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        next[i] = temp - 1;
    }

    vector<int> steps(n, -1);

    for (int i = 0; i < n; i++)
    {
        explore(i, next, steps);
    }

    for (int i = 0; i < n; i++)
    {
        cout << steps[i] << " ";
    }

    return 0;
}
