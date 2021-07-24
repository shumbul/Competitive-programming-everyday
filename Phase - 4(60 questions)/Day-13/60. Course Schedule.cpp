// Link - https://cses.fi/problemset/task/1679
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

vector<int> adj[200003];
bool vis[200003], act[200003];
vector<int> ans;

void dfs(int u) {
	vis[u] = 1;
	act[u] = 1;
	for (auto v : adj[u]) {
		if (act[v]) {
			cout << "IMPOSSIBLE";
			exit(0);
		}
		if (!vis[v]) {
			dfs(v);
		}
	}
	act[u] = 0;
	ans.pb(u);
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;	cin >> n >> m;
	for0(i, m) {
		int a, b;	cin >> a >> b;
		adj[a].pb(b);
	}
	for1(i, n) {
		if (!vis[i])
			dfs(i);
	}

	reverse(ans.begin(), ans.end());
	for (auto u : ans) {
		cout << u << " ";
	}
	return 0;
}