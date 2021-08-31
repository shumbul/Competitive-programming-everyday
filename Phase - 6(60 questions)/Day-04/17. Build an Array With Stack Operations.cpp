// Link - https://leetcode.com/problems/build-an-array-with-stack-operations/
// Author - Shumbul Arifa

class Solution {
public:
	vector<string> buildArray(vector<int>& target, int n) {
		int k = 0;
		vector<string> ans;
		for (int i = 1; i <= n; i++) {
			if (k >= target.size())
				break;
			if (i < target[k]) {
				ans.push_back("Push"), ans.push_back("Pop");
			}
			else
				ans.push_back("Push"), k++;
		}
		return ans;
	}
};