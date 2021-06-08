// Link - https://leetcode.com/problems/longest-valid-parentheses/submissions/
// Link - https://practice.geeksforgeeks.org/problems/valid-substring0624/1
// Author - Shumbul Arifa

class Solution {
public:
	int longestValidParentheses(string s) {
		// method - 1: stacks
		stack<int> t;
		t.push(-1);
		int ans = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(')
				t.push(i);
			else {
				if (!t.empty())
					t.pop();
				if (!t.empty()) {
					ans = max(ans, i - t.top());
				}
				else {
					t.push(i);
				}
			}
		}
		return ans;

		// O(1) space and O(n) time
		int left_ = 0, right_ = 0, ans = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(')
				left_++;
			else
				right_++;

			if (right_ > left_)
				right_ = left_ = 0;
			else if (left_ == right_)
				ans = max(ans, 2 * right_);
		}
		left_ = right_ = 0;
		for (int i = s.length() - 1 ; i >= 0; i--) {
			if (s[i] == '(')
				left_++;
			else
				right_++;

			if (right_ < left_)
				right_ = left_ = 0;
			else if (left_ == right_)
				ans = max(ans, 2 * right_);
		}
		return ans;
	}
};