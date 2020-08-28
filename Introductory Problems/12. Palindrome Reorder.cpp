#include <bits/stdc++.h>
using namespace std;
int a[26] = {0};
int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < (int)s.size(); i++)
    {
        a[s[i] - 'A']++;
    }
    int odd = 0;
    for (int i = 0; i < 26; i++)
    {
        if (a[i] % 2 == 1)
        {
            odd++;
        }
    } //cout<<odd<<endl;
    if (odd > 1)
    {
        cout << "NO SOLUTION\n";
    }
    else
    {
        string ans = "";
        char mid;

        for (int i = 0; i < 26; i++)
        {
            if (a[i] % 2 == 0)
            {
                for (int k = 0; k < a[i] / 2; k++)
                {
                    ans += (char)(i + 'A');
                }
            }
            else
            {
                mid = (char)(i + 'A');
                for (int k = 0; k < a[i] / 2; k++)
                {
                    ans += (char)(i + 'A');
                }
            }
        }
        cout << ans;
        if (s.size() % 2)
        {
            cout << mid;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}