#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int depth[N], height[N];
vector<int> g[N];

void dfs(int vertex, int parent = 0)
{
    for (int child : g[vertex])
    {
        if (child != parent)
        {
            depth[child] = depth[vertex] + 1;
            dfs(child, vertex);
            height[vertex] = max(height[vertex], height[child] + 1);
        }
    }
}

int main()
{
    int v;
    cin >> v;
    for (int i = 0; i < v - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
    cout << endl;
    for (int i = 1; i <= v; i++)
        cout << depth[i] << " " << height[i] << endl;
}