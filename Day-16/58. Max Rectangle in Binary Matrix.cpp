// Link - https://www.interviewbit.com/old/problems/max-rectangle-in-binary-matrix/
// Author - Shumbul Arifa

/**
 * @input A : 2D integer array
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 *
 * @Output Integer
 */

int MaxAreaHist(vector<int> h) {
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
int Solution::maximalRectangle(vector<vector<int> > &A) {
	int n11 = A.size(), n12 = A[0].size();
	// not done using recursion, but using DP + max area histogram
	vector<int> hist(n12, 0);
	int ans = 0;
	for (int i = 0; i < n11; i++) {
		for (int j = 0; j < n12; j++) {
			hist[j] = ((A[i][j] == 0) ? 0 : (hist[j] + 1));
		}
		ans = max(ans, MaxAreaHist(hist));
	}
	return ans;
}
