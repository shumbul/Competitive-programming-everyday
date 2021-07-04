// Link - https://leetcode.com/problems/counting-bits/
// Author - Shumbul Arifa

class Solution {
	int countOnes (int n)
	{
		int count = 0;
		while (n != 0)
		{
			n = n & (n - 1);
			count++;
		}
		return count;
	}
public:
	vector<int> countBits(int n) {
		vector<int> ans(n + 1, 0);
		for (int i = 0; i <= n; i++) {
			ans[i] = countOnes(i);
		}
		return ans;
	}
};