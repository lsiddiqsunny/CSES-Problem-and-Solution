#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, n;
    cin >> x >> n;
    set<int> points = {0, x};
    multiset<int> lengths = {x};
    while (n--)
    {
        int point;
        cin >> point;
        auto it = points.upper_bound(point);

        int left = *prev(it);
        int right = *it;

        lengths.erase(lengths.find(right - left));
        lengths.insert(point - left);
        lengths.insert(right - point);

        points.insert(it, point);

        cout << *lengths.rbegin() << " ";
    }
}