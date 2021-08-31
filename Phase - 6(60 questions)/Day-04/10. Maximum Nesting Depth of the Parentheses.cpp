// Link - https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
// Author - Shumbul Arifa

class Solution {
public:
	int maxDepth(string s) {
		stack<int> st;
		int depth = 0, maxdepth = 0;;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				if (st.empty())
					st.push(1);
				else
					st.push(st.top() + 1);
			}
			else if (s[i] == ')') {
				maxdepth = max(st.top(), maxdepth);
				st.pop();
			}
		}
		return maxdepth;
	}
};