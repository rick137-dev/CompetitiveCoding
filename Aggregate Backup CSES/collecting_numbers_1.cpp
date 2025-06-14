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

int main()
{
    int N;
    cin >> N;
    vector<long long> array(N);
    unordered_map<int, int> findIndex;

    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
        findIndex[array[i]] = i;
    }

    int total = 1;

    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] != N && findIndex[array[i] + 1] < i)
        {
            total++;
        }
    }

    cout << total;

    return 0;
}