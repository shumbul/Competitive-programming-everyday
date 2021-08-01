// Link - https://www.interviewbit.com/old/problems/redundant-braces
// Author - Shumbul Arifa

int Solution::braces(string A) {
	set<pair<int, int>> p;
	stack<int> st;
	for (int i = 0; i < A.length(); i++) {
		if (A[i] == '(')
			st.push(i);
		else if (A[i] == ')') {
			assert(!st.empty());
			int t = st.top();
			st.pop();
			if (p.find(make_pair(t + 1, i - 1)) != p.end() || t > i - 3)
				return 1;
			p.insert(make_pair(t, i));
		}
	}
	return 0;
}