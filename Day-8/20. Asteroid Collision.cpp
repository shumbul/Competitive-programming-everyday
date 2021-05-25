// Link - https://leetcode.com/problems/asteroid-collision/submissions/
// Author - Shumbul Arifa

class Solution {
public:
	vector<int> asteroidCollision(vector<int>& a) {
		stack<int> st;
		vector<int> ans;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] > 0) {
				st.push(a[i]);
			}
			else {
				if (!st.empty()) {
					// we compare
					while (!st.empty() && st.top() < abs(a[i]) && st.top() > 0) {
						// powerful stays
						st.pop();
					}
					if (!st.empty() && st.top() == abs(a[i]) && st.top() > 0) {
						st.pop();
						continue;
					}
					if (!st.empty() && st.top() < 0 || st.empty())
						st.push(a[i]);
				}
				else {
					st.push(a[i]);
				}
			}
		}
		while (!st.empty())
			ans.push_back(st.top()), st.pop();

		reverse(ans.begin(), ans.end());
		return ans;
	}
};