// Link - https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
// Author - Shumbul Arifa

class Solution {
public:
	vector<int> finalPrices(vector<int>& p) {
		stack<int> st;
		vector<int> ans = p;
		for (int i = p.size() - 1; i >= 0; i--) {
			if (st.empty()) {
				st.push(i);
			}
			else {
				if (p[st.top()] > p[i]) {
					while (!st.empty() && p[st.top()] > p[i])
						st.pop();
				}
				if (!st.empty()) {
					ans[i] -= p[st.top()];
				}
				st.push(i);
			}
		}
		return ans;
	}
};