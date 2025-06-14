#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

int main()
{
    long N;
    cin >> N;

    while (N != 1)
    {
        cout << N << " ";
        if (N % 2 == 0)
        {
            N = N / 2;
        }
        else
        {
            N = 3 * N + 1;
        }
    }
    cout << "1";
    return 0;
}
