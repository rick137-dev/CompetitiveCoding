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
#include <stack>
#include <map>
#include <cmath>

using namespace std;
int mod = 1e9 + 7;

// Problem : https://cses.fi/problemset/task/3221

template <typename T>
class MonotonicDeque
{
private:
    deque<T> myQueue;

public:
    T getMinimum()
    {

        return myQueue.front();
    }
    void removeNumber(T num)
    {
        if (myQueue.size() > 0 && myQueue.front() == num)
        {
            myQueue.pop_front();
        }
    }

    void insertNumber(T number)
    {
        while (myQueue.size() > 0 && myQueue.back() > number)
        {
            myQueue.pop_back();
        }
        myQueue.push_back(number);
    }
};

int main()
{

    MonotonicDeque<long> myMonDeque;

    long n, k;
    cin >> n >> k;
    long x, a, b, c;
    cin >> x >> a >> b >> c;

    long first_window_element = x;
    long current = x;

    for (long i = 0; i < k; i++)
    {
        myMonDeque.insertNumber(current);
        current = (a * current + b) % c;
    }

    long min_xor = myMonDeque.getMinimum();

    for (long i = k; i < n; i++)
    {
        myMonDeque.removeNumber(first_window_element);
        myMonDeque.insertNumber(current);
        min_xor = min_xor ^ myMonDeque.getMinimum();
        current = (a * current + b) % c;
        first_window_element = (a * first_window_element + b) % c;
    }

    cout << min_xor;
    return 0;
}