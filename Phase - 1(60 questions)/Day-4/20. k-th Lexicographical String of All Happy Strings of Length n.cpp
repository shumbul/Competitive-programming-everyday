// Link - https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
// Author - Shumbul Arifa

class Solution {
	vector<string> sets;
	string allowed;
	void fill(int n, string curr) {
		if (curr.length() == n) {
			sets.push_back(curr);
			return;
		}

		for (int i = 0; i < allowed.length(); i++) {
			if (curr == "") {
				curr += allowed[i];
				fill(n, curr);
				curr.pop_back();
			}
			else {
				if (curr[curr.length() - 1] != allowed[i]) {
					curr += allowed[i];
					fill(n, curr);
					curr.pop_back();
				}
			}
		}

	}
public:
	string getHappyString(int n, int k) {
		allowed = "abc";
		fill(n, "");
		// generating sets
		sort(sets.begin(), sets.end());
		if (sets.size() < k)
			return "";
		return sets[k - 1];
	}
};