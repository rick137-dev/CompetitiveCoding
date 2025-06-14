#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Kadane's algorithm solution
int main()
{
    int N;
    cin >> N;
    vector<long long> array(N);
    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }

    long long max_sum = array[0];
    long long temp_sum = array[0];

    for (int i = 1; i < N; i++)
    {
        temp_sum = max(temp_sum + array[i], array[i]);
        max_sum = max(max_sum, temp_sum);
    }
    cout << max_sum;
    return 0;
}