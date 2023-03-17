#include <bits/stdc++.h>
using namespace std;

void merge(int l, int r, int mid, vector<int> &arr)
{
    if (l == r)
        return;

    vector<int> L, R;
    for (int i = l; i <= mid; i++)
        L.push_back(arr[i]);
    for (int i = mid + 1; i <= r; i++)
        R.push_back(arr[i]);

    int li = 0, ri = 0;
    while (li < L.size() and ri < R.size())
    {
        if (L[li] < R[ri])
        {
            arr[l + li + ri] = (L[li]);
            li++;
        }
        else
        {
            arr[l + li + ri] = (R[ri]);
            ri++;
        }
    }

    while (li < L.size())
    {
        arr[l + li + ri] = L[li];
        li++;
    }
    while (ri < R.size())
    {
        arr[l + li + ri] = R[ri];
        ri++;
    }
}

void mergesort(int l, int r, vector<int> &arr)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergesort(l, mid, arr);
    mergesort(mid + 1, r, arr);
    merge(l, r, mid, arr);
}

int main()
{
    vector<int> arr = {1, 7, -3, 2, -8, 5, 0, 180};
    mergesort(0, arr.size() - 1, arr);
    for (int val : arr)
        cout << "val: " << val << " ";
    cout << endl;
}