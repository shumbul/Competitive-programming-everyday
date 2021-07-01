// Link - https://leetcode.com/problems/employee-importance/
// Author - Shumbul Arifa

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
	vector<int> ar[2002];
	map<int, int> imp;

public:
	int getImportance(vector<Employee*> emp, int id) {
		for (auto e : emp) {
			imp[e->id] = e->importance;
			for (auto s : e->subordinates) {
				ar[e->id].push_back(s);
			}
		}
		int ans = 0;
		deque<int> q;
		q.push_front(id);
		while (!q.empty()) {
			int val = q.front();
			ans += imp[val];
			q.pop_front();
			for (int i : ar[val]) {
				q.push_back(i);
			}
		}
		return ans;
	}
};