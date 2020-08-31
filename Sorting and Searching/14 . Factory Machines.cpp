#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long k;
    cin >> n >> k;
    long long int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long int lo = 0;
    long long int hi = *max_element(a, a + n) * k + 1;

    long long int mid;
    long long int ans = 0;
    while (lo <= hi)
    {

        mid = (lo + hi) / 2;
        long long int now = 0;
        for (int i = 0; i < n; i++)
        {
            now += (mid / a[i]);
            //cout<<(mid/a[i])<<endl
        }
        //cout << ans <<" "<<" "<<mid<<" "<<now<< endl;
        if (now >= k)
        {
            ans = mid;
           
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << ans << endl;
}