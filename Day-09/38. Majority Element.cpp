// Link - https://www.interviewbit.com/old/problems/majority-element/
// Author - Shumbul Arifa

int Solution::majorityElement(const vector<int> &A) {
	int ans = 0, cnt = 0;
	for (int i = 0; i < A.size(); i++) {
		if (cnt == 0) {
			ans = A[i];
			cnt++;
		}
		else {
			if (A[i] == ans)
				cnt++;
			else cnt--;
		}
	}
	return ans;
}
