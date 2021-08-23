// Link - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Author - Shumbul Arifa

class Solution {
public:
	string removeDuplicates(string s) {
		stack<char> st;
		string ans;
		for (int i = 0; i < s.length(); i++) {
			if (st.empty())
				st.push(s[i]);
			else {
				if (st.top() == s[i]) {
					while (!st.empty() && st.top() == s[i])
						st.pop();
				}
				else    st.push(s[i]);
			}
		}
		while (!st.empty())
			ans += st.top(), st.pop();
		reverse(ans.begin(), ans.end());
		return ans;
	}
};