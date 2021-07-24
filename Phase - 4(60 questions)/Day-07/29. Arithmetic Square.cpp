// Link -  https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435a5b/000000000077a3a5
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
	for (int T = 1; T <= t; T++) {
		cout << "Case #" << T << ": ";
		int dp[3][3];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1)
					continue;
				cin >> dp[i][j];
			}
		}
		int cnt = 0;
		if (dp[0][1] - dp[0][0] == dp[0][2] - dp[0][1])
			cnt++;
		if (dp[2][1] - dp[2][0] == dp[2][2] - dp[2][1])
			cnt++;
		if (dp[1][0] - dp[0][0] == dp[2][0] - dp[1][0])
			cnt++;
		if (dp[1][2] - dp[0][2] == dp[2][2] - dp[1][2])
			cnt++;
		map<int, int> mp;
		if ((dp[2][2] - dp[0][0]) % 2 == 0)
			mp[min(dp[2][2], dp[0][0]) + abs(dp[2][2] - dp[0][0]) / 2]++;
		if ((dp[0][2] - dp[2][0]) % 2 == 0)
			mp[min(dp[0][2], dp[2][0]) + abs(dp[0][2] - dp[2][0]) / 2]++;
		if ((dp[0][1] - dp[2][1]) % 2 == 0)
			mp[min(dp[0][1], dp[2][1]) + abs(dp[0][1] - dp[2][1]) / 2]++;
		if ((dp[1][0] - dp[1][2]) % 2 == 0)
			mp[min(dp[1][0], dp[1][2]) + abs(dp[1][0] - dp[1][2]) / 2]++;
		int maxi = 0;
		for (auto a : mp) {
			// cout << a.first << " " << a.second << "n\n";
			maxi = max(a.second, maxi);
		}
		cnt += maxi;
		cout << cnt << "\n";
	}

	return 0;
}