#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
int grid[N][N];
string maze[N];
int vis[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;
bool possible(int x, int y)
{

    return (x < n && x >= 0 && y < m && y >= 0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, j, x;
    cin >> n >> m;
    string s;
    vector<pair<int, int>> mon;
    int ax, ay;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            vis[i][j] = 0;
            maze[i] = s;
            if (s[j] == 'A')
            {
                ax = i;
                ay = j;
            }
            if (s[j] == 'M')
            {
                mon.push_back({i, j});
            }
        }
    }
    queue<pair<int, pair<int, int>>> q;

    for (int i = 0; i < mon.size(); i++)
    {
        q.push({0, {mon[i].first, mon[i].second}});
        vis[mon[i].first][mon[i].second] = 1;
    }

    while (q.size() > 0)
    {
        pair<int, int> p = q.front().second;
        int lvl = q.front().first;
        q.pop();
        grid[p.first][p.second] = lvl;
        for (int i = 0; i < 4; i++)
        {
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if (!possible(nx, ny))
                continue;
            if (maze[nx][ny] == '#')
                continue;
            if (vis[nx][ny] != -1)
                continue;
            q.push({lvl + 1, {nx, ny}});
            vis[nx][ny] = 1;
        }
    }
    /*
 	fo(i,0,n){
 		fo(j,0,m){
 			cout<<grid[i][j]<<" ";
 		}
 		cout<<endl;
 	}
 	cout.flush();
 	*/
    memset(vis, 0, sizeof(vis));
    pair<int, int> from[n + 1][m + 1];
    char dir[n + 1][m + 1];
    s = "RLDU";
    q.push({0, {ax, ay}});
    pair<int, int> to = {-1, -1};
    bool mm = mon.size() > 0;
    while (q.size() > 0)
    {
       pair<int, int> p = q.front().second;
        int lvl = q.front().first;
        q.pop();
        if (grid[p.first][p.second] != -1 && lvl >= grid[p.first][p.second])
        {
            //cout<<p.x<<" "<<p.y<<" "<<lvl<<" "<<grid[p.x][p.y]<<endl;
            continue;
        }

        //cout<<p.x<<" "<<p.y<<":";
        if (p.first == 0 || p.first == n - 1 || p.second == 0 || p.second == m - 1)
        {
            to = {p.first, p.second};
            break;
        }
        for(int i=0;i<4;i++)
        {
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if (!possible(nx, ny))
                continue;
            if (maze[nx][ny] == '#')
                continue;
            if (vis[nx][ny] != -1)
                continue;
            if (grid[nx][ny] != -1 && grid[nx][ny] <= lvl)
                continue;
            from[nx][ny] = p;
            q.push({lvl + 1, {nx, ny}});
            vis[nx][ny] = 1;
            dir[nx][ny] = s[i];
            //cout<<"("<<nx<<","<<ny<<") ";

            if (nx == 0 || nx == n - 1 || ny == 0 || ny == m - 1)
            {
                //cout<<lvl<<" "<<

                to = {nx, ny};
                break;
            }
        }

        if (to.first != -1)
            break;
        //cout<<endl;
    }
    //	cout<<to.x<<" "<<to.y<<" "<<ax<<" "<<ay<<endl;
    if (to.first == -1)
    {
        cout<<"NO\n";
        return 0;
    }
    cout << "YES" << endl;
    s = "";
    while (to.first != ax || to.second != ay)
    {
        s += dir[to.first][to.second];
        //cout<<to.x<<" "<<to.y
        to = from[to.first][to.second];
    }
    reverse(s.begin(),s.end());
    cout << s.size() << endl;
    cout << s << endl;

    return 0;
}