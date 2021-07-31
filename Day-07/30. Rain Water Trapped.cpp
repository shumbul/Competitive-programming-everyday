// Link - https://www.interviewbit.com/old/problems/rain-water-trapped/
// Author - Shumbul Arifa

#include<bits/stdc++.h>
int Solution::trap(const vector<int> &A) {
	int n = A.size();
	vector<int> mxl(n), mxr(n), water(n);
	for (int i = 0; i < n; i++)
		if (i == 0)    mxl[i] = A[i];
		else        mxl[i] = max(mxl[i - 1], A[i]);
	for (int i = n - 1; i >= 0; i--)
		if (i == n - 1)    mxr[i] = A[i];
		else        mxr[i] = max(mxr[i + 1], A[i]);
	for (int i = 0; i < n; i++)
		water[i] = min(mxl[i], mxr[i]) - A[i];
	return accumulate(water.begin(), water.end(), 0);
}
