// Link - https://leetcode.com/problems/counting-bits/
// Author - Shumbul Arifa

class Solution {
public:
	vector<int> countBits(int n) {
		vector<int> ans(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			ans[i] = ans[i >> 1] + (i & 1);
		}
		return ans;
	}
};

// odd and even logic
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> res(num);
		res.push_back(0);  // for num=0
		if (num == 0) return res;

		for (int i = 1; i <= num; i++) {
			if (i % 2 == 0) {
				res[i] = res[i / 2];
			} else {
				res[i] = res[i - 1] + 1;
			}
		}
		return res;
	}
};