// Link - https://leetcode.com/problems/largest-rectangle-in-histogram/
// Link - https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1
// Author - Shumbul Arifa

class Solution {
public:
	int largestRectangleArea(vector<int>& h) {
		stack<int> st;
		int n = h.size();
		if (n < 1)
			return 0;
		int area, maxArea = 0, top = h[0];
		for (int i = 0; i < n;) {
			if (st.empty() || h[st.top()] <= h[i]) {
				st.push(i++);
			}
			else {
				top = st.top();
				st.pop();
				if (st.empty()) {
					area = h[top] * i;
				}
				else {
					area = h[top] * (i - st.top() - 1);
				}
				maxArea = max(area, maxArea);
			}
		}
		int i = n;
		while (!st.empty()) {
			top = st.top();
			st.pop();
			if (st.empty()) {
				area = h[top] * i;
			}
			else {
				area = h[top] * (i - st.top() - 1);
			}
			maxArea = max(area, maxArea);
		}
		return maxArea;
	}
};