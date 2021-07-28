// Link - https://leetcode.com/problems/course-schedule-ii/
// Author - Shumbul Arifa

// M-1: DFS
#define pb push_back
class Solution {
	vector<int> ar[10001];
	int vis[10001];
	bool imp;
	stack<int> st;
	set<int> done;
	vector<int> ans;
	void dfs(int i) {
		if (imp)
			return;
		vis[i] = 1;
		for (auto a : ar[i]) {
			if (vis[a] == 0)
				dfs(a);
			if (vis[a] == 1) {
				imp = 1;
				return;
			}
		}
		if (done.find(i) == done.end())
			st.push(i), done.insert(i);
		vis[i] = 2;
	}
public:
	vector<int> findOrder(int n, vector<vector<int>>& pres) {
		ans.clear();
		done.clear();
		imp = 0;
		// make a graph
		for (auto a : pres) {
			ar[a[1]].pb(a[0]);
		}
		for (int i = 0; i < n; i++) {
			if (!vis[i])
				dfs(i);
		}
		if (imp)
			return {};
		while (!st.empty())
			ans.pb(st.top()), st.pop();
		if (ans.size() < n) {
			for (int i = 0; i < n; i++) {
				if (done.find(i) == done.end())
					ans.pb(i);
			}
		}


		return ans.size() < n ? vector<int> {}: ans;
	}
};

// M-2: Topological sort
#define pb push_back
class Solution {
	vector<int> ar[10001];
	vector<int> in;
public:
	vector<int> findOrder(int n, vector<vector<int>>& pres) {
		// topo sort
		for (int i = 0; i < n; i++) {
			ar[i].clear();
		}
		in.clear();
		in.resize(n, 0);
		vector<int> res;
		for (auto p : pres) {
			ar[p[1]].pb(p[0]);
			++in[p[0]];
		}
		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (in[i] == 0)
				q.push(i);
		}
		cout << q.size() << "\n";
		while (!q.empty()) {
			int a = q.front();
			q.pop();
			res.pb(a);
			for (auto b : ar[a]) {
				--in[b];
				if (in[b] == 0)
					q.push(b);
			}
		}
		for (int i : res)
			cout << i << " ";
		cout << "\n\n";
		return res.size() == n ? res : vector<int> {};
	}
};