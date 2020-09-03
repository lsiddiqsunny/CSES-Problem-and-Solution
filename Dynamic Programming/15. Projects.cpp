#include <bits/stdc++.h>
#define llow long long int
using namespace std;

struct job
{
    long long int start, finish, money;
};

bool comp(job j1, job j2)
{
    return (j1.finish < j2.finish);
}
int find(job a[], long long ind)
{
    int low = 0, hi = ind - 1;

    while (low <= hi)
    {
        int mid = (low + hi) / 2;
        if (a[mid].finish < a[ind].start)
        {
            if (a[mid + 1].finish < a[ind].start)
                low = mid + 1;

            else
                return mid;
        }

        else
            hi = mid - 1;
    }
    return -1;
}
int main()
{

    int n;
    cin >> n;

    struct job a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].start >> a[i].finish >> a[i].money;

    sort(a, a + n, comp);

    vector<long long> dp(n);
    dp[0] = a[0].money;
    for (int i = 1; i < n; i++)
    {
        long long temp = a[i].money;
        long long search = find(a, i);
        if (search != -1)
            temp += dp[search];
        dp[i] = max(dp[i - 1], temp);
    }

    cout << dp[n - 1] << endl;

    return 0;
}