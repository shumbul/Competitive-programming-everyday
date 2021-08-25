// Link - https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
// Author - Shumbul Arifa

// METHOD - 1: using upper bound
class Solution {
public:
	int countNegatives(vector<vector<int>>& grid) {
		int ans = 0;
		for (auto row : grid)
			ans += upper_bound(row.rbegin(), row.rend(), -1) - row.rbegin();
		// upper bound -1, meaning the no.s <=-1 are accepted!
		return ans;
	}
};

// METHOD - 2: binary sort
class Solution {
	int negatives(vector<int> r) {
		int res = 0, l = 0, h = r.size() - 1, mid;
		while (l <= h) {
			mid = (h - l) / 2 + l;
			if (r[mid] >= 0)
				l = mid + 1;
			else
				res += h - mid + 1, h = mid - 1;
		}
		return res;
	}
public:
	int countNegatives(vector<vector<int>>& grid) {
		int ans = 0, n = grid.size();
		for (int i = n - 1; i >= 0; i--) {
			ans += negatives(grid[i]);
		}
		return ans;
	}
};