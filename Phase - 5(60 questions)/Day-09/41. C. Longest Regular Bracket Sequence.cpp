// Link - https://codeforces.com/problemset/problem/5/C
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

int E[1000001], F[1000001];

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;	cin >> s;
	stack<int> st;
	int mxindex = 0;
	for (unsigned int i = 0; i < s.length(); i++) {
		char ch = s[i];
		if (ch == '(')
			st.push(i);
		else {
			if (st.empty())
				E[i] = -1;
			else {
				int idx = st.top();
				st.pop();
				E[i] = idx;
				if (idx > 0 && s[idx - 1] == ')' && E[idx - 1] > -1)
					E[i] = E[idx - 1];	// extended.
				int l = i - E[i] + 1;
				F[l]++;
				mxindex = max(mxindex, l);
			}
		}
	}
	F[0] = 1;
	cout << mxindex << " " << F[mxindex];

	return 0;
}