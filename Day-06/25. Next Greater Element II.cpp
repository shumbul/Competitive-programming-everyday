// Link - https://leetcode.com/problems/next-greater-element-ii/
// Author - Shumbul Arifa

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		if (nums.size() == 0)
			return nums;
		int m = *max_element(nums.begin(), nums.end());
		stack<int> st;
		int n = nums.size();
		vector<int> ans(n);
		for (int i = 2 * n - 1; i >= 0; i--) {
			if (st.empty()) {
				st.push(nums[i % n]);
				ans[i % n] = -1;
			}
			else if (st.top() > nums[i % n]) {
				ans[i % n] = st.top();
				st.push(nums[i % n]);
			}
			else {
				while (!st.empty() && st.top() <= nums[i % n]) {
					st.pop();
				}
				if (st.empty())
					ans[i % n] = -1;
				else
					ans[i % n] = st.top();
				st.push(nums[i % n]);
			}
		}
		return ans;
	}
};