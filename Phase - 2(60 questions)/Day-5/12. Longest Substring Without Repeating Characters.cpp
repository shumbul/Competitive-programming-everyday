// Link - https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author - Shumbul Arifa

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		// sliding window
		int start = 0, end = 0, n = s.length(), ans = 0;
		map<char, int> mp;
		while (end < n) {
			if (mp.find(s[end]) != mp.end()) {
				start = max(start, mp[s[end]]);
			}
			ans = max(ans, end - start + 1);
			mp[s[end]] = end + 1;
			end++;
			// for(auto a:mp){
			//     cout<<a.first<<" "<<a.second<<"\n";
			// }
			// cout<<"\n";
		}
		return ans;
	}
};