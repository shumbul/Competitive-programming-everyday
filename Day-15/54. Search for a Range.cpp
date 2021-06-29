// Link - https://www.interviewbit.com/old/problems/search-for-a-range/
// Author - Shumbul Arifa

// METHOD-1
vector<int> Solution::searchRange(const vector<int> &A, int B) {
	int mid, l, r;
	l = 0, r = A.size() - 1;
	vector<int> ans = { -1, -1};
	while (l <= r) {
		mid = (r - l) / 2 + l;
		if (A[mid] == B) {
			// find 1st and last occurence
			if (A[l] == B)
				ans[0] = l;
			if (A[r] == B)
				ans[1] = r;
			if (ans[0] != -1 && ans[1] != -1)
				break;
			int L, R;
			L = mid - 1;
			R = mid + 1;
			while (L >= 0 && A[L] == B) {
				L--;
			}
			ans[0] = L + 1;
			while (R <= A.size() - 1 && A[R] == B) {
				R++;
			}
			ans[1] = R - 1;
			// cout<<"L l, R r, mid, ans[0], ans[1] "<<L<<" "<<l<<", "<<R<<" "<<r<<", "<<mid<<", "<<ans[0]<<",  "<<ans[1]<<" \n";
			break;
		}
		else if (B > A[mid])
			l = mid + 1;
		else
			r = mid - 1;
	}
	return ans;
}

// METHOD-2: using lower bound and upper bound
vector<int> Solution::searchRange(const vector<int> &A, int B) {
	vector<int> ans = { -1, -1};
	auto L = lower_bound(A.begin(), A.end(), B);
	auto U = upper_bound(A.begin(), A.end(), B);
	// cout<<L-A.begin()<<" "<<U-A.begin()<<" ";
	if (L - A.begin() >= 0 && A[L - A.begin()] == B) {
		ans[0] = L - A.begin();
	}
	if (U - A.begin() <= A.size() && A[U - A.begin() - 1] == B) {
		ans[1] = U - A.begin() - 1;
	}
	return ans;
}
