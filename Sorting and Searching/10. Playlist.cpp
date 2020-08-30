#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   long long int a[n];
   for(int i=0;i<n;i++){
       cin>>a[i];
   }
   int i = 0, j = 0, max_len = 0, curr_len = 0;
	map<int, int> freq;
	while (j < n)
	{
		if (freq.find(a[j]) == freq.end() || freq[a[j]] == 0)
		{
			freq[a[j]]++;
			curr_len++;
			max_len = max(max_len, curr_len);
			j++;
		}
		else
		{
			curr_len--;
			freq[a[i]]--;
			i++;
		}
	}
	cout << max_len;
}