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

using namespace std;
// Problem : https://cses.fi/problemset/task/1660

int main()
{

    int N, target;
    cin >> N >> target;
    vector<int> array(N);
    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }
    int curr_sum = 0;
    int left = 0;
    long total_count = 0;
    for (int right = 0; right < N; right++)
    {
        curr_sum += array[right];

        while (curr_sum > target)
        {
            curr_sum = curr_sum - array[left];
            left++;
        }
        if (curr_sum == target)
        {
            total_count++;
            curr_sum = curr_sum - array[left];
            left++;
        }
    }

    cout << total_count;

    return 0;
}