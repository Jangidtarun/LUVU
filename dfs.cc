#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int depth[N], height[N];
int subsum[N], evencount[N], oddcount[N];
vector<int> g[N];

void dfs(int vertex, int parent = 0)
{
    subsum[vertex] += vertex;
    if (vertex % 2)
        oddcount[vertex]++;
    else
        evencount[vertex]++;
    for (int child : g[vertex])
    {
        if (child != parent)
        {
            depth[child] = depth[vertex] + 1;
            dfs(child, vertex);
            height[vertex] = max(height[vertex], height[child] + 1);
            subsum[vertex] += subsum[child];
            evencount[vertex] += evencount[child];
            oddcount[vertex] += oddcount[child];
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
    cout << endl;
    for (int i = 1; i <= v; i++)
        cout << evencount[i] << " " << oddcount[i] << endl;
    cout << endl;
    for (int i = 1; i <= v; i++)
        cout << subsum[i] << endl;

    int diameter = -1;
    int diamNode = -1;
    for (int i = 1; i <= v; i++)
    {
        if (diameter < depth[i])
        {
            diameter = depth[i];
            diamNode = i;
        }
        depth[i] = 0;
    }

    dfs(diamNode);
    cout << endl;
    for (int i = 0; i <= v; i++)
        if (diameter < depth[i])
            diameter = depth[i];
    cout << diameter << endl;
}