// Link - https://codedrills.io/problems/all-valid-balanced-parenthesis
// Author - Shumbul Arifa

#include<string>
#include<bits/stdc++.h>
using namespace std;

class AllValidBalancedParenthesis {
	vector<string> ans;
	void solve(int n, string s, int ev, int od) {
		// base case
		if ((int)s.length() == 2 * n)
		{
			ans.push_back(s);
			return;
		}
		// heart of rec
		if (ev < n)
			solve(n, s + "(", ev + 1, od);
		if (ev != od)
			solve(n, s + ")", ev, od + 1);
	}
public:
	std::vector<std::string> getAll(int n) {
		// Code here
		ans.clear();
		solve(n, "(", 1, 0);
		return ans;
	}
};


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;	cin >> t;
	int T = 0;
	while (t--) {
		cout << "Test " << ++T << ":\n";
		AllValidBalancedParenthesis A;
		unsigned int n;	cin >> n;
		auto v = A.getAll(n);
		for (auto a : v) {
			cout << a << " ";
		}
		cout << "\n";
	}

}