// Link - https://leetcode.com/problems/divisor-game/
// Author - Shumbul Arifa

// 1. Best solution
class Solution {
public:
	bool divisorGame(int n) {
		return !(n % 2);
	}
};

// 2
class Solution {
public:
	bool divisorGame(int n) {
		bool dp[n + 1];
		memset(dp, 0, sizeof dp);
		dp[0] = true;

		for (int i = 2; i <= n; i++) {
			for (j = 1; j <= (i + 1) / j; j++) {
				if (i % j == 0 && !dp[i - j])
					dp[i] = true;
			}
		}
		return dp[n];
	}
};

// 3. recursion + memoization
class Solution {
	int dp[100001];
	int help(int n) {
		if (n == 1)
			return 0;
		if (dp[n] != -1)
			return dp[n];
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				if (help(n - i) == 0) // next player loses with n-i
					return dp[n] = 1;
			}
		}
		return dp[n] = 0;
	}
public:
	bool divisorGame(int n) {
		memset(dp, -1, sizeof(dp));
		return help(n);
	}
};

// 4
class Solution {
	int dp[100001];
	int help(int n) {
		if (n == 1)
			return 0;
		if (dp[n] != -1)
			return dp[n];
		for (int i = 1; i <= n / i; i++) {
			if (n % i == 0) {
				if (help(n - i) == 0) // next player loses with n-i
					return dp[n] = 1;
				if (i != 1 && help(n - n / i) == 0) // next player loses with n-i
					return dp[n] = 1;
			}
		}
		return dp[n] = 0;
	}
public:
	bool divisorGame(int n) {
		memset(dp, -1, sizeof(dp));
		return help(n);
	}
};