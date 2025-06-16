#include <boost/multiprecision/cpp_int.hpp>

// For convenience
using boost::multiprecision::cpp_int;
#include <iostream>

struct realNumber
{
    long long a;
    long long b;

    realNumber(long long a, long long b)
    {
        this->a = a;
        this->b = b;
    }

    void square()
    {
    }
    void multiply(long long x, long long y)
    {
    }

    int exponentiate(long N)
    {
    }
};

int main()
{
    cpp_int x = 1;
    cout << x;
    return 0;
}
