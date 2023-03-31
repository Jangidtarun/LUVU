#include <bits/stdc++.h>
using namespace std;

int lowerbound(const vector<int> &v, int val)
{
    int start = 0;
    int end = v.size();
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (v[mid] == val)
            return mid;
        if (v[mid] < val)
            start = mid + 1;
        else
            end = mid;
    }
    if (v[start] > val)
        return start;
    return -1;
}

int upperbound(const vector<int> &v, int val)
{
    int start = 0;
    int end = v.size();
    int it = -1;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (v[mid] == val)
            it = mid;
        if (v[mid] <= val)
            start = mid + 1;
        else
            end = mid;
    }

    if (it != -1)
    {
        if (it + 1 != v.size())
            return it + 1;
        if (it + 1 == v.size())
            return -1;
    }
    // else
    // {
    //     if (v[start] == val)
    //     {
    //         if (start + 1 != v.size())
    //             return start + 1;
    //     }
    //     else if (v[start] > val)
    //         return start;
    // }
    return it;
}

int main()
{
    vector<int> v = {2, 4, 5, 7, 8, 25};
    int val = 25;
    int lb = lowerbound(v, val);
    int ub = upperbound(v, val);
    cout << "lb: " << lb << " ub: " << ub << endl;
}