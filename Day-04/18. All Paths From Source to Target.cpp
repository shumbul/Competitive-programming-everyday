// Link - https://leetcode.com/problems/all-paths-from-source-to-target/
// Author - Shumbul Arifa

#define pb push_back
class Solution {
	vector<int> ar[10001];
	vector<vector<int>> ans;
	void dfs(int i, vector<int> &res, int n, set<int> &st) {
		if (i == n - 1) {
			ans.pb(res);
			return;
		}
		for (int a : ar[i]) {
			if (st.find(a) == st.end()) {
				res.pb(a);
				st.insert(a);
				dfs(a, res, n, st);
				res.pop_back();
				st.erase(a);
			}
		}
	}
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		int n = graph.size();
		for (int i = 0; i < n; i++) {
			for (int b : graph[i])
				ar[i].pb(b);
		}
		vector<int> res;
		set<int> st;
		st.insert(0);
		res.pb(0);
		dfs(0, res, n, st);
		return ans;
	}
};