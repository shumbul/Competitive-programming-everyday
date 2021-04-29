// Link - https://codeforces.com/contest/1511/problem/B
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

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;	cin >> t;
	while (t--) {
		int a1, a2, len;
		cin >> a1 >> a2 >> len;
// 		// brute force give TLE
// 		int g1 = pow(10, a1 - 1);
// 		int g2 = pow(10, a2 - 1);
// 		string s;
// 		for (int i = g2; i < pow(10, a2); i++) {
// 			for (int j = g1; j < pow(10, a1); j++) {
// 				s = to_string(gcd(i, j));
// 				if (s.length() == len) {
// 					g1 = j, g2 = i;
// 					goto print;
// 				}
// 			}
// 		}
// print:
// 		cout << g1 << " " << g2 << "\n";
		int a = 2, b = 3;
		len = pow(10, len - 1);
		a = a * len;
		string s = to_string(a);
		while (s.length() < a1) {
			a *= 2;
			s = to_string(a);
		}
		b = b * len;
		s = to_string(b);
		while (s.length() < a2) {
			b *= 3;
			s = to_string(b);
		}
		cout << a << " " << b << "\n";
	}



	return 0;
}