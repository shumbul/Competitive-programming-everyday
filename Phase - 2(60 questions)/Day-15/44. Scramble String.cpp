// Link - https://www.interviewbit.com/problems/scramble-string/
// Author - Shumbul Arifa

map<pair<string, string>, bool> memo;
int Solution::isScramble(const string A, const string B) {
	pair<string, string> P = make_pair(A, B);
	if (memo.find(P) != memo.end())
		return memo[P];
	if (A.length() != B.length())
		return 0;
	int n = A.length();
	if (n == 0 || A == B)
		return 1;
	auto a = A, b = B;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (a != b)
		return false;
	for (int i = 1; i < n; i++) {
		if (isScramble(A.substr(0, i), B.substr(0, i)) && isScramble(A.substr(i, n - i), B.substr(i, n - i)) )
			return memo[P] = true;
		if (isScramble(A.substr(0, i), B.substr(n - i, i)) && isScramble(A.substr(i, n - i), B.substr(0, n - i)) )
			return memo[P] = true;
	}
	return memo[P] = false;
}

/* Another form:
for(int i=1;i<n;i++){
        if(isScramble(A.substr(0, i), B.substr(0,i)) && isScramble(A.substr(i), B.substr(i)) )
            return memo[P]=true;
        if(isScramble(A.substr(0, i), B.substr(n-i, i)) && isScramble(A.substr(i), B.substr(0, n-i)) )
            return memo[P]=true;
    }
*/
