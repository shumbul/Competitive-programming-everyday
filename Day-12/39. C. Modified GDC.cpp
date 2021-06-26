// Link - https://codeforces.com/problemset/problem/75/C
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

void fill(int g, vi & facts) {
	for (int i = 1; i * i <= g; i++) {
		if (g % i == 0) {
			facts.pb(i);
			if (i * i != g)
				facts.pb(g / i);
		}
	}
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int l, r;
	cin >> l >> r;
	int g = gcd(l, r);
	vector<int> facts;	// to store factors of g
	fill(g, facts);
	int q;	cin >> q;
	map<vector<int>, int> mp;
	while (q--) {
		int a, b;
		cin >> a >> b;
		// if a and b are same
		if (a == b) {
			if (l % a == 0 && r % a == 0) {
				cout << a << "\n";
				mp[ {a, b}] = a;
			}
			else {
				cout << "-1\n";
				mp[ {a, b}] = -1;
			}
			continue;
		}
		// if the answer is already stored
		if (mp.find({a, b}) != mp.end()) {
			cout << mp[ {a, b}] << "\n";
			continue;
		}
		int ans = -1;
		for (int i = facts.size() - 1; i >= 0; i--) {
			if (facts[i] >= a && facts[i] <= b) {
				ans = max(facts[i], ans);
			}
		}
		cout << ans << "\n";
		mp[ {a, b}] = ans;
	}
	return 0;
}