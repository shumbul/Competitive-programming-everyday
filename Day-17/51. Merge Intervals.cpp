// Link - https://leetcode.com/problems/merge-intervals/
// Author - Shumbul Arifa

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> ans;
		sort(intervals.begin(), intervals.end());
		if (intervals.size() < 2)
			return intervals;
		vector<int> v(2);
		v[0] = intervals[0][0], v[1] = intervals[0][1];
		for (auto interval : intervals) {
			if (v[1] >= interval[0]) {
				v[1] = max(v[1], interval[1]);
				continue;
			}
			ans.push_back(v);
			v[0] = interval[0];
			v[1] = interval[1];
		}
		ans.push_back(v);
		return ans;
	}
};

/* ALSO VALID */

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> ans;
		sort(intervals.begin(), intervals.end());
		if (intervals.size() < 2)
			return intervals;
		vector<int> v(2);
		v[0] = intervals[0][0], v[1] = intervals[0][1];
		for (auto interval : intervals) {
			if (v[1] < interval[0]) {
				ans.push_back(v);
				v[0] = interval[0];
				v[1] = interval[1];
			}
			else
				v[1] = max(v[1], interval[1]);
		}
		ans.push_back(v);
		return ans;
	}
};