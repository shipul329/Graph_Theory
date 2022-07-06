/// This problem is about Bipartite Graph also known as 2 Color Problem

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;

vector<vector<int> > g;

vector<bool>vis;
vector<int>color;

bool dfs(int u, int c, int par)
{
    vis[u]=true;
    color[u]=c;

    for(auto v:g[u])
    {
        if(v==par) continue;

        if(color[v]==0)
        {
            if(!dfs(v, (color[u]^3), u)){
                return false;
            }
        }

        if(color[v]==color[u])
        {
            return false;
        }
    }

    return true;
}

bool color_all()
{
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            if(!dfs(i, 1, -1)){
            return false;
            }
        }
    }

    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    g.resize(n+1);
    vis.resize(n+1);
    color.resize(n+1);

    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool ans=color_all();

    if(!ans)
    {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    for(int i=1; i<=n; i++)
        cout << color[i] << " ";

    return 0;
}

/*
Input:
5 3
1 2
1 3
4 5

Output:
1 2 2 1 2
*/
