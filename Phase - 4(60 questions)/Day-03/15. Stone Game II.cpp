// Link - https://leetcode.com/problems/stone-game-ii/
// Author - Shumbul Arifa

class Solution {
	int dp[101][202];
	int solve(int i, int M, vector<int> piles) {
		if (i >= piles.size())
			return 0;
		if (dp[i][M] != -1)
			return dp[i][M];
		int tot = 0;
		int ans = INT_MIN;
		for (int j = 0; j < 2 * M; j++) {
			if ((i + j) < piles.size())
				tot += piles[i + j];
			ans = max(ans, tot - solve(i + j + 1, max(M, j + 1), piles));

		}
		return dp[i][M] = ans;
	}
public:
	int stoneGameII(vector<int>& piles) {
		int sum = accumulate(piles.begin(), piles.end(), 0);
		memset(dp, -1, sizeof dp);
		return (sum + solve(0, 1, piles)) / 2;
	}
};