// Link - https://cses.fi/problemset/task/1070
// Author - Shumbul Arifa

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pb push_back
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;	cin >> n;
	if (n == 2 || n == 3)
		cout << "NO SOLUTION";
	else if (n == 4)
		cout << "3 1 4 2";
	else {
		vector<int> v(n, 0);
		int k = 1;
		for (int i = 0; i < n; i += 2)
			v[i] = k++;
		for (int j = 1; j < n; j += 2)
			v[j] = k++;
		for (int i : v)
			cout << i << " ";
	}


	return 0;
}