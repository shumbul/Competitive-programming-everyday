// Link - https://leetcode.com/problems/sorting-the-sentence/
// Author - Shumbul Arifa

class Solution {
public:
	string sortSentence(string s) {
		vector<string> v(201);
		int m = 0, k;
		string t;
		for (int i = 0; i < s.length() - 1; i++) {
			t = "";
			while (i + 2 == s.length() || (i + 1 < s.length() && s[i + 1] != ' ')) {
				t += s[i++];
			}
			if (i < s.length()) {
				k = s[i] - '0';
				i++;
				v[k - 1] = t;
				m = max(m, k - 1);
			}
			// cout<<t<<" -> ";
		}
		t = "";
		for (int i = 0; i <= m; i++) {
			t += v[i];
			t += " ";
		}
		t.pop_back();
		return t;
	}
};