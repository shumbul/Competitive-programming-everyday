// Link - https://www.interviewbit.com/problems/increasing-path-in-matrix/
// Author - Shumbul Arifa

bool mainans = false;
bool path(vector<vector<int> > &A, int i, int j, int n1, int n2) {
	// cout<<A[i][j]<<"\n";
	if (i == n1 - 1 && j == n2 - 1) {
		mainans = true;
		return true;
	}
	bool ans = false;
	if (i + 1 < n1 && A[i + 1][j] > A[i][j] && !mainans)
		ans = path(A, i + 1, j, n1, n2);
	if (j + 1 < n2 && A[i][j + 1] > A[i][j] && !mainans)
		ans = ans || path(A, i, j + 1, n1, n2);
	return ans || mainans;
}

int Solution::solve(vector<vector<int> > &A) {
	// if path doesn't exist, ans is -1
	// if path exists, based the the given conditions, ans is n1+n2-1
	// we just have to check if the path exists or not
	int n1 = A.size(), n2 = A[0].size();
	mainans = false;
	if (path(A, 0, 0, n1, n2) || mainans)
		return n1 + n2 - 1;
	return -1;
}