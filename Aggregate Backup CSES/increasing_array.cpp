#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> array(N);
    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }
    long long total = 0;
    int curr_max = array[0];
    for (int i = 0; i < N; i++)
    {
        if (array[i] >= curr_max)
        {
            curr_max = array[i];
        }
        else
        {
            total += (long long)(curr_max - array[i]);
        }
    }
    cout << total;

    return 0;
}
