// Link - https://www.interviewbit.com/old/problems/largest-rectangle-in-histogram/
// Author - Shumbul Arifa

int Solution::largestRectangleArea(vector<int> &A) {
	// For each element, we have to find the left and right width
	// by width -> means how much it can be expanded
	// i.e consecutive elements to the left which are not less than curr element, same for right case

	int n = A.size();
	vector<int> nsl(n), nsr(n), width(n), area(n);
	stack<int> st;
	// nsl
	for (int i = 0; i < n; i++) {
		if (st.empty()) {
			st.push(i);
			nsl[i] = -1;
		}
		else if (!st.empty() && A[st.top()] < A[i]) {
			nsl[i] = st.top();
			st.push(i);
		}
		else {
			while (!st.empty() && A[st.top()] >= A[i]) {
				st.pop();
			}
			if (st.empty()) {
				nsl[i] = -1;
			}
			else {
				nsl[i] = st.top();
			}
			st.push(i);
		}
	}

	while (!st.empty())
		st.pop();
	// nsr
	for (int i = n - 1; i >= 0; i--) {
		if (st.empty()) {
			st.push(i);
			nsr[i] = n;
		}
		else if (!st.empty() && A[st.top()] < A[i]) {
			nsr[i] = st.top();
			st.push(i);
		}
		else {
			while (!st.empty() && A[st.top()] >= A[i]) {
				st.pop();
			}
			if (st.empty()) {
				nsr[i] = n;
			}
			else {
				nsr[i] = st.top();
			}
			st.push(i);
		}
	}

	for (int i = 0; i < n; i++) {
		// cout<<nsr[i]<<" "<<nsl[i]<<" -> ";
		width[i] = nsr[i] - nsl[i] - 1;
	}

	for (int i = 0; i < n; i++) {
		area[i] = A[i] * width[i];
	}
	return *max_element(area.begin(), area.end());
}
