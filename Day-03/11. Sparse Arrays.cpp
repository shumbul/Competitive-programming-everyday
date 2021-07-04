// Link - https://www.hackerrank.com/challenges/sparse-arrays/problem
// Author - Shumbul Arifa

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
	map<string, int> mp;
	for (auto a : strings)
		mp[a]++;
	vector<int> ans;
	for (auto b : queries)
		if (mp.find(b) != mp.end())
			ans.push_back(mp[b]);
		else {
			ans.push_back(0);
		}
	return ans;
}