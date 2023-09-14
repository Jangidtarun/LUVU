#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int dp[N];

int f(int len, vector<int> &prices)
{
    if (len == 0)
        return 0;
    if (dp[len] != -1)
        return dp[len];
    int ans = 0;
    for (int lcut = 1; lcut <= prices.size(); lcut++)
        if (len - lcut >= 0)
            ans = max(ans, f(len - lcut, prices) + prices[lcut - 1]);
    return dp[len] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n = 8;
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};

    int ans = f(n, prices);
    cout << ans << endl;
}