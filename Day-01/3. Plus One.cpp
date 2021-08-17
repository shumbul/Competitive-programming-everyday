// Link - https://leetcode.com/explore/learn/card/array-and-string/201/introduction-to-array/1148/
// Author - Shumbul Arifa

// METHOD-1
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> ans;
		int n = digits.size();
		int carry = 1;
		for (int i = n - 1; i >= 0; i--) {
			ans.push_back((digits[i] + carry) % 10);
			carry = (digits[i] + carry) / 10;
		}
		if (carry)
			ans.push_back(carry);
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

// METHOD-2
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int n = digits.size();
		auto digs = digits;
		if (digs[n - 1] != 9) {
			digs[n - 1]++;
			return digs;
		}
		int carry = 1;
		int i = n - 1;
		while (carry && i >= 0) {
			int val = (digs[i] + carry);
			carry = 1 ? val > 9 : 0;
			digs[i] = val % 10;
			i--;
		}
		if (carry) {
			digs.insert(digs.begin(), carry);
		}
		return digs;
	}
};