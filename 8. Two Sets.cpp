#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long sum = n * (n + 1);
    sum /= 2;
    if (sum % 2 == 1)
    {
        cout << "NO\n";
        return 0;
    }
    else
    {
        cout << "YES\n";
        vector<int> a, b;
        int now=0;
        if (n % 4 == 3)
        {
            a.push_back(1);
            a.push_back(2);
            b.push_back(3);
            now = 3;
        }
        
        while (now < n)
        {
            a.push_back(now + 1);
            a.push_back(now + 4);

            b.push_back(now + 2);
            b.push_back(now + 3);
            now += 4;
        }
        cout << a.size() << endl;
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        cout << b.size() << endl;
        for (int i = 0; i < b.size(); i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;
    }
}