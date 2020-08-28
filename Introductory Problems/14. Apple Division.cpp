#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long mini = INT_MAX;
    for (long long i = 0; i < 1<<n; i++)
    {
        long long sum1 = 0, sum2 = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & 1 << j)
                sum1 += a[j];
            else
                sum2 += a[j];
        }
        mini = min(mini, abs(sum1 - sum2));
    }
    cout<<mini<<endl;
}