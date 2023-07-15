#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
bool vis[N];
int lev[N];
vector<int> g[N];

int bfs(vector<int> &source)
{
    queue<int> q;
    for (int s : source)
    {
        q.push(s);
        lev[s] = 0;
        vis[s] = true;
    }

    while (!q.empty())
    {
        int curv = q.front();
        q.pop();
        for (int child : g[curv])
        {
            q.push(child);
            lev[child] = lev[curv] + 1;
            vis[child] = true;
        }
    }
    return lev[0];
}

int main()
{
}