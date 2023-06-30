#include <bits/stdc++.h>
using namespace std;

const int N = 1e8 + 7;
vector<int> graph[N];
bool vis[N];
vector<vector<int>> cc;
int ct = 0;

bool dfs(vector<int> g[], int vertex, int parent)
{
    cout << "\n"
         << vertex << ": ";
    vis[vertex] = true;
    bool loopexist = false;
    cc[ct].push_back(vertex);
    for (int child : g[vertex])
    {
        cout << child << " ";
        if (vis[child] and child == parent)
            continue;
        if (vis[child])
            return true;
        loopexist |= dfs(g, child, vertex);
        // loopexist = true;
    }
    return loopexist;
}

int main()
{
    int v, e;
    cin >> v >> e;
    for (int j = 0; j < e; j++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            cc.push_back(vector<int>());
            if (dfs(graph, i, 0))
                cout << "\nloop exists";
            else
                cout << "\nNAH";
            ct++;
        }
    }

    cout << "\ncc: " << cc.size() << endl;
    for (auto c_cc : cc)
    {
        for (auto vertex : c_cc)
            cout << vertex << " ";
        cout << endl;
    }
}