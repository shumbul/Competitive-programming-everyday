// Link - https://leetcode.com/problems/find-the-town-judge/
// Author - Shumbul Arifa

// METHOD - 1
class Solution {
public:
	int findJudge(int n, vector<vector<int>>& trust) {
		if (n == 1)
			return 1;
		set<int> poss;
		for (int i = 1; i <= n; i++) {
			poss.insert(i);
		}
		for (auto a : trust) {
			poss.erase(a[0]);
		}
		map<int, set<int>> mp;
		for (auto t : poss)
			mp[t];
		for (auto a : trust) {
			if (mp.find(a[1]) != mp.end()) {
				mp[a[1]].insert(a[0]);
				if (mp[a[1]].size() == n - 1)
					return a[1];
			}
		}
		return -1;
	}
};

// METHOD - 2
class Solution {
public:
	int findJudge(int n, vector<vector<int>>& trust) {
		if (n == 1)
			return 1;
		set<int> poss;
		for (auto a : trust) {
			poss.insert(a[0]);
		}
		vector<int> cnt(1002, 0);
		for (auto t : trust) {
			++cnt[t[1]];
		}
		for (int i = 1; i <= n; i++) {
			if (cnt[i] == n - 1 && poss.find(i) == poss.end())
				return i;
		}
		return -1;
	}
};

// METHOD - 3 (easiest and fastest among all)
class Solution {
public:
	int findJudge(int n, vector<vector<int>>& trust) {
		if (n == 1)
			return 1;
		vector<int> cnt(1002, 0);
		for (auto t : trust) {
			--cnt[t[0]];
			++cnt[t[1]];
		}
		for (int i = 1; i <= n; i++) {
			if (cnt[i] == n - 1)
				return i;
		}
		return -1;
	}
};