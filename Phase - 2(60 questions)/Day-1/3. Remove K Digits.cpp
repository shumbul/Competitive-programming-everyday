// Link - https://practice.geeksforgeeks.org/problems/remove-k-digits/1#
// Link - https://leetcode.com/problems/remove-k-digits/discuss/88708/Straightforward-Java-Solution-Using-Stack
// Author - Shumbul Arifa

class Solution {
public:
    string removeKdigits(string S, int K) {
        if (K == S.length())
            return "0";
        if (S == "")
            return "0";
        // stack to remove large numbers
        stack<char> st;
        for (char ch : S) {
            while (K > 0 && !st.empty() && st.top() > ch) {
                K--;
                st.pop();
            }
            st.push(ch);
        }
        if (st.empty())
            return "0";
        // left over elements
        while (K > 0 && !st.empty()) {
            st.pop();
            K--;
        }
        string t = "";
        while (!st.empty()) {
            char ch = st.top();
            st.pop();
            t += ch;
        }
        reverse(t.begin(), t.end());
        // finally, remove leading zeroes
        int i = 0;
        S = "";
        while (t[i] == '0')
            i++;
        S = t.substr(i, t.length());
        if (S == "")
            return "0";
        return S;
    }
};