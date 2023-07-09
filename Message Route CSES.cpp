/// This is a single source shortest path problem

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;

vector<vector<int> > g;

vector<bool>vis;
vector<int>par;

void bfs()
{
    vis[1]=true;

    queue<int>q;

    q.push(1);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(auto v:g[u])
        {
            if(!vis[v])
            {
                vis[v]=true;
                par[v]=u;
                q.push(v);
            }
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
    par.resize(n+1);

    for(auto i=0; i<=n; i++)
    {
        par[i]=-1;
    }

    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs();

    if(par[n]==-1)
    {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    int candidate=n;

    stack<int>st;

    while(candidate!=-1)
    {
        st.push(candidate);
        candidate=par[candidate];
    }

    cout << st.size() << '\n';

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}

/*
input
5 5
1 2
1 3
1 4
2 3
5 4

coutput
3
1 4 5
*/
