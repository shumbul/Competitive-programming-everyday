// Link - https://leetcode.com/problems/maximal-rectangle/
// Author - Shumbul Arifa

class Solution {
	int n, m;
	int MAH(vector<int> A) {
		vector<int> nsl(m), nsr(m);
		int ans = 0;
		// nsl
		stack<int> st;
		for (int i = 0; i < m; i++) {
			if (st.empty()) {
				st.push(i);
				nsl[i] = -1;
			}
			else if (A[i] > A[st.top()]) {
				nsl[i] = st.top();
				st.push(i);
			}
			else {
				while (!st.empty() && A[i] <= A[st.top()]) {
					st.pop();
				}
				if (st.empty())
					nsl[i] = -1;
				else
					nsl[i] = st.top();
				st.push(i);
			}
		}
		// nsr
		while (!st.empty())
			st.pop();
		for (int i = m - 1; i >= 0; i--) {
			if (st.empty()) {
				st.push(i);
				nsr[i] = m;
			}
			else if (A[i] > A[st.top()]) {
				nsr[i] = st.top();
				st.push(i);
			}
			else {
				while (!st.empty() && A[i] <= A[st.top()]) {
					st.pop();
				}
				if (st.empty())
					nsr[i] = m;
				else
					nsr[i] = st.top();
				st.push(i);
			}
		}

		// for(int i=0;i<m;i++)
		//     cout<<nsl[i]<<" "<<nsr[i]<<"\n";
		for (int i = 0; i < m; i++)
			ans = max(ans, A[i] * (nsr[i] - nsl[i] - 1));
		// cout<<ans<<" \n ";
		return ans;
	}
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		n = matrix.size();
		if (n == 0)
			return 0;
		m = matrix[0].size();
		int ans = 0;
		vector<vector<int>> v(n, vector<int> (m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] != '0') {
					if (i == 0)
						v[i][j] = matrix[i][j] - '0';
					else
						v[i][j] = matrix[i][j] - '0' + v[i - 1][j];
				}
				// cout<<v[i][j]<<" ";
			}
			// cout<<"\n";
		}

		for (vector<int> a : v)
			ans = max(ans, MAH(a));

		return ans;
	}
};