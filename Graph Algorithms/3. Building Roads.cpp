#include <bits/stdc++.h>
using namespace std;
int vis[100005];
vector<int>g[100005];
int n,m;
void dfs(int s)
{
    vis[s]=1;
    for(auto v:g[s]){
        if(!vis[v]){
            dfs(v);
        }
    }
    
}
int main()
{

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            ans.push_back(i);
        }
    }
    cout<<ans.size()-1<<endl;
    for(int i=0;i<ans.size()-1;i++){
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
   
}