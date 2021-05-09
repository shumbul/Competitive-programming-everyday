// Link - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3736/
// Author - Shumbul Arifa

// Optimised approach, smart solution

#define ll long long
class Solution {
	bool isPalindrome(string s) {
		for (int i = 0; i < s.length() / 2; i++) {
			if (s[i] != s[s.length() - i - 1])
				return 0;
		}
		return 1;
	}
public:
	int superpalindromesInRange(string left_, string right_) {
		ll left, right;
		left = stoll(left_);
		right = stoll(right_);
		int count = 0;

		// create palindromes in range [1...sqrt(10^9)]
		// Even palindromes
		for (int i = 1; i <= sqrt(1000000000); i++) {
			string sb = to_string(i);
			string s = sb;
			for (int j = s.length() - 1; j >= 0; j--)
				sb += s[j];

			ll n = stoll(sb);
			n *= n;
			// check if n is a superpalindrome or not
			if (n > right)
				break;
			else if (n >= left && isPalindrome(to_string(n))) {
				count++;
				// cout<<n<<" ";
			}
		}

		// Odd palindromes
		for (int i = 1; i <= sqrt(1000000000); i++) {
			string sb = to_string(i);
			string s = sb;
			for (int j = s.length() - 2; j >= 0; j--)
				sb += s[j];

			ll n = stoll(sb);
			n *= n;
			// check if n is a superpalindrome or not
			if (n > right)
				break;
			else if (n >= left && isPalindrome(to_string(n))) {
				count++;
				// cout<<n<<" ";
			}
		}
		return count;
	}
};


// Brute force method - give TLE for large length inputs

class Solution {
	vector<long long> pallin, sqpallin;
public:
	int superpalindromesInRange(string left_, string right_) {

		long long left, right;
		stringstream num(left_);
		num >> left;
		stringstream numr(right_);
		numr >> right;

		pallin.clear(), sqpallin.clear();
		for (long long i = sqrt(left); i <= right; i++) {
			string s = to_string(i);
			string rs = s;
			reverse(rs.begin(), rs.end());
			if (s == rs) {
				pallin.push_back(i);
			}
		}
		for (long long i : pallin) {
			// cout<<i<<" ";
			if (find(pallin.begin(), pallin.end(), i * i) != pallin.end()) {
				// cout<<i*i<<"\n";
				sqpallin.push_back(i * i);
			}
		}
		return sqpallin.size();
	}
};