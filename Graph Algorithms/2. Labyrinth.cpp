#include <bits/stdc++.h>
#include <chrono>
using namespace std;
int vis[1005][1005];
int grid[1005][1005];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
map<pair<int, int>, pair<int, int>> mp;
int n, m;
bool possible(int x, int y)
{

    return (x < n && x >= 0 && y < m && y >= 0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //std::chrono::steady_clock::time_point begin1 = std::chrono::steady_clock::now();
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int done=0;
    pair<int, int> start, end;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            
            if (s[i][j] == 'A')
            {
                start = {i, j};
                done++;
            }
            if (s[i][j] == 'B')
            {
                end = {i, j};
                done++;
                
            }
            if(done==2){
                break;
            }
        }
        if(done==2){
            break;
        }
    }
    
    queue<pair<int, int>> q;
    q.push(start);
    vis[start.first][start.second] = 1;
    mp[start] = {-1, -1};
    while (!q.empty())
    {
        pair<int, int> now = q.front();

        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if (!possible(nx, ny) or s[nx][ny]=='#' or vis[nx][ny])
            {
                continue;
            } //cout << nx << " " << ny << endl;
            mp[{nx, ny}] = now;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    if (vis[end.first][end.second])
    {
        cout << "YES\n";
        string ans = "";
        pair<int, int> now = end;
        while (now != start)
        {
            pair<int, int> par = mp[now];
            if (par.first == now.first)
            {
                if (par.second < now.second)
                {
                    ans += "R";
                }
                else
                {
                    ans += "L";
                }
            }
            else
            {
                if (par.first < now.first)
                {
                    ans += "D";
                }
                else
                {
                    ans += "U";
                }
            }
            now = par;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        cout << ans << endl;
    }
    else
    {
        cout << "NO\n";
    }
   // std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();

    //std::cout << "Time difference = " << chrono::duration_cast<chrono::microseconds>(end1 - begin1).count() / 1000000.0 << "[µs]" << std::endl;
    //std::cout << "Time difference = " << chrono::duration_cast<chrono::nanoseconds>(end1 - begin1).count() << "[ns]" << std::endl;
}