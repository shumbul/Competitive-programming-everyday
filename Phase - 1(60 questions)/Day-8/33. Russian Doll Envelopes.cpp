// Link - https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/dynamic-programming/russian-doll-envelopes-official/ojquestion
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

	// SORT WIDTH, APPLY lis ON HEIGHT
	int n;	cin >> n;
	if (n < 2) {
		cout << n;
		return 0;
	}
	vector<pair<int, int>> ar;
	for0(i, n) {
		int a, b;
		cin >> a >> b;
		ar.pb(make_pair(a, b));
	}
	sort(ar.begin(), ar.end(), [](const auto & s1, const auto & s2) {
		if (s1.ss == s2.ss) {
			return s1.ff < s2.ff;
		}
		return s1.ss < s2.ss;
	});

	// LIS in ar.ss :-
	vector<int> sec;
	for0(i, ar.size()) {
		sec.pb(ar[i].ss);
	}
	int lis[n];
	memset(lis, 0, sizeof lis);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (ar[i] > ar[j]) {
				lis[i] = max(lis[i], 1 + lis[j]);
			}
		}
	}
	cout << *max_element(lis, lis + n) + 1 << "\n";

	return 0;
}