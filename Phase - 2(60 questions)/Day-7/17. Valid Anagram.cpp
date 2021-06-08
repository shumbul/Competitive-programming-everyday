// Link - https://leetcode.com/problems/valid-anagram/submissions/
// Author - Shumbul Arifa

class Solution {
public:
	bool isAnagram(string s, string t) {
		string sk = s, tk = t;
		sort(sk.begin(), sk.end());
		sort(tk.begin(), tk.end());
		if (sk == tk)
			return true;
		return false;
	}
};