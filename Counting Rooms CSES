/// Counting Rooms CSES problem

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m, rooms;

vector<vector<bool> > vis;

vector<pair<int, int> > moves={{-1,0}, {1,0}, {0,-1}, {0,1}};

bool isValid(ll x, ll y)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return false;

    if(vis[x][y])
        return false;

    return true;
}

void dfs(ll i, ll j)
{
    vis[i][j]=true;

    for(auto p:moves)
    {
        if(isValid(i+p.first, j+p.second))
        {
            dfs(i+p.first, j+p.second);
        }
    }
}

void connected_components()
{
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            if(!vis[i][j])
            {
                dfs(i, j);
                rooms++;
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

    vis.resize(n);

    for(ll i=0; i<n; i++)
    {
        vis[i].resize(m);
    }

    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<m; j++)
        {
            char ch;
            cin >> ch;

            if(ch=='#')
            {
                vis[i][j]=true;
            }
        }
    }

    connected_components();

    cout << rooms << '\n';
}

/*
intput 
5 8
########
#..#...#
####.#.#
#..#...#
########

output 
3

*/
