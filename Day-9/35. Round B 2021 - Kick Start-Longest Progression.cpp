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

int solve(vector<pair<int, int>> &ch) {
	int ans = 0, l = ch.size(), i = 0, j, m;

	while (i < l) {
		m = ch[i].ss;
		ans = max(ans, m);
		j = i + 1;
		if (j < l) {
			// case 1 definitely holds
			ans = max(ans, m + 1);
		}
		if (j + 1 < l && ch[j].ss == 1) {
			if (ch[i].ff * 2 == ch[j].ff + ch[j + 1].ff) {
				// case 2 holds
				ans = max(ans, m + 2);
				if (j + 2 < l && ch[j + 2].ff == ch[i].ff && ch[j + 1].ss == 1) {
					// case 3 holds
					ans = max(ans, m + ch[j + 2].ss + 2);
				}
			}
		}
		i++;
	}

	return ans + 1;	// "+1" for actual length in ar
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;	cin >> t;
	for (int T = 1; T <= t; T++) {
		cout << "Case #" << T << ": ";

		int n;	cin >> n;

		vi ar(n);
		vi d(n - 1);
		for0(i, n) {
			cin >> ar[i];
			if (i > 0) {
				d[i - 1] = (ar[i] - ar[i - 1]);
			}
		}

		vector<pair<int, int>> ch;	// chunk
		// 2 pointer
		int i = 0, j;
		while (i < n - 1) {
			j = i + 1;
			while (d[j] == d[i] && j < n - 1) {
				j++;
			}
			auto p = make_pair(d[i], j - i);
			ch.pb(p);
			i = j;
		}
		// for (auto a : ch) {
		// 	cout << a.ff << " " << a.ss << "\n";
		// }
		int f1 = solve(ch);
		reverse(ch.begin(), ch.end());
		// for (auto a : ch) {
		// 	cout << a.ff << " " << a.ss << "\n";
		// }
		int f2 = solve(ch);
		cout << max(f1, f2);

		cout << "\n";
	}

	return 0;
}