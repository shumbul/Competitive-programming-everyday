// Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3320/
// Author - Shumbul Arifa

class Solution {
public:
	int firstUniqChar(string s) {
		string t = s, saw = "";
		for (int i = 0; i < s.length(); i++) {
			t.erase(t.begin());
			char c = s[i];
			if (t.find(c) == t.npos && saw.find(c) == saw.npos)
				return i;
			saw += c;
		}
		return -1;
	}
};