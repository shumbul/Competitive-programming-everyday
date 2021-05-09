// Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3318/
// Author - Shumbul Arifa

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		map<char, int> mp;
		for (char c : magazine) {
			mp[c]++;
		}
		for (char c : ransomNote) {
			if (mp.find(c) == mp.end()) {
				return false;
			}
			mp[c]--;
			if (mp[c] == 0)
				mp.erase(c);
		}
		return true;
	}
};