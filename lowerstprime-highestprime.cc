#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 100;
    vector<bool> is_prime(n, true);
    vector<int> lp(n, 0), hp(n, 0);
    is_prime[1] = false;
    for (int i = 1; i < n; i++)
    {
        if (is_prime[i])
        {
            lp[i] = hp[i] = i;
            for (int j = 2 * i; j < n; j += i)
            {
                is_prime[j] = false;
                hp[j] = i;
                if (!lp[j])
                    lp[j] = i;
            }
        }
    }

    vector<vector<int>> prime_factors(n);
    prime_factors[1].push_back(-1);
    for (int i = 1; i < n; i++)
    {
        int query = i;
        while (query > 1)
        {
            int prime_factor = hp[query];
            while (query % prime_factor == 0)
            {
                prime_factors[i].push_back(prime_factor);
                query /= prime_factor;
            }
        }
        cout << i << ": ";
        for (auto val : prime_factors[i])
            cout << val << " ";
        cout << endl;
    }
}