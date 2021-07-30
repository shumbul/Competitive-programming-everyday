// Link - https://leetcode.com/problems/next-greater-element-i/
// Author - Shumbul Arifa

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		stack<int> st;
		int n = nums2.size();
		map<int, int> mp;
		for (int i = n - 1; i >= 0; i--) {
			if (st.empty()) {
				st.push(nums2[i]);
				mp[nums2[i]] = -1;
			}
			else if (st.top() > nums2[i]) {
				mp[nums2[i]] = st.top();
				st.push(nums2[i]);
			}
			else {
				while (!st.empty() && st.top() <= nums2[i]) {
					st.pop();
				}
				if (st.empty())
					mp[nums2[i]] = -1;
				else
					mp[nums2[i]] = st.top();
				st.push(nums2[i]);
			}
		}
		vector<int> ans;
		for (int i : nums1) {
			ans.push_back(mp[i]);
		}
		return ans;
	}
};