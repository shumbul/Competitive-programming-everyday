// Link - https://leetcode.com/problems/string-to-integer-atoi/
// Author - Shumbul Arifa

class Solution {
public:
	int myAtoi(string s) {
		if (s == "")
			return 0;
		int i = 0, sign = 1, base = 0;
		while (i < s.length() && s[i] == ' ') i++;
		if (i == s.length())
			return 0;
		if (s[i] == '-' || s[i] == '+') {
			if (s[i] == '-')
				sign = -1;
			i++;
		}
		if (i == s.length()) {
			return 0;
		}
		while (s[i] >= '0' && s[i] <= '9') {
			if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && s[i] - '0' > 7)) {
				if (sign == 1) return INT_MAX;
				else return INT_MIN;
			}
			base  = 10 * base + (s[i++] - '0');
		}
		return base * sign;
	}
};