#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
const int N = 8;
bool vis[N][N];
int level[N][N];

void init()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            vis[i][j] = false;
            level[i][j] = INF;
        }
}

vector<pair<int, int>> dir = {
    {1, 2},
    {1, -2},
    {-1, 2},
    {-1, -2},
    {-2, 1},
    {-2, -1},
    {2, 1},
    {2, -1},
};

bool isValid(pair<int, int> loc)
{
    return loc.first >= 0 and loc.second > 0 and
           loc.first < N and loc.second < N;
}

pair<int, int> getloc(string loc)
{
    int x = loc[0] - 'a';
    int y = loc[1] - '1';
    return {x, y};
}

int bfs(string start, string end)
{
    init();
    pair<int, int> source = getloc(start);
    pair<int, int> dest = getloc(end);
    queue<pair<int, int>> q;
    q.push(source);
    vis[source.first][source.second] = true;
    level[source.first][source.second] = 0;
    while (!q.empty())
    {
        pair<int, int> cur_loc = q.front();
        q.pop();
        for (pair<int, int> move : dir)
        {
            pair<int, int> child = {cur_loc.first + move.first,
                                    cur_loc.second + move.second};

            if (isValid(child) and !vis[child.first][child.second])
            {
                q.push(child);
                vis[child.first][child.second] = true;
                level[child.first][child.second] = level[cur_loc.first][cur_loc.second] + 1;
            }
        }
        if (level[dest.first][dest.second] != INF)
            break;
    }
    return level[dest.first][dest.second];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string start, dest;
        cin >> start >> dest;
        int ans = bfs(start, dest);
        cout << ans << endl;
    }
}