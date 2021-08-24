// Link - https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
// Author - Shumbul Arifa

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