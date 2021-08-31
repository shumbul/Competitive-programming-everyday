// Link - https://leetcode.com/problems/get-maximum-in-generated-array/
// Author - Shumbul Arifa

class Solution {
	unordered_map<int, int> mp;
	int N;
	int ans = 0;
	int solve(int n) {
		if (n < 2)
			return mp[n] = n;
		if (mp.find(n) != mp.end())
			return mp[n];
		if (n % 2 == 0)
			return mp[n] = solve(n / 2);
		return mp[n] = solve((n - 1) / 2) + solve((n + 1) / 2);
	}
public:
	int getMaximumGenerated(int n) {
		N = n;
		ans = 0;
		for (int i = 1; i <= n; i++)
			solve(i), ans = max(mp[i], ans);
		return ans;
	}
};