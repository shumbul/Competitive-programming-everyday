// Link - https://leetcode.com/contest/biweekly-contest-55/problems/remove-all-occurrences-of-a-substring/
// Author - Shumbul Arifa

class Solution {
public:
	string removeOccurrences(string s, string part) {
		if (part == "" || s == "")
			return s;
		// using stack
		// string subs = "";
		// stack<char> st;
		// for(char c:s){
		//     subs+=c;
		//     st.push(c);
		//     if(subs.size()==part.size()){
		//         if(subs==part){
		//             for(int i=0;i<part.size();i++)
		//                 st.pop();
		//             subs = "";
		//         }
		//         subs.erase(subs.begin, subs.begin()+1);
		//     }
		// }
		// because size limit is too small
		auto i = s.find(part);
		while (i != std::string::npos) {
			s.erase(i, part.length());
			i = s.find(part);
		}
		return s;
	}
};