#include <bits/stdc++.h>
using namespace std;

void make_set(int v, vector<int> &parent)
{
    parent[v] = v;
}

int find_set(int v, vector<int> &parent)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent);
}

void union_set(int u, int v, vector<int> &parent, vector<int> &size)
{
    u = find_set(u, parent);
    v = find_set(v, parent);
    if (u != v)
    {
        if (size[u] < size[v])
            swap(u, v);
        parent[v] = u;
        size[u] += size[v];
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> parent(v + 1);
    vector<int> size(v + 1);
    
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({wt, {u, v}});
    }
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= v; i++)
        make_set(i, parent);

    int cost = 0;
    for (auto edge : edges)
    {
        int wt = edge.first;
        int u = edge.second.first, v = edge.second.second;
        if (find_set(u, parent) != find_set(v, parent))
        {
            union_set(u, v, parent, size);
            cost += wt;
            cout << u << " " << v << endl;
        }
    }
    cout << cost << endl;
}