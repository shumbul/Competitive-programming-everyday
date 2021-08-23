// Link - https://leetcode.com/problems/remove-outermost-parentheses/
// Author - Shumbul Arifa

class Solution {
public:
	string removeOuterParentheses(string s) {
		string ans;
		stack<int> st;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				if (st.empty())
					st.push(1);
				else
					st.push(st.top() + 1), ans += s[i];
			}
			else if (s[i] == ')') {
				if (st.top() != 1) {
					st.pop(), ans += ')';
				}
				else {
					st.pop();
				}
			}
		}
		return ans;
	}
};