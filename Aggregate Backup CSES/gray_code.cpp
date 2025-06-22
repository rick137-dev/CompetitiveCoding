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

string convertNum(long a, int N)
{
       string res = "";
       for (int i = N - 1; i >= 0; --i)
              res.push_back(((a >> i) & 1) + '0');
       return res;
}

int main()
{

       int N;
       cin >> N;
       long target = 1 << N;

       for (long i = 0; i < target; i++)
       {
              int gray = i ^ (i >> 1);
              cout << convertNum(gray, N) << "\n";
       }
       return 0;
}
