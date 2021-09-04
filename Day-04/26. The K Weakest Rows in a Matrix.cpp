// Link - https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
// Author - Shumbul Arifa

class Solution {
public:
	vector<int> kWeakestRows(vector<vector<int>> mat, int K) {
		vector<pair<int, int>> v;
		int c = 0, k = 0;
		for (auto a : mat) {
			c = 0;
			for (int i = 0; i < a.size() && a[i]; i++) {
				c++;
			}
			v.push_back({c, k++});
		}
		vector<int> ans;
		sort(v.begin(), v.end());
		k = 0;
		while (K--) {
			ans.push_back(v[k++].second);
		}
		return ans;
	}
};