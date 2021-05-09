// Link - https://leetcode.com/problems/count-primes
// Author - Shumbul Arifa

class Solution {
	bool prime[5000001];

	void ALGO_sieve(int n) {
		memset(prime, true, n + 2);
		for (int p = 2; p * p <= n ; p++) {
			if (prime[p] == true) {
				for (int i = p * p; i <= n; i += p)
					prime[i] = false;
			}
		}
	}
public:
	int countPrimes(int n) {
		if (n < 2)
			return 0;
		ALGO_sieve(n);
		int ans = 0;
		for (int i = 2; i < n; i++) {
			if (prime[i])
				ans++;
		}
		return ans;
	}
};