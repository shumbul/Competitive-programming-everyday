// Link - https://leetcode.com/contest/weekly-contest-251/problems/sum-of-digits-of-string-after-convert/
// Author - Shumbul Arifa

class Solution {
public:
	int getLucky(string s, int k) {
		vector<int> all;
		for (int i = 0; i < s.length(); i++) {
			int dig = s[i] - 'a' + 1;
			while (dig) {
				all.insert(all.begin(), dig % 10);
				dig /= 10;
			}
		}
		for (auto a : all)
			cout << a << " ";
		// brute force
		while (k) {
			int sum = 0;
			for (int a : all)
				sum += a;
			all.clear();
			while (sum) {
				all.insert(all.begin(), sum % 10);
				sum /= 10;
			}
			if (all.size() == 1)
				break;
			k--;
		}
		cout << endl;
		s = "";
		for (int a : all)
			s += to_string(a);
		cout << s << "-<";
		return stoi(s);
	}
};