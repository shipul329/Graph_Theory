/// This problem is about BFS on a Grid

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;

vector<vector<pair<int, int> > > path;
vector<vector<bool> > vis;

int sx, sy, ex, ey;

vector<pair<int, int> > moves={{-1,0}, {1,0}, {0,-1}, {0,1}};

bool isValid(int x, int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return false;

    if(vis[x][y])
        return false;

    return true;
}

void bfs()
{
    queue<pair<int, int> > q;

    q.push({sx, sy});

    while(!q.empty())
    {
        int cx=q.front().first;
        int cy=q.front().second;

        q.pop();

        for(auto mv:moves)
        {
            int mvx=mv.first;
            int mvy=mv.second;

            if(isValid(cx+mvx, cy+mvy))
            {
                q.push({cx+mvx, cy+mvy});
                vis[cx+mvx][cy+mvy]=true;

                path[cx+mvx][cy+mvy]={mvx, mvy};
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

    path.resize(n);
    vis.resize(n);

    for(int i=0; i<n; i++)
    {
        path[i].resize(m);
        vis[i].resize(m);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            path[i][j]={-1, -1};

            char ch;
            cin >> ch;

            if(ch=='#')
                vis[i][j]=true;

            if(ch=='A')
            {
                sx=i;
                sy=j;
            }

            if(ch=='B')
            {
                ex=i;
                ey=j;
            }
        }
    }

    bfs();

    if(!vis[ex][ey])
    {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';

    vector<pair<int, int> > ans;

    pair<int, int> endd={ex, ey};

    while(endd.first!=sx || endd.second!=sy)
    {
        ans.push_back(path[endd.first][endd.second]);
        endd.first-=ans.back().first;
        endd.second-=ans.back().second;
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << '\n';

    for(auto ch:ans)
    {
        if(ch.first==1 && ch.second==0)
            cout << 'D';

        else if(ch.first==-1 && ch.second==0)
            cout << 'U';

        else if(ch.first==0 && ch.second==1)
            cout << 'R';

        else if(ch.first==0 && ch.second==-1)
            cout << 'L';
    }


    return 0;
}

/*

Input:
5 8
########
#.A#...#
#.##.#B#
#......#
########

Output:
YES
9
LDDRRRRRU

*/
