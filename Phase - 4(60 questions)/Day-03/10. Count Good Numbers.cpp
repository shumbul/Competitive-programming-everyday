// Link - https://leetcode.com/contest/weekly-contest-248/problems/count-good-numbers/
// Author - Shumbul Arifa

const int mod = 1e9 + 7;
typedef long long ll;
ll power(ll a, ll n, ll mod) {ll p = 1; while (n > 0) {if (n % 2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}
class Solution {
public:
	int countGoodNumbers(long long n) {
		if (n == 1)
			return 5;
		long long ans = 1, five = 5, four = 4;
		// n=n%mod;  -> never do this !
		return ((power(five, n - n / 2, mod) % mod) * (power(four, n / 2, mod) % mod)) % mod;
	}
};