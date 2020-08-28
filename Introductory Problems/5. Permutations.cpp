#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    if (n <= 3)
    {
        cout << "NO SOLUTION\n";
        return 0;
    }
    int ans[n + 1];

        int now = 1;
        for (int i = n / 2 ; i >= 1; i--)
        {
            ans[i] = now;
            now += 2;
        }
        ans[n / 2 + 1] = n;
        now = 2;
        for (int i = n / 2 + 2; i <= n; i++)
        {
            ans[i] = now;
            now += 2;
        }
   for(int i=1;i<=n;i++){
       cout<<ans[i]<<" ";
   }
   cout<<endl;
}