// Link - https://codeforces.com/contest/1511/problem/D
// Author - Shumbul Arifa

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define inar(arr,n) for(int i=0; i<n; i++) cin>>arr[i];
#define suma(arr,n) for(int i=0; i<n; i++) sum+=arr[i];
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define forr(i,n) for(int i=n-1; i>=0; i--)
#define rof(i,a,b) for(int i=a;i<=b;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) cout<<v<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;
ll gcd (ll a, ll b) {return ( a ? gcd(b % a, a) : b );}
ll power(ll a, ll n) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

vi adj[26];
string ans;
vector<bool> vis(26, false);

void dfs(int x, int &n) {
	if (n == 0)	return;
	vis[x] = 1;
	for (int u : adj[x]) {
		if (n == 0)	return;
		char ch = 'a' + u;
		ans += ch;
		n--;
		if (n == 0)	return;
		if (!vis[u])
			dfs(u, n);
		if (x == u)
			continue;
		if (n == 0)	return;
		ch = 'a' + x;
		ans += ch;
		n--;
		if (n == 0)	return;

	}
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// graphs solution
	int n, k;	cin >> n >> k;

	if (n == 1) {
		cout << "a";
		return 0;
	}
	int len = n;
	for (int i = 0; i < k; i++) {
		for (int j = i; j < k; j++) {
			adj[i].pb(j);
		}
	}
	ans += "a";
	n--;
	dfs(0, n);
	string res = "";
	while (res.length() < len)
		res += ans.substr(1);
	cout << res.substr(0, len);

	return 0;
}