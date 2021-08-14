// Link - https://www.geeksforgeeks.org/count-all-prime-numbers-that-can-be-formed-using-digits-of-a-given-number/
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
vector<bool> prime;
unordered_set<string> primes;
unordered_set<string> ans;

void sieve() {
	prime.resize(100001, 1);
	int n = sizeof(prime) - 1;
	for (int p = 2; p * p <= n ; p++) {
		if (prime[p] == true) {
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
	for (int p = 2; p <= n; p++)
		if (prime[p])
			primes.insert(to_string(p));
}

void dfs(unordered_map<char, int> count, string s) {
	// cout << s << "\n";
	if (primes.find(s) != primes.end()) {
		// cout << "killa\n";
		ans.insert(s);
	}
	for (auto a : count) {
		if (a.second == 0)
			continue;
		count[a.first]--;
		dfs(count, s + a.first);
		count[a.first]++;
	}
}

void solve() {
	string s;	cin >> s;
	ans.clear();
	unordered_map<char, int> count;
	for (char c : s)
		count[c]++;
	dfs(count, "");
	cout << ans.size() << "\n";
	for (string a : ans)
		cout << a << " ";
	cout << "\n";
}

signed main() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;	cin >> t;
	sieve();
	while (t--)	solve();

	return 0;
}