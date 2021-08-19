// Link - https://www.interviewbit.com/old/problems/longest-substring-without-repeat/
// Author - Shumbul Arifa

int Solution::lengthOfLongestSubstring(string A) {
	int l = 0, n = A.size();
	if (n <= 1)
		return n;

	int i = 0, j = 1, curr = 1, max_l = 1;
	set<char> st;
	st.insert(A[i]);
	while (j < n) {
		if (st.find(A[j]) == st.end()) {
			curr++;
			st.insert(A[j]);
		}
		else {
			max_l = max(max_l, curr);
			while (A[i] != A[j] && i < j)
				st.erase(A[i]), i++;
			i++;
			curr = j - i + 1;
		}
		j++;
	}
	max_l = max(max_l, curr);
	return max_l;
}