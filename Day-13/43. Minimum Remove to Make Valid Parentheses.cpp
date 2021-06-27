// Link - https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// Author - Shumbul Arifa

class Solution {
public:
	string minRemoveToMakeValid(string s) {
		// trial -1, using stack
		stack<int> st;
		unordered_set<int> inx;    // indices to remove
		int i;
		for (i = 0; i < s.length(); i++) {
			char c = s[i];
			if (c == '(') {
				st.push(i);
			}
			else if (c == ')') {
				if (!st.empty())
					st.pop();
				else {
					inx.insert(i);
				}
			}
		}
		while (!st.empty()) {
			inx.insert(st.top());
			st.pop();
		}
		string t = s;
		for (i = 0; i < s.length(); i++)
			if (inx.find(i) == inx.end())
				t += s[i];
		return t;
	}
};