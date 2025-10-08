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
/*
One solution is to binary search the best length, as shown below:

bool sequenceExists(vector<int> &songs, int windowLength)
{
    unordered_map<int, int> myMap;

    for (int i = 0; i < windowLength; i++)
    {
        myMap[songs[i]]++;
    }
    if (myMap.size() == windowLength)
    {
        return true;
    }

    for (int it = windowLength; it < songs.size(); it++)
    {

        myMap[songs[it]]++;
        int windowStart = it - windowLength;

        myMap[songs[windowStart]]--;
        if (myMap[songs[windowStart]] == 0)
        {
            myMap.erase(songs[windowStart]);
        }

        if (myMap.size() == windowLength)
        {
            return true;
        }
    }

    return false;
}

But a better solution is an O(n) search using a last seen counter. The solution is O(n) if we use a hash map, using an ordered map makes it O(nlogn).
*/

// Problem : https://cses.fi/problemset/task/1141/

int main()
{
    int n;
    cin >> n;
    vector<int> songs(n);

    int songid;
    for (int i = 0; i < n; i++)
    {
        cin >> songid;
        songs[i] = songid;
    }

    int bestLength = 1;

    int left = 0;
    map<int, int> seenCounter;

    for (int right = 0; right < n; right++)
    {
        seenCounter[songs[right]]++;
        while (seenCounter[songs[right]] > 1)
        {
            seenCounter[songs[left]]--;
            left++;
        }
        bestLength = max(bestLength, right - left + 1);
    }

    cout << bestLength;

    return 0;
}