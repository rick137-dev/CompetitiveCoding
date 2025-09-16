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

// Problem : https://cses.fi/problemset/task/1640

int main()
{
    long N, target;
    cin >> N >> target;

    vector<pair<long, long>> array(N);

    for (int i = 0; i < N; i++)
    {
        cin >> array[i].first;
        array[i].second = i;
    }
    sort(array.begin(), array.end(), [](pair<long, long> a, pair<long, long> b)
         { return a.first < b.first; });

    long left = 0;
    long right = N - 1;
    long temp;
    while (left < right)
    {
        temp = array[left].first + array[right].first;
        if (temp == target)
        {
            cout << array[left].second + 1 << " " << array[right].second + 1;
            return 0;
        }
        else if (temp < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}