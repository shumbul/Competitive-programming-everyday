// Link - https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
// Author - Shumbul Arifa

class Solution {
public:
	int specialArray(vector<int>& nums) {
		sort(nums.begin(), nums.end(), greater());
		int l = 0, h = nums.size(), mid;
		while (l < h) { // l!=h because h-> mid
			mid = (h - l) / 2 + l;
			if (mid < nums[mid])
				l = mid + 1;
			else
				h = mid;
		}
		if (l < nums.size() && nums[l] == l)
			return -1;
		return l;
	}
};