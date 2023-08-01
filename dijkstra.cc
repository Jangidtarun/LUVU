#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
typedef pair<int, int> int_pair;

int level[N];
int vis[N];
int v, e;
vector<pair<int, int>> g[N];

void reset()
{
    for (int i = 0; i <= v; i++)
    {
        level[i] = INF;
        vis[i] = false;
    }
}

void dijkstra(int start)
{
    priority_queue<int_pair, vector<int_pair>, greater<int_pair>> q;
    level[start] = 0;
    q.push({start, level[start]});

    while (!q.empty())
    {
        auto cv = q.top();
        vis[cv.first] = true;
        cout << cv.first << " " << cv.second << endl;
        q.pop();
        for (auto child : g[cv.first])
        {
            int current_level = level[child.first];
            int next_level = level[cv.first] + child.second;
            if (!vis[child.first])
            {
                if (current_level > next_level)
                    level[child.first] = next_level;
                q.push({child.first, level[child.first]});
            }
        }
    }
}

int main()
{
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        reset();
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        if (v1 != v2)
            g[v1].push_back({v2, w});
    }

    dijkstra(1);
    for (int i = 1; i <= v; i++)
        cout << i << ": " << level[i] << endl;
}