// Link - https://leetcode.com/problems/global-and-local-inversions/
// Author - Shumbul Arifa

class Solution {
public:
	bool isIdealPermutation(vector<int>& nums) {
		if (nums.size() < 2)
			return true;
		// All local inversions are global
		// All global inversions should be local for them to be equal
		// i.e. this case should not be there for any i:
		// A[i]>A[i+k], for k>=2
		// or, should be: A[i-k]<=A[i], for k>=2
		int cmax = 0;
		for (int i = 0; i < nums.size() - 2; i++) {
			cmax = max(cmax, nums[i]);
			if (cmax > nums[i + 2])
				return false;
		}
		return true;
	}
};

// 2
class Solution {
public:
	bool isIdealPermutation(vector<int>& nums) {
		int n = nums.size();
		if (n < 2)
			return true;
		for (int i = 1; i < n; i++)
			if (nums[i] < nums[i - 1])
				swap(nums[i], nums[i - 1]), i++;
		auto b = nums;
		sort(b.begin(), b.end());
		return b == nums;
	}
};