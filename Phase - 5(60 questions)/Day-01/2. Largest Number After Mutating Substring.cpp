// Link - https://leetcode.com/contest/weekly-contest-251/problems/largest-number-after-mutating-substring/
// Author - Shumbul Arifa

class Solution {
public:
	string maximumNumber(string num, vector<int>& change) {
		bool changed = 0;
		for (unsigned int i = 0; i < num.length(); i++) {
			int n1 = change[num[i] - '0'];
			int n2 = num[i] - '0';
			// cout<<n1<<" "<<n2<<"\n";
			// printing gives TLE
			if (n1 < n2 && changed)
				break;
			if (n1 == n2 || (!changed && n1 < n2))
				continue;
			num[i] = change[num[i] - '0'] + '0';
			changed = 1;
		}
		return num;
	}
};