// Link - https://leetcode.com/problems/reverse-words-in-a-string/submissions/
// Author - Shumbul Arifa

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int start, end, place, n = s.length();
        start = end = place = 0;
        while (end < n) {
            while (s[start] == ' ' && start < n)
                start++;
            end = start;
            start = place;
            // gap bw words
            while (s[end] != ' ' && end < n) {
                s[place++] = s[end++];
            }

            // fixed initial place till final place
            reverse(s.begin() + start, s.begin() + place);

            while (s[end] == ' ' && end < n)
                end++;

            if (place > 0 && place < n && end < n) {
                s[place++] = ' ';
            }
            start = end;
        }
        return s.substr(0, place);
    }
};