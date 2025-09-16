#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Problem : https://cses.fi/problemset/task/1621

int main()
{

    // I was forced to use a sorting solution instead of hash set due to inputs being tweaked to cause collisions in hash set
    int N;
    cin >> N;
    vector<int> array(N);
    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }
    sort(array.begin(), array.end());
    int total = 0;

    for (int i = 1; i < N; i++)
    {
        if (array[i] != array[i - 1])
            total++;
    }
    cout << total + 1;
    return 0;
}