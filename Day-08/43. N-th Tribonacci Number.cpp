// Link - https://leetcode.com/problems/n-th-tribonacci-number/
// Author - Shumbul Arifa

class Solution {
	map<int , int> mp;
public:
	int tribonacci(int n) {
		if (n < 2)
			return n;
		if (n == 2)
			return 1;
		if (mp.find(n) != mp.end())
			return mp[n];
		return mp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
	}
};