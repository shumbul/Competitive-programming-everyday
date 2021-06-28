// Link - https://www.interviewbit.com/old/problems/n-max-pair-combinations/
// Author - Shumbul Arifa

#define mp make_pair
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
	sort(A.begin(), A.end());
	sort(B.begin(-max - p), B.end());
	int n = A.size();
	vector<int> ans;
	priority_queue< pair<int, pair<int, int> > > q;
	set<pair<int, int>> st;
	// last elements are surely the greatest pair
	q.push(mp(A[n - 1] + B[n - 1], mp(n - 1, n - 1)));
	st.insert(mp(n - 1, n - 1));
	int k = n;
	// because we want max n elements
	while (k--) {
		auto top = q.top(); q.pop();
		int e = top.first;
		int L = top.second.first;
		int R = top.second.second;
		// max of @ time and space complexity
		if (R > 0 && L >= 0 && (st.find(mp(L, R - 1)) == st.end()) ) {
			q.push(mp(A[L] + B[R - 1], mp(L, R - 1)));
			st.insert(mp(L, R - 1));
		}
		if (L > 0 && R >= 0 && (st.find(mp(L - 1, R)) == st.end()) ) {
			q.push(mp(A[L - 1] + B[R], mp(L - 1, R)));
			st.insert(mp(L - 1, R));
		}
		ans.push_back(e);
	}
	sort(ans.begin(), ans.end(), greater());
	ans.resize(n);
	return ans;
}

// BRUTE FORCE SOLUTION
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
	int n = A.size();
	vector<int> ans;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (q.size() < n)
				q.push(A[i] + B[j]);
			else if (A[i] + B[j] > q.top()) {
				q.pop();
				q.push(A[i] + B[j]);
			}
		}
	}
	while (!q.empty()) {
		ans.insert(ans.begin(), q.top());
		q.pop();
	}
	return ans;
}
