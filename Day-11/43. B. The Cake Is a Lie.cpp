// Link - https://codeforces.com/contest/1519/problem/B
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

vector < vector<pair<int, int>>> costs(101, vector<pair<int, int>>(101));
// contains shortest and the longest path lengths

void fill() {
	int n = 100;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			costs[i][j].ff = INT_MAX;
		}
	}
	costs[1][1].ff = costs[1][1].ss = 0;
	for (int i = 2; i <= n; i++) {
		costs[i][1].ss = costs[i][1].ff = 1 + costs[i - 1][1].ff;
	}
	for (int i = 2; i <= n; i++) {
		costs[1][i].ss = costs[1][i].ff = 1 + costs[1][i - 1].ff;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			costs[i][j].ff = min(costs[i - 1][j].ff + j, costs[i][j - 1].ff + i);
			costs[i][j].ss = max(costs[i - 1][j].ss + j, costs[i][j - 1].ss + i);
		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++) {
	// 		cout << i << " " << j << "->" << costs[i][j].ff << " " << costs[i][j].ss << "\n";
	// 	}
	// }
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	fill();
	int t;	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (costs[a][b].ff <= c && costs[a][b].ss >= c) {
			cout << "Yes\n";
		}
		else cout << "No\n";
	}

	return 0;
}