// Link - https://binarysearch.com/problems/Count-Substrings-With-All-1s
// Author - Shumbul Arifa

int solve(string s) {
	int i = 0, t = 0, ans = 0, k = s.length();
	while (i <= k) {
		if (i == k) {
			ans += (t * (t + 1) / 2);
		}
		else if (s[i] == '1')
			t++;
		else if (t) {
			ans += (t * (t + 1) / 2);
			t = 0;
		}
		i++;
	}
	return ans;
}