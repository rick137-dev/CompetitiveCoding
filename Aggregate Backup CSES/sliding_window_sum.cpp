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
#include <climits>
#include <map>

using namespace std;

int main()
{

       long N, k;
       cin >> N >> k;
       long long x, a, b, c;
       cin >> x >> a >> b >> c;

       long long curr_sum = 0;
       long long curr_element = x;
       long long first_element = x;

       for (long i = 0; i < k; i++)
       {
              curr_sum += curr_element;
              curr_element = (a * curr_element + b) % c;
       }

       long long xor_sum = curr_sum;

       for (long i = k; i < N; i++)
       {

              curr_sum += curr_element;
              curr_sum -= first_element;

              curr_element = (a * curr_element + b) % c;
              first_element = (a * first_element + b) % c;
              xor_sum = xor_sum ^ curr_sum;
       }
       cout << xor_sum;
       return 0;
}