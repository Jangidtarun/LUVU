#include <bits/stdc++.h>
using namespace std;
const int N = 520;
const int INF = 1e9 + 10;

int d[N][N];

int main()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;

    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        d[v1][v2] = wt;
    }

    for (int k = 1; k <= v; k++)
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                if (d[i][k] != INF and d[k][j] != INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
            if (d[i][j] == INF)
                cout << 'I' << " ";
            else
                cout << d[i][j] << " ";
        cout << endl;
    }
}