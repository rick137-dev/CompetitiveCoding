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
#include <bit>

using namespace std;
int mod = 1e9 + 7;

// Problem : https://cses.fi/problemset/task/2162/
// Best way to solve this is with a queue, for O(N) time. Using a priority queue could also work with a different logic but would require O(NlogN)

int main()
{
    int n;
    cin >> n;

    queue<int> myQueue;
    for (int i = 1; i <= n; i++)
    {
        myQueue.push(i);
    }

    while (!myQueue.empty())
    {
        int curr = myQueue.front();
        myQueue.pop();
        myQueue.push(curr);
        curr = myQueue.front();
        myQueue.pop();
        cout << curr << " ";
    }

    return 0;
}
