// Link - https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
// Author - Shumbul Arifa

class Solution {
	string ans = "";
	vector<string> res;
	void solve(int n, int k, string s) {
		if (res.size() == k) {
			return;
		}
		if (s.size() == n) {
			res.push_back(s);
			return;
		}
		for (char ch : {'a', 'b', 'c'}) {
			int a = s.size();
			if (!a || s[a - 1] != ch)
				solve(n, k, s + ch);
		}
	}
public:
	string getHappyString(int n, int k) {
		solve(n, k, "");
		if (res.size() == k)
			ans = res[k - 1];
		return ans;
	}
};