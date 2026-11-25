#include <vector>

using namespace std;

template <typename T>
class FenwickTree
{
public:
    vector<T> tree;
    FenwickTree(vector<T> nums)
    {
        tree.resize(nums.size() + 1);

        for (T i = 1; i < tree.size(); i++)
        {
            tree[i] += nums[i - 1];

            int parent = i + (i & -i);

            if (parent < tree.size())
            {
                tree[parent] += tree[i];
            }
        }
    }

    void update(T index, T numToReplace)
    {
        T oldValue = sum(index) - sum(index - 1);
        T delta = numToReplace - oldValue;

        while (index < tree.size())
        {
            tree[index] += delta;
            index += (index & -index);
        }
    }

    T sum(T index)
    {
        T currSum = 0;

        while (index > 0)
        {
            currSum += tree[index];
            index -= (index & -index);
        }

        return currSum;
    }
};