// Link - https://codeforces.com/contest/1509/problem/C
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

vi s;
int mem[2001][2001];
int dp(int l, int h) {
	if (l == h)
		return 0;
	if (mem[l][h] != -1)
		return mem[l][h];
	if (l == h - 1)
		mem[l][h] = s[h] - s[l];
	else
		mem[l][h] = s[h] - s[l] + min(dp(l + 1, h), dp(l, h - 1));
	// cout << "\n## " << l << h << " " << mem[l][h];
	return mem[l][h];
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;	cin >> n;
	s.resize(n);
	for0(i, n)
	cin >> s[i];
	sort(all(s));
	memset(mem, -1, sizeof mem);
	cout << dp(0, n - 1);
	return 0;
}