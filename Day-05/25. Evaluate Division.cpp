// Link - https://leetcode.com/problems/evaluate-division/
// Author - Shumbul Arifa

// Video explaination: https://www.youtube.com/watch?v=P9cPgMp6Wc8
// thanks to Lead Coding for a great explaination
class Solution {
	void dfs(string s, string d,
	         unordered_map<string, vector<pair<string, double>> > weight, set<string> vis, double &ans, double temp) {
		if (vis.find(s) != vis.end()) {
			// source is not already visited
			return;
		}
		vis.insert(s);
		if (s == d) {
			ans = temp;
			return;
		}
		for (auto a : weight[s]) {
			dfs(a.first, d, weight, vis, ans, temp * a.second);
		}
	}
public:
	vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& vals, vector<vector<string>>& queries) {
		unordered_map<string, vector<pair<string, double>> > weight;
		// bidirectional weighted graph
		for (int i = 0; i < eq.size(); i++) {
			weight[eq[i][0]].push_back(make_pair(eq[i][1], vals[i]));
			weight[eq[i][1]].push_back(make_pair(eq[i][0], 1 / vals[i]));
		}
		vector<double> res;
		for (auto a : queries) {
			double ans = -1.0;
			set<string> vis;
			if (weight.find(a[0]) != weight.end())
				dfs(a[0], a[1], weight, vis, ans, 1.0);
			res.push_back(ans);
		}
		return res;
	}
};