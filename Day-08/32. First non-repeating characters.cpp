// Link - https://www.interviewbit.com/old/problems/first-non-repeating-character-in-a-stream-of-characters/
// Author - Shumbul Arifa

string Solution::solve(string A) {
	vector<int> alpha(26, 0);
	queue<char> q;
	string ans = "";
	for (char c : A) {
		alpha[c - 'a']++;
		while (!q.empty() && alpha[q.front() - 'a'] > 1)
			q.pop();
		if (q.empty()) {
			if (alpha[c - 'a'] == 1)
				ans += c, q.push(c);
			else
				ans += '#';
		}
		else {
			ans += q.front();
			if (alpha[c - 'a'] == 1)
				q.push(c);
		}
	}
	return ans;
}
