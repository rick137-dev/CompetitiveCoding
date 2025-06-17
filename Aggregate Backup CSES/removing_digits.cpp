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

int maxDigit(long a)
{
       int curr = a % 10;
       while (a > 0)
       {
              int last = a % 10;
              curr = max(curr, last);
              a = a / 10;
       }
       return curr;
}

int main()
{

       int N;
       cin >> N;

       long steps = 0;
       while (N > 0)
       {
              int toRemove = maxDigit(N);
              N = N - toRemove;
              steps++;
       }
       cout << steps;
       return 0;
}
