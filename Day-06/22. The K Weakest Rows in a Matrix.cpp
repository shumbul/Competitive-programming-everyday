// Link - https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
// Author - Shumbul Arifa

// METHOD - 1: using priority queue
class Solution {
	int strength(vector<int> r) {
		int i = 0;
		while (i < r.size() && r[i])
			i++;
		return i;
	}
public:
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		int i = 0;
		for (auto r : mat)
			pq.push({strength(r), i++});
		vector<int> ans;
		while (!pq.empty() && k--)
			ans.push_back(pq.top().second), pq.pop();
		return ans;
	}
};

// METHOD - 2: binary search
class Solution {
public:
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		int n = mat.size(), m = mat[0].size(), l, h, mid;
		vector<int> ans, oneidx(n, 0);
		for (int i = 0; i < n; i++) {
			l = 0, h = m;
			while (l < h) {
				mid = (h - l) / 2 + l;
				if (mat[i][mid] == 0)
					h = mid;
				else
					l = mid + 1;
			}
			oneidx[i] = l;
		}
		map<int, vector<int>> strength;
		for (int i = 0; i < n; i++)
			strength[oneidx[i]].push_back(i);
		int cnt = 0;
		for (auto a : strength) {
			// cout<<a.first<<"->";
			auto tmp = a.second;
			for (int i : tmp) {
				ans.push_back(i);
				cnt++;
				if (cnt == k)
					break;
			}
			if (cnt == k)
				break;
		}
		return ans;
	}
};