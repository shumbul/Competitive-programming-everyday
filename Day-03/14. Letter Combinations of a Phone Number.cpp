// Link - https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author - Shumbul Arifa

#define pb push_back
class Solution {
	vector<string> ans;
	vector<char> ar[15];
	bool filled = 0;
	void fill() {
		ar[2].pb('a');
		ar[2].pb('b');
		ar[2].pb('c');
		ar[3].pb('d');
		ar[3].pb('e');
		ar[3].pb('f');
		ar[4].pb('g');
		ar[4].pb('h');
		ar[4].pb('i');
		ar[5].pb('j');
		ar[5].pb('k');
		ar[5].pb('l');
		ar[6].pb('m');
		ar[6].pb('n');
		ar[6].pb('o');
		ar[7].pb('p');
		ar[7].pb('q');
		ar[7].pb('r');
		ar[7].pb('s');
		ar[8].pb('t');
		ar[8].pb('u');
		ar[8].pb('v');
		ar[9].pb('w');
		ar[9].pb('x');
		ar[9].pb('y');
		ar[9].pb('z');
		filled = 1;
	}
	void dfs(int i, string s, string a) {
		if (i == s.length()) {
			ans.pb(a);
			return;
		}
		string tmp;
		for (char b : ar[s[i] - '0']) {
			tmp = a;
			tmp += b;
			dfs(i + 1, s, tmp);
		}
	}
public:
	vector<string> letterCombinations(string digits) {
		if (!filled)
			fill();
		ans.clear();
		if (digits.length() == 0)
			return ans;
		dfs(0, digits, "");
		return ans;
	}
};