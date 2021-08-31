// Link - https://leetcode.com/problems/intersection-of-two-arrays/
// Author - Shumbul Arifa

// METHOD - 1: using set
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> st, tmp;
		vector<int> ans;
		for (int i : nums1)
			st.insert(i);
		for (int i : nums2)
			if (st.find(i) != st.end())
				tmp.insert(i);
		for (auto a : tmp)
			ans.push_back(a);
		return ans;
	}
};

// METHOD - 2: using binary search
class Solution {
	int bin_search(vector<int> n, int k) {
		int l = 0, h = n.size() - 1, mid;
		while (l <= h) {
			mid = (h - l) / 2 + l;
			if (n[mid] == k)
				return mid;
			if (n[mid] > k)
				h = mid - 1;
			else l = mid + 1;
		}
		// cout<<"returning -1 on "<<k<<"\n";
		return -1;
	}
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size())
			return intersection(nums2, nums1);
		// assuming nums1 is always smaller or equal in size than nums2
		auto n1 = nums1, n2 = nums2;
		sort(n1.begin(), n1.end());
		sort(n2.begin(), n2.end());
		set<int> st;
		vector<int> ans;
		for (int i : n1) {
			if (st.find(i) != st.end())
				continue;
			int b = bin_search(n2, i);
			if (b != -1)
				st.insert(i);
		}
		for (int i : st)
			ans.push_back(i);
		return ans;
	}
};