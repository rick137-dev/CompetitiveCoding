#include <deque>
#include <stdexcept>

using namespace std;

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
