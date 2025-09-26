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

// Problem : https://cses.fi/problemset/task/1619/

/*
Used a min-queue to store upcoming end times for customers, and traversed the list ordered by start time.
*/
struct Comparator
{

    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> times(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        times[i] = {a, b};
    }
    sort(times.begin(), times.end(), [](pair<int, int> &a, pair<int, int> &b)
         { return a.first < b.first; });

    priority_queue<int, vector<int>, Comparator> myQueue;

    int max_people = 0;

    for (pair<int, int> &time : times)
    {

        int start = time.first;
        int end = time.second;

        while (myQueue.size() > 0 && myQueue.top() < start)
        {
            myQueue.pop();
        }

        myQueue.push(end);
        max_people = max(max_people, (int)myQueue.size());
    }

    cout << max_people;

    return 0;
}