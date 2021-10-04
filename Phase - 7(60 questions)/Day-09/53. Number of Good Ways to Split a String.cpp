// Link - https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
// Author - Shumbul Arifa

class Solution {
public:
	int numSplits(string s) {
		// using maps
		map<char, int> m1, m2;
		if (s.size() < 2)
			return 0;
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) m2[s[i]]++;
		for (int i = 0; i < s.size(); i++) {
			m2[s[i]]--;
			if (m2[s[i]] == 0)
				m2.erase(s[i]);
			m1[s[i]]++;
			if (m1.size() == m2.size())
				cnt++;
		}
		return cnt;
	}
};