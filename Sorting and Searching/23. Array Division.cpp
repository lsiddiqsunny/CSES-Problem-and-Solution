#include <bits/stdc++.h>
using namespace std;
bool check(int n,long long a[],long long now,int k){

    int co=0;

    long long cursum=0;
    for(int i=0;i<n;i++){
        if(a[i]>now){
            return false;
        }
        if(cursum+a[i]>now){
            cursum=a[i];
            co++;
        }
        else{
            cursum+=a[i];
        }
    }
    if(cursum){
        co++;
    }

    return co<=k;
}
int main()
{
    int n, k;
    cin >> n >> k;

    long long a[n];
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    long long lo = 0, hi = sum;
    long long mid = 0;
    long long ans = 0;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (check(n,a,mid, k))
        {
            hi = mid - 1;
            ans = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout<<ans<<endl;
}