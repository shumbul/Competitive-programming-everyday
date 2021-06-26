// Link - https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
// Author - Shumbul Arifa

class Solution {
	// a rec func
	int solve(string s, int place, unordered_set<string> st, string tmp) {
		if (place == s.size())
			return 0;
		tmp += s[place];
		int op1, op2;
		op1 = op2 = 0;
		if (st.find(tmp) == st.end()) {
			st.insert(tmp);
			op1 = 1 + solve(s, place + 1, st, ""); // tried including temp
			st.erase(tmp);  // backtracking
		}
		op2 = solve(s, 1 + place, st, tmp); //  a char is added to tmp, and function is called recursively
		return max(op1, op2);
	}
public:
	int maxUniqueSplit(string s) {
		unordered_set<string> st;
		return solve(s, 0, st, "");
	}
};