// Link - https://leetcode.com/problems/stone-game/
// Author - Shumbul Arifa

class Solution {
    int memo[501][501];
    int solve(vector<int> piles, int s, int e) {
        if (s > e)
            return 0;
        if (memo[s][e] != -1)
            return memo[s][e];
        if (s == e)
            return memo[s][e] = piles[s];
        return memo[s][e] = max(piles[s] - solve(piles, s + 1, e), piles[e] - solve(piles, s, e - 1));
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(memo, -1, sizeof memo);
        return solve(piles, 0, n - 1) > 0;
    }
};

// method - 2

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

// because it's gven that piles length is always even