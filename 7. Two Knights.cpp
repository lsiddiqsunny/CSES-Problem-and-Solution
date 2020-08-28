#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int tab[10005 ];
    tab[1] = 0;
    tab[2] = 6;
    tab[3] = 28;
    tab[4] = 96;
    tab[5] = 252;
    for(int i=6;i<10005;i++){
        tab[i] = tab[i-1]*5+tab[i-2]*-10+tab[i-3]*10+tab[i-4]*-5+tab[i-5];
    }
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<tab[i]<<endl;
    }

}