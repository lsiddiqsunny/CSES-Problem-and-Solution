#include <bits/stdc++.h>
using namespace std;
int vis[100005];
vector<int> g[100005];
int n, m;
bool ok;
void dfs(int s, int c)
{
    vis[s] = c;
    for (auto v : g[s])
    {
        if (!vis[v])
        {
            if (c == 1)
                dfs(v, 2);
            else
            {
                dfs(v, 1);
            }
        }else if(vis[v]==c){
            ok=false;
        }
    }
}
int main()
{
    ok=true;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, 1);
        }
    }
    if(!ok){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        for(int i=1;i<=n;i++){
            cout<<vis[i]<<" ";
        }
    }
}