// Link - https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1
// Link - https://leetcode.com/problems/valid-parentheses/submissions/
// Author - Shumbul Arifa

class Solution {
public:
	bool isValid(string s) {
		// using stack
		stack<char> st;
		for (char c : s) {
			if (c == '(' || c == '[' || c == '{')
				st.push(c);
			else {
				if (st.empty())
					goto end;
				char t = st.top();
				if (t == '(' && c != ')' || t == '[' && c != ']' || t == '{' && c != '}')
					goto end;
				st.pop();
			}
			// if(!st.empty()){
			//     cout<<c<<" "<<st.top()<<"\n";
			// }
		}
		// cout<<"\n\n";
		return st.empty();
end:
		return false;
	}
};