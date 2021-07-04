// Link - https://leetcode.com/problems/divisor-game/
// Author - Shumbul Arifa

class Solution {
public:
	bool divisorGame(int n) {
		// brute force
		int dp[n + 1];
		dp[0] = true;
		dp[1] = false;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j * j <= i + 1; j++) {
				if (i % j == 0 && !dp[i - j])
					dp[i] = true;
			}
		}
		return dp[n];
	}
};

// maths
class Solution {
public:
	bool divisorGame(int n) {
		return !(n % 2);
	}
};