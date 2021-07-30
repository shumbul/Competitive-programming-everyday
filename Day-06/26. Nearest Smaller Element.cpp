// Link - https://www.interviewbit.com/old/problems/nearest-smaller-element/
// Author - Shumbul Arifa

vector<int> Solution::prevSmaller(vector<int> &a) {
	stack<int> st;
	vector<int> ans(a.size());
	for (int i = 0; i < a.size(); i++) {
		if (st.empty()) {
			st.push(a[i]);
			ans[i] = -1;
		}
		else if (st.top() < a[i]) {
			ans[i] = st.top();
			st.push(a[i]);
		}
		else {
			while (!st.empty() && st.top() >= a[i]) {
				st.pop();
			}
			if (st.empty())
				ans[i] = -1;
			else
				ans[i] = st.top();
			st.push(a[i]);
		}
	}
	return ans;
}
