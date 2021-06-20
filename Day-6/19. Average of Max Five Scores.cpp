// Link - https://codedrills.io/problems/average-of-max-five-scores
// Author - Shumbul Arifa

#include<bits/stdc++.h>
using namespace std;

class AverageMaxFive {
	vector<vector<int>> ans;
	map<int, priority_queue<int, vector<int>, greater<int>>> mp;
	void solve(vector<vector<int>> a) {
		for (auto p : a) {
			if (mp.find(p[0]) == mp.end() || mp[p[0]].size() < 5)
				mp[p[0]].push(p[1]);
			else if (mp[p[0]].size() == 5 && mp[p[0]].top() < p[1]) {
				mp[p[0]].pop();
				mp[p[0]].push(p[1]);
			}
		}
		for (auto p : mp) {
			int avg = 0;
			while (!p.second.empty()) {
				avg += p.second.top(), p.second.pop();
			}
			vector<int> v;
			v.push_back(p.first);
			v.push_back(avg / 5);
			ans.push_back(v);
		}
	}
public:
	std::vector<std::vector<int>> getAverage(std::vector<std::vector<int>> a) {
		// Code here
		ans.clear();
		solve(a);
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
		AverageMaxFive A;
		// unsigned int n;	cin >> n;
		vector < vector<int>> n = {{1, 3}, {2, 4}, {1, 5}, {2, 1}, {1, 7}, {1, 5}, {1, 3}, {2, 3}, {2, 10}, {1, 2}, {2, 9}};
		auto v = A.getAverage(n);
		for (auto a : v) {
			for (auto b : a)
				cout << b << " ";
			cout << "\n";
		}
		cout << "\n";
	}

}