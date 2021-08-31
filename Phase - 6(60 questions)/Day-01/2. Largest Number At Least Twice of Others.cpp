// Link - https://leetcode.com/explore/learn/card/array-and-string/201/introduction-to-array/1147/
// Author - Shumbul Arifa

class Solution {
public:
	int dominantIndex(vector<int>& nums) {
		auto it = max_element(nums.begin(), nums.end());
		auto pos = it - nums.begin();
		int largest = *it;
		for (int i = 0; i < nums.size(); i++) {
			if (i != pos && nums[i] * 2 > largest)
				return -1;
		}
		return pos;
	}
};