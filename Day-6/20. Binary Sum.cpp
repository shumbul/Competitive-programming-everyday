// Link - https://codedrills.io/problems/binary-sum
// Author - Shumbul Arifa

#include<bits/stdc++.h>
using namespace std;

class BinarySum {
	string ans;
	void solve(string n1, string n2) {
		int l1 = n1.length() - 1, l2 = n2.length() - 1;
		bool carry = 0;
		while (l1 >= 0 || l2 >= 0 || carry) {
			int val1, val2;
			(l1 >= 0) ? (val1 = n1[l1] - '0') : (val1 = 0);
			(l2 >= 0) ? (val2 = n2[l2] - '0') : (val2 = 0);
			int val = val1 + val2 + carry;
			if (val == 3) {	// 1 1 1
				carry = 1;
				val = 1;
			}
			else if (val == 2) {	// 1 1
				carry = 1;
				val = 0;
			}
			else if (val == 1) {
				carry = 0;
			}
			ans += to_string(val);
			l1--, l2--;
		}
		reverse(ans.begin(), ans.end());
	}
public:
	std::string getBinarySum(std::string num1, std::string num2) {
		// Code here
		ans = "";
		solve(num1, num2);
		return ans;
	}
};


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;	cin >> t;
	int T = 0;
	while (t--) {
		cout << "Test " << ++T << ":\n";
		BinarySum A;
		string num1 = "11", num2 = "110";
		auto v = A.getBinarySum(num1, num2);
		cout << v;
		cout << "\n";
	}

}