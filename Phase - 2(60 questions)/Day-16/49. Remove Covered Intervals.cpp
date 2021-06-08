// Link - https://leetcode.com/problems/remove-covered-intervals/
// Author - Shumbul Arifa

class Solution {
public:
	int removeCoveredIntervals(vector<vector<int>>& intervals) {
		int removed = 0;
		sort(intervals.begin(), intervals.end(), [](const auto & s1, const auto & s2) {
			if (s1[0] != s2[0])
				return s1[0] <= s2[0];
			return s1[1] >= s2[1];
		});
		int last = -1;
		for (auto interval : intervals) {
			if (interval[1] <= last)
				removed ++;
			else
				last = interval[1];
		}
		return intervals.size() - removed;
	}
};