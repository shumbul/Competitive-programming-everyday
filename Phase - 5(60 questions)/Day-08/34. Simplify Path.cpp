// Link - https://leetcode.com/problems/simplify-path/
// Author - Shumbul Arifa

class Solution {
public:
	string simplifyPath(string path) {
		int n = path.size();
		vector<string> v;
		string ans;
		for (int i = 0; i < n; i++) {
			string dir = "";
			while (i < n && path[i] != '/') {
				dir += path[i];
				i++;
			}
			if (dir == "..") {
				if (!v.empty())
					v.pop_back();
			}
			else if (dir == "." || dir == "") {}
			else {
				v.push_back(dir);
			}
			// cout<<dir<<"\n";
		}
		for (string s : v)
			ans += "/" + s;
		if (ans == "")
			ans = "/";
		return ans;
	}
};