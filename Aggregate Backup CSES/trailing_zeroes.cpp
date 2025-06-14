#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    int zeros = 0;
    for (int i = 5; i <= N; i = i * 5)
    {
        zeros += N / i;
    }
    cout << zeros;
    return 0;
}
