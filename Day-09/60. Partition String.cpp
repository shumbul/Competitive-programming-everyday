// Link - https://binarysearch.com/problems/Partition-String
// Author - Shumbul Arifa

vector<int> solve(string s) {
	if (s == "")
		return {};
	map<char, pair<int, int>> mp;
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if (mp.find(c) == mp.end()) {
			pair<int, int> k;
			k.first = i;
			k.second = i;
			mp[c] = k;
		}
		else
			mp[c].second = i;
	}
	vector<pair<int, int>> intervals;
	for (auto a : mp) {
		intervals.push_back(a.second);
	}
	sort(intervals.begin(), intervals.end());
	for (auto a : intervals) {
		cout << a.first << " " << a.second << "\n";
	}
	vector<pair<int, int>> it;
	int start, end;
	int prev_start = intervals[0].first, prev_end = intervals[0].second;
	vector<int> ans;
	for (int i = 1; i <= intervals.size(); i++) {
		cout << prev_start << " " << prev_end << "\n";
		if (i == intervals.size()) {
			ans.push_back(prev_end - prev_start + 1);
			break;
		}
		start = intervals[i].first, end = intervals[i].second;
		if (start < prev_end) {
			prev_end = max(prev_end, end);
		}
		else {
			ans.push_back(prev_end - prev_start + 1);
			prev_start = start;
			prev_end = end;
			// if(i+1==intervals.size())
			//     break;
		}
	}

	return ans;
}