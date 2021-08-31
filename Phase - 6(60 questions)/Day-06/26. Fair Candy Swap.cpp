// Link - https://leetcode.com/problems/fair-candy-swap/
// Author - Shumbul Arifa

// using set
class Solution {
public:
	vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
		set<int> b;
		int s1, s2;
		s1 = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
		s2 = accumulate(bobSizes.begin(), bobSizes.end(), 0);
		for (int i : bobSizes)
			b.insert(i);
		vector<int> ans;
		for (int i : aliceSizes) {
			if (b.find((s2 - s1) / 2 + i) != b.end()) {
				ans.push_back(i), ans.push_back(i + (s2 - s1) / 2);
				return ans;
			}
		}
		return ans;
	}
};