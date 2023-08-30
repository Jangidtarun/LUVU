#include <bits/stdc++.h>
using namespace std;

int mcost(int n, vector<int> &h, vector<int> &cost)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return abs(h[2] - h[1]);
    if (cost[n] != -1)
        return cost[n];
    int c1 = mcost(n - 1, h, cost) + abs(h[n] - h[n - 1]);
    int c2 = mcost(n - 2, h, cost) + abs(h[n] - h[n - 2]);
    return cost[n] = min(c1, c2);
}

int main()
{
    int n;
    cin >> n;
    vector<int> h(n + 1), cost(n + 1, -1);
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    cout << mcost(n, h, cost) << endl;
}