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

// Greedy solution to maximum non overlapping intervals is well known, we must order by end value and iteratively check which intervals we can fit

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> movies;

    int a, b;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        movies.push_back({a, b});
    }

    sort(movies.begin(), movies.end(), [](vector<int> a, vector<int> b)
         { return a[1] < b[1]; });

    int total = 1;
    a = movies[0][0];
    b = movies[0][1];

    for (int i = 1; i < N; i++)
    {
        if (movies[i][0] >= b)
        {
            total++;
            a = movies[i][0];
            b = movies[i][1];
        }
    }

    cout << total;
    return 0;
}