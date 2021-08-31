// Link - https://leetcode.com/problems/intersection-of-two-arrays-ii/
// Author - Shumbul Arifa

// METHOD - 1: using map and multiset
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		map<int, int> st;
		multiset<int> tmp;
		vector<int> ans;
		for (int i : nums1)
			st[i]++;
		for (int i : nums2)
			if (st.find(i) != st.end()) {
				tmp.insert(i);
				st[i]--;
				if (st[i] == 0)
					st.erase(i);
			}
		for (auto a : tmp)
			ans.push_back(a);
		return ans;
	}
};