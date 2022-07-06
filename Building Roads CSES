#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, cc=0;

vector<vector<int> > g;

vector<bool>vis;
vector<int>lead;

void dfs(int u)
{
    vis[u]=true;

    for(auto v:g[u])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }
}

void process_cc()
{
    for(auto i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            cc++;
            lead.push_back(i);
            dfs(i);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    g.resize(n+1);
    vis.resize(n+1);

    for(auto i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    process_cc();

    cout << cc-1 << '\n';

    if(cc>1)
    {
        int u=lead[0];
        int v;

        for(auto i=1; i<cc; i++)
        {
            v=lead[i];

            cout << u << " " << v << '\n';
            u=v;
        }
    }

    return 0;
}

/*
input 
4 2
1 2
3 4

output
1
2 3
*/
