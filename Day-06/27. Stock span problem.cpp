// Link - https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1#
// Author - Shumbul Arifa

// Using stack
class Solution
{
public:
	//Function to calculate the span of stockâ€™s price for all n days.
	vector <int> calculateSpan(int price[], int n)
	{
		// Your code here
		vector<int> ans(n, 1);
		stack<int> st;
		for (int i = 0; i < n; i++) {
			while (!st.empty() && price[st.top()] <= price[i]) {
				ans[i] += ans[st.top()];
				st.pop();
			}
			st.push(i);
		}
		return ans;
	}
};

// BRUTE FORCE - Inefficient
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
	vector<int> price(n);
	vector<int> ans(n), st;
	for0(i, n)	cin >> price[i];
	for0(i, n) {
		if (st.size() == 0) {
			ans[i] = 1;
			st.pb(price[i]);
		}
		else if (st[st.size() - 1] > price[i]) {
			st.pb(price[i]);
			ans[i] = 1;
		}
		else {
			int x = 1;
			for (int j = st.size() - 1; j >= 0 && st[j] <= price[i]; j--) {
				x++;
			}
			ans[i] = x;
			st.pb(price[i]);
		}
	}
	for0(i, n)	cout << ans[i] << " ";

	return 0;
}