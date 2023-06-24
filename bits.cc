#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int binexpo(int a, int b)
{
    if (b == 0)
        return 1;
    int expo = binexpo(a, b / 2);
    if (b & 1)
        return (a * ((expo * 1LL * expo) % M)) % M;
    else
        return (expo * 1LL * expo) % M;
}

int main()
{
    int a = 2, b = 30;
    cout << "rec: " << binexpo(a, b) << endl;
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (1LL * ans * a) % M;
        a = (1LL * a * a) % M;
        b >>= 1;
    }
    cout << "ite: " << ans << endl;
    cout << (1 << 30) << endl;
}