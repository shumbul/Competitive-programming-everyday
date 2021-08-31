// Link - https://leetcode.com/problems/get-maximum-in-generated-array/
// Author - Shumbul Arifa

class Solution {
	map<int, int> mp;
	vector<int> ar;
	int N;
	int solve(int n) {
		if (n < 2)
			return n;
		if (mp.find(n) != mp.end())
			return mp[n];
		if (n >= 2 && n <= N)
			mp[n] = mp[n / 2];
		return mp[n] = mp[n / 2] + mp[n / 2 + 1];
	}
public:
	int getMaximumGenerated(int n) {
		N = n;
		ar.resize(N);
		for (int i = 0; i < n; i++)
			solve(i);
		return *max(ar.begin(), ar.end());
	}
};