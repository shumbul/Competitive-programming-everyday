// Link - https://leetcode.com/contest/weekly-contest-246/problems/largest-odd-number-in-string/
// Author - Shumbul Arifa

class Solution {
public:
	string largestOddNumber(string num) {
		string ans = "";
		for (int i = num.length() - 1; i >= 0; i--) {
			if ((num[i] - '0') % 2) {
				ans = num.substr(0, i + 1);
				break;
			}
		}
		return ans;
	}
};