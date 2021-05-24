// Link - https://leetcode.com/problems/decode-string
// Author - Shumbul Arifa

class Solution {
public:
	string decodeString(string s) {
		stack<int> nst; // number stack
		stack<string> wst;  // word stack
		int i = 0;
		string ans = "";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '[') {
				wst.push(ans);
				ans = "";
			}
			else if (s[i] == ']') { // ']'
				// important
				string tmp = wst.top();
				int n = nst.top();
				wst.pop(), nst.pop();
				string sb = ans;
				for (int k = 2; k <= n; k++)
					ans += sb;
				tmp += ans;
				ans = tmp;
				tmp = "";
			}
			else if (isdigit(s[i])) {
				string time;
				bool in = 0;
				while (isdigit(s[i]) && i < s.length()) {
					time += s[i];
					in = 1;
					i++;
				}
				int times = stoi(time);
				nst.push(times);
				if (in)
					i--;
			}
			else if (isalpha(s[i])) {
				bool in = 0;
				while (isalpha(s[i]) && i < s.length()) {
					ans += s[i];
					in = 1;
					i++;
				}
				if (in)
					i--;
			}
			cout << ans << " ";
		}
		cout << "\n";
		return ans;
	}
};