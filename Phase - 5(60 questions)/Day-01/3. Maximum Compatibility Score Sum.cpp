// Link - https://leetcode.com/contest/weekly-contest-251/problems/maximum-compatibility-score-sum/
// Author - Shumbul Arifa

// Backtracking - Accepted
class Solution {
	int calcComp(vector<vector<int>>& students, vector<vector<int>>& mentors, int sidx, int midx) {
		int ans = 0;
		for (int i = 0; i < students[0].size(); i++) {
			if (students[sidx][i] == mentors[midx][i])
				ans++;
		}
		return ans;
	}
	void solve(vector<vector<int>>& students, vector<vector<int>>& mentors, int idx, set<int> available_mentors, int score, int &res) {
		// base
		if (idx == students.size()) {
			res = max(res, score);
			return;
		}

		// main
		auto b = available_mentors;
		for (int am : available_mentors) {
			int comp = calcComp(students, mentors, idx, am);
			b.erase(am);
			solve(students, mentors, idx + 1, b, score + comp, res);
			b.insert(am);
		}
	}
public:
	int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
		// greedy doesn't work! We have to check all possible combinations
		// thus, we go for backtracking

		set<int> available_mentors;
		for (int i = 0; i < mentors.size(); i++) {
			available_mentors.insert(i);
		}
		int res = 0;
		solve(students, mentors, 0, available_mentors, 0, res);
		return res;
	}
};

// Greedy - Wrong ans => Fails!
class Solution {
	int diff(string s1, string s2) {
		int res = 0;
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				res++;
		}
		return res;
	}
public:
	int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
		vector<string> s, m;
		for (auto a : students) {
			string tmp;
			for (int b : a) {
				tmp += b + '0';
			}
			s.push_back(tmp);
		}
		sort(s.begin(), s.end());
		for (auto a : s)
			cout << a << " ";
		cout << "\n";
		for (auto a : mentors) {
			string tmp;
			for (int b : a) {
				tmp += b + '0';
			}
			m.push_back(tmp);
		}
		sort(m.begin(), m.end());
		for (auto a : m)
			cout << a << " ";
		cout << "\n";
		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			string s1 = s[i], m1 = m[i];
			if (s1 != m1)
				ans += diff(s1, m1);
		}
		return s[0].length() * s.size() - ans;
	}
};