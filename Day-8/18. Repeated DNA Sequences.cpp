// Link - https://leetcode.com/problems/repeated-dna-sequences
// Author - Shumbul Arifa


// method 1: using set
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		set<string>  ans;
		set<string> all;
		vector<string> final;
		if (s.length() <= 10)
			return final;
		string s1;
		s1 = s.substr(0, 10);
		all.insert(s1);
		for (int i = 10; i < s.length(); i++) {
			s1.erase(s1.begin());
			s1 += s[i];
			if (all.find(s1) != all.end()) {
				ans.insert(s1);
			}
			else {
				all.insert(s1);
			}
		}
		for (auto a : ans)
			final.push_back(a);
		return final;
	}
};

// method -2: using hashmap