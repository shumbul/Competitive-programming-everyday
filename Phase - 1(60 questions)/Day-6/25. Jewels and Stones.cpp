// Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3317/
// Author - Shumbul Arifa

class Solution {
public:
	int numJewelsInStones(string jewels, string stones) {
		int ans = 0;
		for (char c : stones) {
			if (jewels.find(c) != jewels.npos)
				ans++;
		}
		return ans;
	}
};