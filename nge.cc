#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    // n = 6;
    vector<int> v(n);
    unordered_map<int, int> nge;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        nge[v[i]];
    }
    stack<int> ng;
    for (int i = 0; i < n; i++)
    {

        while (!ng.empty() and ng.top() < v[i])
        {
            nge[ng.top()] = v[i];
            ng.pop();
        }
        ng.push(v[i]);
    }

    while (!ng.empty())
    {
        nge[ng.top()] = -1;
        ng.pop();
    }

    for (auto val : nge)
        cout << val.first << " " << val.second << endl;
}