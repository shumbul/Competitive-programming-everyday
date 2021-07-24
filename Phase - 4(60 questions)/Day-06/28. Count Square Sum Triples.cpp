// Link - https://leetcode.com/contest/biweekly-contest-56/problems/count-square-sum-triples/
// Author - Shumbul Arifa

class Solution {
public:
	int countTriples(int n) {
		int cnt = 0;
		for (int i = 3; i <= n; i++) {
			for (int j = 3; j <= n; j++) {
				double d = sqrt(i * i + j * j);
				int dd = d;
				if (dd == d && d <= n)
					cnt++;
			}
		}
		return cnt;
	}
};