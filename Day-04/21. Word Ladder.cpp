// Link - https://leetcode.com/problems/word-ladder/
// Author - Shumbul Arifa

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& word) {
		queue<string> q;
		q.push(beginWord);
		int n = word.size();
		unordered_set<string> todo(word.begin(), word.end());
		int ans = 1;
		while (!q.empty()) {
			int s = q.size();
			while (s--) {
				string f = q.front();
				todo.erase(f);
				if (f == endWord)
					return ans;
				q.pop();
				for (int i = 0; i < f.size(); i++) {
					char c = f[i];
					for (int j = 0; j < 26; j++) {
						if (j == c - 'a')
							continue;
						f[i] = j + 'a';
						if (todo.find(f) != todo.end())
							q.push(f);
					}
					f[i] = c;
				}
			}
			ans++;
		}
		return 0;
	}
};