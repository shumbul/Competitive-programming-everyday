// Link - https://leetcode.com/problems/pascals-triangle-ii/
// Author - Shumbul Arifa

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<vector<int>> ans(rowIndex + 1);
		ans[0] = {1};
		for (int i = 1; i <= rowIndex; i++) {
			int prevs = ans[i - 1].size();
			vector<int> v(prevs + 1);
			v[0] = v[prevs] = 1;
			for (int j = 0; j < prevs - 1; j++) {
				v[j + 1] = ans[i - 1][j] + ans[i - 1][j + 1];
			}
			ans[i] = v;
		}
		return ans[rowIndex];
	}
};