// Link - https://leetcode.com/problems/operations-on-tree/
// Author - Shumbul Arifa

class LockingTree {
	vector<int> par;
	map<int, int> locked;
	vector<int> ar[20002];
	int n;
public:
	LockingTree(vector<int>& parent) {
		// cout<<" E1 ";
		par = parent;
		locked.clear();
		n = par.size();
		for (int i = 0; i < n; i++)
			ar[i].clear();
		for (int i = 1; i < n; i++)
			ar[par[i]].push_back(i);
		// cout<<" E2\n";
	}

	bool lock(int num, int user) {
		// cout<<" L1 ";
		if (locked.find(num) == locked.end()) {
			locked[num] = user;
			return true;
		}
		// cout<<" L2\n";
		return false;
	}

	bool unlock(int num, int user) {
		// cout<<" U ";
		if (locked.find(num) != locked.end() && locked[num] == user) {
			locked.erase(num);
			return true;
		}
		// cout<<" U2\n";
		return false;
	}

	bool upgrade(int num, int user) {
		int i = num;
		if (locked.find(num) != locked.end())
			return false;
		// cout<<" UG1 ";
		// for(auto a:locked)
		//     cout<<a.first<<" "<<a.second<<"\n";
		while (par[i] != -1) {
			if (locked.find(par[i]) != locked.end())
				return false;
			i = par[i];
		}
		// cout<<" UG2 ";
		queue<int> q;
		q.push(num);
		bool f = 0;
		while (!q.empty()) {
			int p = q.size();
			while (p--) {
				auto a = q.front();
				// cout<<a<<" -> ";
				q.pop();
				if (locked.find(a) != locked.end()) {
					f = 1;
					locked.erase(a);
				}
				for (auto j : ar[a])
					q.push(j);
			}
		}
		if (f) {
			locked[num] = user;
			return true;
		}
		// cout<<" UG3\n";
		return false;
	}
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */