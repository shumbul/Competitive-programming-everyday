// Link - https://codedrills.io/problems/all-permutations
// Author - Shumbul Arifa

#include<bits/stdc++.h>
using namespace std;

class AllPermutations {
	vector<vector<int>> ans;
	void solve(unsigned int n, vector<int> s1, vector<int> s2) {
		// for (int a : s1)
		// 	cout << a << " ";
		// cout << " and" ;
		// for (int a : s2)
		// 	cout << a << " ";
		// cout << "\n";
		if (s1.size() == n) {
			ans.push_back(s1);
			return;
		}
		for (unsigned int i = 0; i < s2.size(); i++) {
			// cout << s2[i] << " yo \n";
			int val = s2[i];
			// cout << val << " -> val\n";
			s1.push_back(val);
			s2.erase(s2.begin() + i);
			solve(n, s1, s2);
			if (s1.size() < n) {
				s2.insert(s2.begin() + i, val);
				s1.pop_back();
			}
		}
	}

public:
	std::vector<std::vector<int>> getAll(int n) {
		// Code here
		ans.clear();
		vector<int> v;
		for (int i = 1; i <= n; i++)
			v.push_back(i);
		solve(n, {}, v);
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
		AllPermutations A;
		unsigned int n;	cin >> n;
		auto v = A.getAll(n);
		for (auto a : v) {
			for (auto b : a)
				cout << b << " ";
			cout << "\n";
		}
	}

}