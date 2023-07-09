/// This is a cycle retrival problem

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
int sv, ev;

vector<vector<int> > g;

vector<bool>vis;
vector<int>parent;

bool dfs(int u, int p)
{
    vis[u]=true;
    parent[u]=p;

    for(auto v:g[u])
    {
        if(v==p) continue;

        if(vis[v])
        {
            sv=v;
            ev=u;

            return true;
        }

        if(!vis[v])
        {
            if(dfs(v, u))
                return true;
        }
    }

    return false;
}

bool visit_all()
{
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            if(dfs(i, -1)){
            return true;
            }
        }
    }

    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    g.resize(n+1);
    vis.resize(n+1);
    parent.resize(n+1);

    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    if(!visit_all())
    {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    int tv=ev;

    vector<int>ans;
    ans.push_back(ev);

    while(tv!=sv)
    {
        ans.push_back(parent[tv]);
        tv=parent[tv];
    }

    ans.push_back(ev);

    cout << ans.size() << '\n';

    for(auto it:ans)
        cout << it << " ";

    return 0;
}

/*
input
5 6
1 3
1 2
5 3
1 5
2 4
4 5

Output:
4
5 3 1 5
*/
